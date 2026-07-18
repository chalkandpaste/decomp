from __future__ import annotations

from dataclasses import dataclass
from typing import Protocol

from decomp.core.address import Address
from decomp.core.flow import FlowInfo
from decomp.core.image import FirmwareImage
from decomp.core.instruction import Instruction


@dataclass(frozen=True)
class DisassemblerConfig:
    tool: str
    architecture: str
    bits: int
    extra_args: tuple[str, ...] = ()


@dataclass(frozen=True)
class RegisterEffect:
    reads: tuple[bytes, ...] = ()
    writes: tuple[bytes, ...] = ()


class ArchitectureBackend(Protocol):
    id: str
    display_name: str
    disassembler: DisassemblerConfig

    def decode_window(
        self,
        binary: bytes,
        address: int,
        *,
        base_address: int = 0x08020000,
        size: int = 4096,
    ) -> tuple[Instruction, ...]:
        """Decode a window of firmware bytes into typed instructions."""

    def decode_legacy_tokens(self, tokens: list[object]) -> Instruction:
        """Convert current legacy token lists into typed instructions."""

    def classify_flow(self, instruction: Instruction) -> FlowInfo:
        """Return architecture-specific control-flow information."""

    def read_data_at_loc(
        self,
        binary: bytes,
        address: int,
        length: int,
        *,
        base_address: int = 0x08020000,
        signed: bool = False,
        float_value: bool = False,
    ) -> bytes:
        """Read and format an architecture-profile literal value."""

    def is_probable_code_address(self, image: FirmwareImage, value: int) -> bool:
        """Return whether a literal can plausibly reference code for this target."""


class ArchitectureBehavior(Protocol):
    def normalize_code_address(self, address: Address) -> Address:
        """Normalize an architecture-specific code pointer into an instruction address."""

    def is_block_terminator(self, instruction: Instruction) -> bool:
        """Return whether an instruction ends a basic block."""

    def is_function_end_candidate(self, instruction: Instruction) -> bool:
        """Return whether an instruction may end the current function."""

    def returns_via_program_counter(self, instruction: Instruction) -> bool:
        """Return whether an instruction restores or branches directly to PC."""

    def restores_link_register(self, instruction: Instruction) -> bool:
        """Return whether an instruction restores LR for a following tail branch."""

    def returns_to_link_register(self, instruction: Instruction) -> bool:
        """Return whether an instruction returns directly through LR."""

    def is_stack_pop(self, instruction: Instruction) -> bool:
        """Return whether an instruction is the stack-pop form with special return handling."""

    def is_unconditional_branch(self, instruction: Instruction) -> bool:
        """Return whether an instruction is an unconditional branch."""

    def is_exchange_transfer(self, instruction: Instruction) -> bool:
        """Return whether an instruction transfers control through a register."""

    def is_register_restore(self, instruction: Instruction) -> bool:
        """Return whether an instruction restores registers from the stack."""

    def is_move_to_register(self, instruction: Instruction, register: str) -> bool:
        """Return whether an instruction loads/moves an immediate into a target register."""

    def register_effect(self, instruction: Instruction) -> RegisterEffect | None:
        """Return register reads/writes for signature and liveness analysis."""
