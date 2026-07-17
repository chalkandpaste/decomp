from __future__ import annotations

import argparse
import contextlib
import hashlib
import io
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

from .block_graph import generate_block_graph
from .function_signatures import collect_functions, skip_functions
from .legacy_adapter import legacy_block_graph_to_cfg


@dataclass(frozen=True)
class BlockFingerprint:
    address: int
    end: int
    instruction_count: int
    outgoing: tuple[int, ...]
    incoming: tuple[int, ...]

    def to_json(self) -> dict[str, object]:
        return {
            "address": hex(self.address),
            "end": hex(self.end),
            "instruction_count": self.instruction_count,
            "outgoing": [hex(address) for address in self.outgoing],
            "incoming": [hex(address) for address in self.incoming],
        }


@dataclass(frozen=True)
class FunctionFingerprint:
    address: int
    status: str
    calls: tuple[int, ...] = ()
    blocks: tuple[BlockFingerprint, ...] = ()
    error: str | None = None

    @property
    def block_count(self) -> int:
        return len(self.blocks)

    @property
    def instruction_count(self) -> int:
        return sum(block.instruction_count for block in self.blocks)

    def to_json(self) -> dict[str, object]:
        return {
            "address": hex(self.address),
            "status": self.status,
            "calls": [hex(address) for address in self.calls],
            "block_count": self.block_count,
            "instruction_count": self.instruction_count,
            "blocks": [block.to_json() for block in self.blocks],
            "error": self.error,
        }


@dataclass(frozen=True)
class ParitySnapshot:
    architecture: str
    base_address: int
    entry_point: int
    binary_sha256: str
    binary_size: int
    max_functions: int | None
    functions: tuple[FunctionFingerprint, ...]
    discovery_order: tuple[int, ...]

    def to_json(self) -> dict[str, object]:
        return {
            "schema_version": 1,
            "architecture": self.architecture,
            "base_address": hex(self.base_address),
            "entry_point": hex(self.entry_point),
            "binary_sha256": self.binary_sha256,
            "binary_size": self.binary_size,
            "max_functions": self.max_functions,
            "discovery_order": [hex(address) for address in self.discovery_order],
            "functions": [function.to_json() for function in self.functions],
        }

    @classmethod
    def from_json(cls, payload: dict[str, object]) -> "ParitySnapshot":
        return cls(
            architecture=str(payload["architecture"]),
            base_address=parse_int(payload["base_address"]),
            entry_point=parse_int(payload["entry_point"]),
            binary_sha256=str(payload["binary_sha256"]),
            binary_size=int(payload["binary_size"]),
            max_functions=payload["max_functions"],
            discovery_order=tuple(parse_int(value) for value in payload["discovery_order"]),
            functions=tuple(
                _function_from_json(function)
                for function in payload["functions"]
            ),
        )


def capture_legacy_snapshot(
    binary_path: str | Path,
    *,
    entry_point: int,
    base_address: int = 0x08020000,
    architecture: str = "arm-thumb",
    max_functions: int | None = 25,
    quiet: bool = True,
) -> ParitySnapshot:
    binary_path = Path(binary_path)
    binary = binary_path.read_bytes()
    sha256 = hashlib.sha256(binary).hexdigest()

    queue = [entry_point]
    discovery_order: list[int] = []
    fingerprints: dict[int, FunctionFingerprint] = {}
    skipped = set(skip_functions)

    while queue and (max_functions is None or len(discovery_order) < max_functions):
        address = queue.pop(0)
        if address in fingerprints:
            continue

        discovery_order.append(address)
        fingerprint = _capture_function(binary, address, quiet=quiet)
        fingerprints[address] = fingerprint

        for call in fingerprint.calls:
            if call in skipped or call in fingerprints or call in queue:
                continue
            if max_functions is not None and len(discovery_order) + len(queue) >= max_functions:
                continue
            queue.append(call)

    return ParitySnapshot(
        architecture=architecture,
        base_address=base_address,
        entry_point=entry_point,
        binary_sha256=sha256,
        binary_size=len(binary),
        max_functions=max_functions,
        discovery_order=tuple(discovery_order),
        functions=tuple(fingerprints[address] for address in discovery_order),
    )


def compare_snapshots(expected: ParitySnapshot, actual: ParitySnapshot) -> list[str]:
    differences: list[str] = []
    for field_name in (
        "architecture",
        "base_address",
        "entry_point",
        "binary_sha256",
        "binary_size",
        "max_functions",
        "discovery_order",
    ):
        if getattr(expected, field_name) != getattr(actual, field_name):
            differences.append(
                f"{field_name}: expected {getattr(expected, field_name)!r}, got {getattr(actual, field_name)!r}"
            )

    expected_functions = {function.address: function for function in expected.functions}
    actual_functions = {function.address: function for function in actual.functions}
    if set(expected_functions) != set(actual_functions):
        differences.append(
            "functions: expected "
            f"{_format_address_set(expected_functions)}, got {_format_address_set(actual_functions)}"
        )

    for address in sorted(set(expected_functions) & set(actual_functions)):
        expected_function = expected_functions[address]
        actual_function = actual_functions[address]
        if expected_function != actual_function:
            differences.extend(_compare_function(expected_function, actual_function))

    return differences


