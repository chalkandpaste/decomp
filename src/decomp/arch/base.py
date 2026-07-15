from __future__ import annotations

from dataclasses import dataclass
from typing import Protocol

from decomp.core.flow import FlowInfo
from decomp.core.image import FirmwareImage
from decomp.core.instruction import Instruction


@dataclass(frozen=True)
class DisassemblerConfig:
    tool: str
    architecture: str
    bits: int
    extra_args: tuple[str, ...] = ()


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
