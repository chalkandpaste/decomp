import struct
import unittest

from decomp import convert_c
from decomp import instructions
from decomp.instruction_buffer import InstructionsBuffer, is_probable_address_literal


class InstructionBufferLiteralTests(unittest.TestCase):
    def make_buffer(self, value):
        buf = object.__new__(InstructionsBuffer)
        buf.binary_offset_loc = 0x08020000
        buf.binary = struct.pack("<I", value)
        return buf

    def test_formats_flash_literals_as_addresses(self):
        buf = self.make_buffer(0x08021000)

        self.assertEqual(buf.read_data_at_loc(0x08020000, 4), b"0x8021000")

    def test_formats_sram_and_peripheral_literals_as_addresses(self):
        self.assertTrue(is_probable_address_literal(0x20000010))
        self.assertTrue(is_probable_address_literal(0x40021000))
        self.assertTrue(is_probable_address_literal(0xE000ED88))

    def test_formats_plain_integers_as_decimal(self):
        buf = self.make_buffer(1234)

        self.assertEqual(buf.read_data_at_loc(0x08020000, 4), b"1234")


class ConvertInstructionTests(unittest.TestCase):
    def test_three_operand_left_shift_lowers_as_left_shift(self):
        self.assertEqual(
            convert_c.shift_left([b"lsls", b"r0", b"2"]),
            b"r0 = r0 << 2",
        )

    def test_double_store_accepts_base_address_form(self):
        self.assertEqual(
            convert_c.store_d([b"strd", b"r0", b"r1", b"r2"]),
            b"*( r2) = r0;\n*( r2 + 4) = r1",
        )

    def test_thumb_table_branch_mnemonics_are_bytes(self):
        self.assertIn(b"tbh.w", instructions.tbb)
        self.assertNotIn("tbh.w", instructions.tbb)


if __name__ == "__main__":
    unittest.main()