def write_snapshot(snapshot: ParitySnapshot, output_path: str | Path) -> None:
    Path(output_path).write_text(json.dumps(snapshot.to_json(), indent=2, sort_keys=True) + "\n")


def read_snapshot(path: str | Path) -> ParitySnapshot:
    return ParitySnapshot.from_json(json.loads(Path(path).read_text()))


def _capture_function(binary: bytes, address: int, *, quiet: bool) -> FunctionFingerprint:
    try:
        if quiet:
            with contextlib.redirect_stdout(io.StringIO()):
                block_graph = generate_block_graph(binary, address, use_cache=False)
                calls = collect_functions(block_graph)
        else:
            block_graph = generate_block_graph(binary, address, use_cache=False)
            calls = collect_functions(block_graph)
        cfg = legacy_block_graph_to_cfg(block_graph)
    except Exception as exc:
        return FunctionFingerprint(
            address=address,
            status="failed",
            error=f"{exc.__class__.__name__}: {exc}",
        )

    return FunctionFingerprint(
        address=address,
        status="ok",
        calls=tuple(sorted(set(calls))),
        blocks=tuple(
            BlockFingerprint(
                address=block.address,
                end=block.end,
                instruction_count=len(block.instructions),
                outgoing=tuple(edge.target for edge in block.outgoing),
                incoming=tuple(edge.source for edge in block.incoming),
            )
            for block in (cfg.blocks[address] for address in sorted(cfg.blocks))
        ),
    )


def _function_from_json(payload: dict[str, object]) -> FunctionFingerprint:
    return FunctionFingerprint(
        address=parse_int(payload["address"]),
        status=str(payload["status"]),
        calls=tuple(parse_int(value) for value in payload["calls"]),
        blocks=tuple(
            BlockFingerprint(
                address=parse_int(block["address"]),
                end=parse_int(block["end"]),
                instruction_count=int(block["instruction_count"]),
                outgoing=tuple(parse_int(value) for value in block["outgoing"]),
                incoming=tuple(parse_int(value) for value in block["incoming"]),
            )
            for block in payload["blocks"]
        ),
        error=payload["error"],
    )


def _compare_function(expected: FunctionFingerprint, actual: FunctionFingerprint) -> list[str]:
    prefix = hex(expected.address)
    differences = []
    for field_name in ("status", "calls", "blocks", "error"):
        if getattr(expected, field_name) != getattr(actual, field_name):
            differences.append(
                f"{prefix}.{field_name}: expected {getattr(expected, field_name)!r}, "
                f"got {getattr(actual, field_name)!r}"
            )
    return differences


def _format_address_set(values: Iterable[int]) -> str:
    return "[" + ", ".join(hex(value) for value in sorted(values)) + "]"


def parse_int(value: object) -> int:
    if isinstance(value, int):
        return value
    return int(str(value), 0)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="decomp-parity",
        description="capture or check legacy decompiler parity snapshots",
    )
    sub = parser.add_subparsers(dest="command", required=True)

    capture = sub.add_parser("capture", help="capture a parity snapshot from a firmware binary")
    capture.add_argument("binary")
    capture.add_argument("output")
    capture.add_argument("--entry-point", required=True)
    capture.add_argument("--base-address", default="0x08020000")
    capture.add_argument("--architecture", default="arm-thumb")
    capture.add_argument("--max-functions", type=int, default=25)
    capture.add_argument("--verbose", action="store_true")
    capture.set_defaults(func=cmd_capture)

    check = sub.add_parser("check", help="compare a firmware binary against a snapshot")
    check.add_argument("binary")
    check.add_argument("snapshot")
    check.add_argument("--verbose", action="store_true")
    check.set_defaults(func=cmd_check)

    return parser


def cmd_capture(args: argparse.Namespace) -> None:
    snapshot = capture_legacy_snapshot(
        args.binary,
        entry_point=parse_int(args.entry_point),
        base_address=parse_int(args.base_address),
        architecture=args.architecture,
        max_functions=args.max_functions,
        quiet=not args.verbose,
    )
    write_snapshot(snapshot, args.output)
    print(f"captured {len(snapshot.functions)} functions to {args.output}")


def cmd_check(args: argparse.Namespace) -> None:
    expected = read_snapshot(args.snapshot)
    actual = capture_legacy_snapshot(
        args.binary,
        entry_point=expected.entry_point,
        base_address=expected.base_address,
        architecture=expected.architecture,
        max_functions=expected.max_functions,
        quiet=not args.verbose,
    )
    differences = compare_snapshots(expected, actual)
    if differences:
        for difference in differences:
            print(difference)
        raise SystemExit(1)
    print(f"parity ok for {args.snapshot}")


def main(argv: list[str] | None = None) -> None:
    parser = build_parser()
    args = parser.parse_args(argv)
    args.func(args)


if __name__ == "__main__":
    main()
