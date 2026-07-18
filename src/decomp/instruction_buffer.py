from .arch import ArchitectureBackend, default_architecture_backend
from .arch.arm_thumb.backend import (
    fix_jump_offset,
    is_probable_address_literal,
    normalize_rasm2_output,
    twos_complement,
)
from .core.instruction import Instruction
from .legacy_types import LegacyInstruction


def disassemble_section(section_bytes: bytes, backend: ArchitectureBackend | None = None) -> bytes:
    decoder = backend or default_architecture_backend()
    return decoder.disassemble_section(section_bytes)


class InstructionsBuffer:
    def __init__(
        self,
        binary: bytes,
        entry_point_loc: int = 0x08020004,
        binary_offset_loc: int = 0x08020000,
        n_bytes: int = 4096,
        backend: ArchitectureBackend | None = None,
    ) -> None:
        self.binary = binary
        self.binary_offset_loc = binary_offset_loc
        self.buff_len_bytes = n_bytes
        self.backend = backend or default_architecture_backend()
        self.update_loc(entry_point_loc)

    def read_instructions_binary(self, loc: int) -> list[LegacyInstruction]:
        return self._backend().decode_window_as_legacy_tokens(
            self.binary,
            loc,
            base_address=self.binary_offset_loc,
            size=self.buff_len_bytes,
        )

    def read_typed_instructions_binary(self, loc: int) -> tuple[Instruction, ...]:
        return self._backend().decode_window(
            self.binary,
            loc,
            base_address=self.binary_offset_loc,
            size=self.buff_len_bytes,
        )

    def update_loc(self, new_loc: int) -> None:
        self.curr_offset_loc = new_loc
        self.insns_buff = self.read_instructions_binary(self.curr_offset_loc)
        self.typed_insns_buff = tuple(
            self._backend().decode_legacy_tokens(tokens)
            for tokens in self.insns_buff
        )
        self.insns_buff_index = {int(v[0], 0): i for (i, v) in enumerate(self.insns_buff)}

    def read_data_at_loc(self, loc: int, length: int, signed: bool = False, f: bool = False) -> bytes:
        return self._backend().read_data_at_loc(
            self.binary,
            loc,
            length,
            base_address=self.binary_offset_loc,
            signed=signed,
            float_value=f,
        )

    def read_insns_at_loc(self, loc: int) -> list[LegacyInstruction]:
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.insns_buff[idx:]

    def read_typed_insns_at_loc(self, loc: int) -> tuple[Instruction, ...]:
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.typed_insns_buff[idx:]

    def _backend(self) -> ArchitectureBackend:
        if not hasattr(self, "backend"):
            self.backend = default_architecture_backend()
        return self.backend
