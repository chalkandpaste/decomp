from __future__ import annotations

from .legacy_types import LegacyInstruction, LegacyToken


ADDRESS_INDEX = 0
SIZE_INDEX = 1
MNEMONIC_INDEX = 3
OPERAND_START_INDEX = 4


def mnemonic(instruction: LegacyInstruction) -> bytes:
    return _bytes_token(instruction[MNEMONIC_INDEX])


def instruction_address(instruction: LegacyInstruction) -> int:
    return int(_bytes_token(instruction[ADDRESS_INDEX]), 0)


def instruction_size(instruction: LegacyInstruction) -> int:
    return int(_bytes_token(instruction[SIZE_INDEX]), 0)


def next_instruction_address(instruction: LegacyInstruction) -> int:
    return instruction_address(instruction) + instruction_size(instruction)


def operand(instruction: LegacyInstruction, index: int) -> LegacyToken:
    return instruction[OPERAND_START_INDEX + index]


def operand_bytes(instruction: LegacyInstruction, index: int) -> bytes:
    return _bytes_token(operand(instruction, index))


def operand_int(instruction: LegacyInstruction, index: int, base: int = 0) -> int:
    return int(operand_bytes(instruction, index), base)


def with_appended_token(instruction: LegacyInstruction, token: LegacyToken) -> LegacyInstruction:
    return [*instruction, token]


def table_targets(instruction: LegacyInstruction) -> list[int]:
    token = instruction[-1]
    if not isinstance(token, list):
        raise TypeError(f"expected table target list, got {type(token).__name__}")
    if not all(isinstance(target, int) for target in token):
        raise TypeError("expected table target list to contain only ints")
    return list(token)


def _bytes_token(token: LegacyToken) -> bytes:
    if isinstance(token, bytes):
        return token
    raise TypeError(f"expected bytes token, got {type(token).__name__}")
