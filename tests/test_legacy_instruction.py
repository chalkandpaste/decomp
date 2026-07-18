import unittest

from decomp.legacy_instruction import (
    instruction_address,
    instruction_size,
    mnemonic,
    next_instruction_address,
    operand_bytes,
    operand_int,
    table_targets,
    with_appended_token,
)


class LegacyInstructionAccessorTests(unittest.TestCase):
    def test_reads_mnemonic_and_operands_from_legacy_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"]

        self.assertEqual(mnemonic(instruction), b"bl")
        self.assertEqual(operand_bytes(instruction, 0), b"0x8030000")
        self.assertEqual(operand_int(instruction, 0), 0x08030000)

    def test_reads_address_and_size_from_legacy_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"b", b"0x8030000"]

        self.assertEqual(instruction_address(instruction), 0x08020000)
        self.assertEqual(instruction_size(instruction), 2)
        self.assertEqual(next_instruction_address(instruction), 0x08020002)

    def test_reads_table_targets_from_final_token(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08030000, 0x08030004]]

        self.assertEqual(table_targets(instruction), [0x08030000, 0x08030004])

    def test_appends_tokens_without_mutating_original_instruction(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"]

        decorated = with_appended_token(instruction, b"void func_0x8030000 ()")

        self.assertEqual(instruction, [b"0x8020000", b"2", b"0000", b"bl", b"0x8030000"])
        self.assertEqual(decorated[-1], b"void func_0x8030000 ()")

    def test_byte_accessors_reject_non_byte_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08030000]]

        with self.assertRaises(TypeError):
            operand_bytes(instruction, 2)

    def test_table_target_accessor_rejects_non_table_tokens(self) -> None:
        instruction = [b"0x8020000", b"2", b"0000", b"b", b"0x8030000"]

        with self.assertRaises(TypeError):
            table_targets(instruction)


if __name__ == "__main__":
    unittest.main()
