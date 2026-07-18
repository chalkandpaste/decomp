from __future__ import annotations

from decomp.core.instruction import Instruction


def is_pc_return(instruction: Instruction) -> bool:
    return _register_list_contains(instruction, "pc")


def is_link_register_restore(instruction: Instruction) -> bool:
    return _register_list_contains(instruction, "lr")


def is_return_to_link_register(instruction: Instruction) -> bool:
    return instruction.mnemonic == "bx" and instruction.operand_register(0) == "lr"


def _register_list_contains(instruction: Instruction, register: str) -> bool:
    return register in {
        normalized
        for operand in instruction.operands
        if (normalized := _normalize_register_list_item(operand.text)) is not None
    }


def _normalize_register_list_item(text: str) -> str | None:
    normalized = text.strip("{} ,]")
    if normalized in {"sp", "lr", "pc"}:
        return normalized
    if len(normalized) > 1 and normalized[0] in {"r", "s", "d"} and normalized[1:].isdigit():
        return normalized
    return None
