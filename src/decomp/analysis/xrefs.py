from __future__ import annotations

from dataclasses import dataclass
from enum import Enum

from decomp.core.cfg import BasicBlock, ControlFlowGraph
from decomp.core.instruction import Instruction
from decomp.instructions import (
    crs,
    exchange_func_call,
    exchange_return,
    func_call,
    func_end,
    move,
    uncond_block_end,
)


class CallReferenceKind(str, Enum):
    DIRECT_CALL = "direct_call"
    INDIRECT_LITERAL_CALL = "indirect_literal_call"
    LOWER_TAIL_BRANCH = "lower_tail_branch"
    RESTORE_TAIL_BRANCH = "restore_tail_branch"


@dataclass(frozen=True)
class CallReference:
    source: int
    target: int
    kind: CallReferenceKind

    def to_json(self) -> dict[str, str]:
        return {
            "source": hex(self.source),
            "target": hex(self.target),
            "kind": self.kind.value,
        }


def collect_call_references(cfg: ControlFlowGraph) -> tuple[CallReference, ...]:
    references = []

    for address in _reachable_block_order(cfg):
        block = cfg.blocks[address]
        references.extend(_collect_block_references(cfg.entry, block))

    return tuple(_dedupe_references(references))


def collect_function_addresses(cfg: ControlFlowGraph) -> list[int]:
    references = collect_call_references(cfg)
    return list({reference.target for reference in references})


def _collect_block_references(entry: int, block: BasicBlock) -> list[CallReference]:
    references = []
    instructions = block.instructions

    for index, instruction in enumerate(instructions):
        tokens = _legacy_tokens(instruction)
        mnemonic = _mnemonic(instruction)

        if mnemonic in func_call:
            references.append(
                CallReference(
                    source=instruction.address,
                    target=int(tokens[4], 0) & ~1,
                    kind=CallReferenceKind.DIRECT_CALL,
                )
            )
        elif mnemonic in exchange_func_call + exchange_return and len(tokens) >= 5:
            register = crs(tokens[4])
            if register != b"lr":
                target = _literal_loaded_into_register(instructions, index, register)
                if target is not None:
                    references.append(
                        CallReference(
                            source=instruction.address,
                            target=target,
                            kind=CallReferenceKind.INDIRECT_LITERAL_CALL,
                        )
                    )
        elif mnemonic in uncond_block_end:
            target = int(tokens[4], 0) & ~1
            if block.address == entry and target < entry:
                references.append(
                    CallReference(
                        source=instruction.address,
                        target=target,
                        kind=CallReferenceKind.LOWER_TAIL_BRANCH,
                    )
                )
        elif mnemonic in func_end:
            references.extend(_tail_branches_after_restore(instructions, index))

    return references


def _tail_branches_after_restore(instructions: tuple[Instruction, ...], start_index: int) -> list[CallReference]:
    references = []
    for instruction in instructions[start_index:]:
        tokens = _legacy_tokens(instruction)
        if _mnemonic(instruction) in uncond_block_end:
            references.append(
                CallReference(
                    source=instruction.address,
                    target=int(tokens[4], 0) & ~1,
                    kind=CallReferenceKind.RESTORE_TAIL_BRANCH,
                )
            )
    return references


def _literal_loaded_into_register(
    instructions: tuple[Instruction, ...],
    index: int,
    register: bytes,
) -> int | None:
    for previous in reversed(instructions[:index]):
        tokens = _legacy_tokens(previous)
        if _mnemonic(previous) in move and len(tokens) >= 6 and crs(tokens[4]) == register:
            try:
                return int(tokens[5], 0) & ~1
            except ValueError:
                return None
    return None


def _reachable_block_order(cfg: ControlFlowGraph) -> list[int]:
    retrace_nodes = [cfg.entry]
    seen = set()
    order = []

    while retrace_nodes:
        address = retrace_nodes.pop(-1)
        if address in seen or address not in cfg.blocks:
            continue
        seen.add(address)
        order.append(address)

        for edge in cfg.blocks[address].outgoing:
            if edge.target not in seen:
                retrace_nodes.append(edge.target)

    return order


def _dedupe_references(references: list[CallReference]) -> list[CallReference]:
    seen = set()
    deduped = []
    for reference in references:
        key = (reference.source, reference.target, reference.kind)
        if key in seen:
            continue
        seen.add(key)
        deduped.append(reference)
    return deduped


def _legacy_tokens(instruction: Instruction) -> list[object]:
    if instruction.legacy_tokens:
        return list(instruction.legacy_tokens)
    return list(instruction.raw_tokens)


def _mnemonic(instruction: Instruction) -> bytes:
    return instruction.mnemonic.encode("ascii")
