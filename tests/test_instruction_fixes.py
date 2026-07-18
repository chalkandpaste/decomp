import struct
import unittest

from decomp import convert_c
from decomp import instructions
from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.arch.arm_thumb.backend import is_probable_address_literal
from decomp.core import FlowKind
from decomp.instruction_buffer import InstructionsBuffer, disassemble_section


class FixtureBackend(ArmThumbBackend):
    def disassemble_section(self, _section_bytes: bytes) -> bytes:
        return b"fixture disassembly"

    def decode_window_as_legacy_tokens(
        self,
        _binary: bytes,
        _address: int,
        *,
        base_address: int = 0x08020000,
        size: int = 4096,
    ) -> list[list[object]]:
        return [[b"0x8020000", b"2", b"0000", b"bx", b"lr"]]


class InstructionBufferLiteralTests(unittest.TestCase):
    def make_buffer(self, value: int) -> InstructionsBuffer:
        buf = object.__new__(InstructionsBuffer)
        buf.binary_offset_loc = 0x08020000
        buf.binary = struct.pack("<I", value)
        return buf

    def test_formats_flash_literals_as_addresses(self) -> None:
        buf = self.make_buffer(0x08021000)

        self.assertEqual(buf.read_data_at_loc(0x08020000, 4), b"0x8021000")

    def test_formats_sram_and_peripheral_literals_as_addresses(self) -> None:
        self.assertTrue(is_probable_address_literal(0x20000010))
        self.assertTrue(is_probable_address_literal(0x40021000))
        self.assertTrue(is_probable_address_literal(0xE000ED88))

    def test_formats_plain_integers_as_decimal(self) -> None:
        buf = self.make_buffer(1234)

        self.assertEqual(buf.read_data_at_loc(0x08020000, 4), b"1234")

    def test_wrapper_exposes_typed_instruction_buffer(self) -> None:
        buf = object.__new__(InstructionsBuffer)
        buf.backend = ArmThumbBackend()
        buf.insns_buff = [
            [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
            [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
        ]
        buf.typed_insns_buff = tuple(buf.backend.decode_legacy_tokens(tokens) for tokens in buf.insns_buff)
        buf.insns_buff_index = {0x08020000: 0, 0x08020002: 1}

        typed = buf.read_typed_insns_at_loc(0x08020002)

        self.assertEqual(typed[0].mnemonic, "beq")
        self.assertEqual(typed[0].flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(typed[0].flow.targets, (0x08020008,))

    def test_disassemble_section_accepts_architecture_backend(self) -> None:
        self.assertEqual(disassemble_section(b"", backend=FixtureBackend()), b"fixture disassembly")

    def test_constructor_accepts_architecture_backend(self) -> None:
        buf = InstructionsBuffer(b"", entry_point_loc=0x08020000, backend=FixtureBackend())

        self.assertEqual(buf.read_typed_insns_at_loc(0x08020000)[0].mnemonic, "bx")


class ArmThumbBackendDecodeTests(unittest.TestCase):
    def test_backend_reads_literals_with_current_address_formatting(self) -> None:
        backend = ArmThumbBackend()
        binary = struct.pack("<I", 0x08021000)

        self.assertEqual(
            backend.read_data_at_loc(binary, 0x08020000, 4, base_address=0x08020000),
            b"0x8021000",
        )

    def test_backend_decodes_legacy_tokens_to_typed_instruction(self) -> None:
        backend = ArmThumbBackend()

        instruction = backend.decode_legacy_tokens(
            [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"]
        )

        self.assertEqual(instruction.address, 0x08020002)
        self.assertEqual(instruction.mnemonic, "beq")
        self.assertEqual(instruction.flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(instruction.flow.targets, (0x08020008,))

    def test_typed_instruction_exposes_operand_helpers(self) -> None:
        backend = ArmThumbBackend()

        instruction = backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"0x8034f49"]
        )

        self.assertEqual(instruction.operand_register(0), "r0")
        self.assertEqual(instruction.operand_int(1), 0x08034F49)
        self.assertIsNone(instruction.operand_at(2))

    def test_backend_normalizes_branch_targets_against_decode_window(self) -> None:
        class FakeBackend(ArmThumbBackend):
            def disassemble_section(self, _section_bytes: bytes) -> bytes:
                return b"0x2 2 0000 beq 0x8\n"

        backend = FakeBackend()

        tokens = backend.decode_window_as_legacy_tokens(
            b"\x00" * 32,
            0x08020000,
            base_address=0x08020000,
            size=32,
        )

        self.assertEqual(tokens[0], [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"])


class ConvertInstructionTests(unittest.TestCase):
    def test_three_operand_left_shift_lowers_as_left_shift(self) -> None:
        self.assertEqual(
            convert_c.shift_left([b"lsls", b"r0", b"2"]),
            b"r0 = r0 << 2",
        )

    def test_double_store_accepts_base_address_form(self) -> None:
        self.assertEqual(
            convert_c.store_d([b"strd", b"r0", b"r1", b"r2"]),
            b"*( r2) = r0;\n*( r2 + 4) = r1",
        )

    def test_thumb_table_branch_mnemonics_are_bytes(self) -> None:
        self.assertIn(b"tbh.w", instructions.tbb)
        self.assertNotIn("tbh.w", instructions.tbb)


if __name__ == "__main__":
    unittest.main()
