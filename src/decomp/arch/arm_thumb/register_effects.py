from __future__ import annotations

from dataclasses import dataclass

from decomp.core.instruction import Instruction
from decomp.instructions import (
    add,
    base_arith,
    bits,
    cast,
    compares,
    cond_block_end,
    cond_block_end_zero,
    coprocessor,
    div,
    exchange_func_call,
    exchange_return,
    func_call,
    func_end,
    func_start,
    load,
    load_d,
    move,
    mul,
    nop,
    smull,
    store,
    store_d,
    sxtab,
    tbb,
    tst,
    uncond_block_end,
    vdup,
    vmlas,
    vpop,
)


@dataclass(frozen=True)
class RegisterEffect:
    reads: tuple[bytes, ...] = ()
    writes: tuple[bytes, ...] = ()


class UnsupportedRegisterEffect(ValueError):
    pass


def register_effect(instruction: Instruction) -> RegisterEffect | None:
    mnemonic = instruction.mnemonic.encode("ascii")
    operand_count = len(instruction.operands)

    if mnemonic in base_arith + mul + div + vmlas + cast + bits + move + load:
        return _arithmetic_like_effect(instruction, mnemonic, operand_count)
    if mnemonic in smull:
        return RegisterEffect(reads=_registers(instruction, 2, 3), writes=_registers(instruction, 1, 0))
    if mnemonic in store:
        if operand_count == 2:
            return RegisterEffect(reads=_registers(instruction, 0, 1))
        if operand_count in {3, 5}:
            return RegisterEffect(reads=_registers(instruction, 0, 1, 2))
    if mnemonic in store_d:
        if operand_count == 3:
            return RegisterEffect(reads=_registers(instruction, 1, 0, 2))
        if operand_count == 4:
            return RegisterEffect(reads=_registers(instruction, 1, 0, 2, 3))
    if mnemonic in load_d:
        if operand_count == 3:
            return RegisterEffect(reads=_registers(instruction, 2), writes=_registers(instruction, 1, 0))
        if operand_count == 4:
            return RegisterEffect(reads=_registers(instruction, 2, 3), writes=_registers(instruction, 1, 0))
    if mnemonic in sxtab:
        if operand_count in {3, 5}:
            return RegisterEffect(reads=_registers(instruction, 1, 2), writes=_registers(instruction, 0))
    if mnemonic in compares + tst:
        if operand_count in {2, 4}:
            return RegisterEffect(reads=_registers(instruction, 0, 1))
    if mnemonic in cond_block_end_zero:
        if operand_count == 2:
            return RegisterEffect(reads=_registers(instruction, 0))
    if mnemonic in _IGNORED_MNEMONICS:
        return None

    raise UnsupportedRegisterEffect(f"unsupported register effect for {instruction.to_json()!r}")


def _arithmetic_like_effect(instruction: Instruction, mnemonic: bytes, operand_count: int) -> RegisterEffect:
    if operand_count == 2:
        return RegisterEffect(reads=_registers(instruction, 1), writes=_registers(instruction, 0))
    if operand_count in {3, 5} or (mnemonic in add and operand_count == 7):
        return RegisterEffect(reads=_registers(instruction, 1, 2), writes=_registers(instruction, 0))
    if mnemonic in move and operand_count == 4:
        return RegisterEffect(reads=_registers(instruction, 1), writes=_registers(instruction, 0))
    if mnemonic in vmlas + bits and operand_count == 4:
        return RegisterEffect(reads=_registers(instruction, 1, 2, 3), writes=_registers(instruction, 0))

    raise UnsupportedRegisterEffect(f"unsupported register effect for {instruction.to_json()!r}")


def _registers(instruction: Instruction, *indexes: int) -> tuple[bytes, ...]:
    registers = []
    for index in indexes:
        register = instruction.operand_register(index)
        if register is not None:
            registers.append(register.encode("ascii"))
    return tuple(registers)


_IGNORED_MNEMONICS = (
    func_start +
    func_end +
    func_call +
    uncond_block_end +
    vpop +
    cond_block_end +
    tbb +
    nop +
    exchange_return +
    exchange_func_call +
    vdup +
    coprocessor
)
