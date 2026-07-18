import unittest

from decomp.legacy_instruction import mnemonic, operand_bytes, operand_int, with_appended_token


class LegacyInstructionAccessorTests(unittest.TestCase):
    def test_reads_mnemonic_and_operands_from_legacy_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"]

        self.assertEqual(mnemonic(instruction), b"bl")
        self.assertEqual(operand_bytes(instruction, 0), b"0x8030000")
        self.assertEqual(operand_int(instruction, 0), 0x08030000)

    def test_appends_tokens_without_mutating_original_instruction(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"]

        decorated = with_appended_token(instruction, b"void func_0x8030000 ()")

        self.assertEqual(instruction, [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"])
        self.assertEqual(decorated[-1], b"void func_0x8030000 ()")

    def test_byte_accessors_reject_non_byte_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08030000]]

        with self.assertRaises(TypeError):
            operand_bytes(instruction, 2)


if __name__ == "__main__":
    unittest.main()
