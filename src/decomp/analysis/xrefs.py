from __future__ import annotations

from dataclasses import dataclass
from enum import Enum

from decomp.arch.arm_thumb.addresses import normalize_interworking_address
from decomp.arch.arm_thumb.instruction_kinds import (
    is_exchange_transfer,
    is_move_to_register,
    is_register_restore,
)
from decomp.core.cfg import BasicBlock, ControlFlowGraph
from decomp.core.instruction import Instruction


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

    for address in cfg.reachable_order():
        block = cfg.block_at(address)
        references.extend(_collect_block_references(cfg.entry, block))

    return tuple(_dedupe_references(references))


def collect_function_addresses(cfg: ControlFlowGraph) -> list[int]:
    references = collect_call_references(cfg)
    return list({reference.target for reference in references})


def _collect_block_references(entry: int, block: BasicBlock) -> list[CallReference]:
    references = []
    instructions = block.instructions

    for index, instruction in enumerate(instructions):
        if instruction.flow.is_direct_call():
            for target in instruction.flow.target_addresses(normalize_interworking_address):
                references.append(
                    CallReference(
                        source=instruction.address,
                        target=target,
                        kind=CallReferenceKind.DIRECT_CALL,
                    )
                )
        elif is_exchange_transfer(instruction):
            register = instruction.operand_register(0)
            if register != "lr":
                target = _literal_loaded_into_register(instructions, index, register)
                if target is not None:
                    references.append(
                        CallReference(
                            source=instruction.address,
                            target=target,
                            kind=CallReferenceKind.INDIRECT_LITERAL_CALL,
                        )
                    )
        elif instruction.flow.is_unconditional_branch():
            for target in instruction.flow.target_addresses(normalize_interworking_address):
                if block.address == entry and target < entry:
                    references.append(
                        CallReference(
                            source=instruction.address,
                            target=target,
                            kind=CallReferenceKind.LOWER_TAIL_BRANCH,
                        )
                    )
        elif is_register_restore(instruction):
            references.extend(_tail_branches_after_restore(instructions, index))

    return references


def _tail_branches_after_restore(instructions: tuple[Instruction, ...], start_index: int) -> list[CallReference]:
    references = []
    for instruction in instructions[start_index:]:
        if instruction.flow.is_unconditional_branch():
            for target in instruction.flow.target_addresses(normalize_interworking_address):
                references.append(
                    CallReference(
                        source=instruction.address,
                        target=target,
                        kind=CallReferenceKind.RESTORE_TAIL_BRANCH,
                    )
                )
    return references


def _literal_loaded_into_register(
    instructions: tuple[Instruction, ...],
    index: int,
    register: str | None,
) -> int | None:
    if register is None:
        return None
    for previous in reversed(instructions[:index]):
        if is_move_to_register(previous, register):
            target = previous.operand_int(1)
            if target is not None:
                return normalize_interworking_address(target)
    return None


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
