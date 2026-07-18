from __future__ import annotations

from decomp.core.instruction import Instruction
from decomp.instructions import exchange_func_call, exchange_return, func_end, move


def is_exchange_transfer(instruction: Instruction) -> bool:
    return _mnemonic(instruction) in exchange_func_call + exchange_return


def is_register_restore(instruction: Instruction) -> bool:
    return _mnemonic(instruction) in func_end


def is_move_to_register(instruction: Instruction, register: str) -> bool:
    return _mnemonic(instruction) in move and instruction.operand_register(0) == register


def _mnemonic(instruction: Instruction) -> bytes:
    return instruction.mnemonic.encode("ascii")
