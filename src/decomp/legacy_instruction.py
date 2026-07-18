from __future__ import annotations

from .legacy_types import LegacyInstruction, LegacyToken


MNEMONIC_INDEX = 3
OPERAND_START_INDEX = 4


def mnemonic(instruction: LegacyInstruction) -> bytes:
    return _bytes_token(instruction[MNEMONIC_INDEX])


def operand(instruction: LegacyInstruction, index: int) -> LegacyToken:
    return instruction[OPERAND_START_INDEX + index]


def operand_bytes(instruction: LegacyInstruction, index: int) -> bytes:
    return _bytes_token(operand(instruction, index))


def operand_int(instruction: LegacyInstruction, index: int, base: int = 0) -> int:
    return int(operand_bytes(instruction, index), base)


def with_appended_token(instruction: LegacyInstruction, token: LegacyToken) -> LegacyInstruction:
    return [*instruction, token]


def _bytes_token(token: LegacyToken) -> bytes:
    if isinstance(token, bytes):
        return token
    raise TypeError(f"expected bytes token, got {type(token).__name__}")
