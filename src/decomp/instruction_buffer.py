from .arch.arm_thumb.backend import (
    ArmThumbBackend,
    fix_jump_offset,
    is_probable_address_literal,
    normalize_rasm2_output,
    twos_complement,
)


def disassemble_section(section_bytes):
    return ArmThumbBackend().disassemble_section(section_bytes)


class InstructionsBuffer:
    def __init__(self, binary, entry_point_loc=0x08020004, binary_offset_loc=0x08020000, n_bytes=4096):
        self.binary = binary
        self.binary_offset_loc = binary_offset_loc
        self.buff_len_bytes = n_bytes
        self.backend = ArmThumbBackend()
        self.update_loc(entry_point_loc)

    def read_instructions_binary(self, loc):
        return self._backend().decode_window_as_legacy_tokens(
            self.binary,
            loc,
            base_address=self.binary_offset_loc,
            size=self.buff_len_bytes,
        )

    def read_typed_instructions_binary(self, loc):
        return self._backend().decode_window(
            self.binary,
            loc,
            base_address=self.binary_offset_loc,
            size=self.buff_len_bytes,
        )

    def update_loc(self, new_loc):
        self.curr_offset_loc = new_loc
        self.insns_buff = self.read_instructions_binary(self.curr_offset_loc)
        self.typed_insns_buff = tuple(
            self._backend().decode_legacy_tokens(tokens)
            for tokens in self.insns_buff
        )
        self.insns_buff_index = {int(v[0], 0): i for (i, v) in enumerate(self.insns_buff)}

    def read_data_at_loc(self, loc, length, signed=False, f=False):
        return self._backend().read_data_at_loc(
            self.binary,
            loc,
            length,
            base_address=self.binary_offset_loc,
            signed=signed,
            float_value=f,
        )

    def read_insns_at_loc(self, loc):
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.insns_buff[idx:]

    def read_typed_insns_at_loc(self, loc):
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.typed_insns_buff[idx:]

    def _backend(self):
        if not hasattr(self, "backend"):
            self.backend = ArmThumbBackend()
        return self.backend
