from __future__ import annotations

from dataclasses import dataclass

from decomp.arch.arm_thumb.addresses import normalize_interworking_address
from decomp.arch.arm_thumb.control_flow import (
    is_link_register_restore,
    is_pc_return,
    is_return_to_link_register,
)
from decomp.arch.arm_thumb.instruction_kinds import (
    is_block_terminator,
    is_exchange_transfer,
    is_function_end_candidate,
    is_move_to_register,
    is_register_restore,
    is_stack_pop,
    is_unconditional_branch,
)
from decomp.arch.arm_thumb.register_effects import register_effect
from decomp.arch.base import RegisterEffect
from decomp.core.address import Address
from decomp.core.instruction import Instruction


@dataclass(frozen=True)
class ArmThumbArchitectureBehavior:
    def normalize_code_address(self, address: Address) -> Address:
        return normalize_interworking_address(address)

    def is_block_terminator(self, instruction: Instruction) -> bool:
        return is_block_terminator(instruction)

    def is_function_end_candidate(self, instruction: Instruction) -> bool:
        return is_function_end_candidate(instruction)

    def returns_via_program_counter(self, instruction: Instruction) -> bool:
        return is_pc_return(instruction)

    def restores_link_register(self, instruction: Instruction) -> bool:
        return is_link_register_restore(instruction)

    def returns_to_link_register(self, instruction: Instruction) -> bool:
        return is_return_to_link_register(instruction)

    def is_stack_pop(self, instruction: Instruction) -> bool:
        return is_stack_pop(instruction)

    def is_unconditional_branch(self, instruction: Instruction) -> bool:
        return is_unconditional_branch(instruction)

    def is_exchange_transfer(self, instruction: Instruction) -> bool:
        return is_exchange_transfer(instruction)

    def is_register_restore(self, instruction: Instruction) -> bool:
        return is_register_restore(instruction)

    def is_move_to_register(self, instruction: Instruction, register: str) -> bool:
        return is_move_to_register(instruction, register)

    def register_effect(self, instruction: Instruction) -> RegisterEffect | None:
        return register_effect(instruction)
