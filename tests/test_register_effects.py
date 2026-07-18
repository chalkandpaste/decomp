import unittest

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.arch.arm_thumb.register_effects import RegisterEffect, register_effect


class RegisterEffectTests(unittest.TestCase):
    def setUp(self) -> None:
        self.backend = ArmThumbBackend()

    def test_move_writes_destination_and_reads_source_register(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"r1"]
        )

        self.assertEqual(register_effect(instruction), RegisterEffect(reads=(b"r1",), writes=(b"r0",)))

    def test_store_reads_value_and_base_registers(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"str", b"r1,", b"[r0,", b"0]"]
        )

        self.assertEqual(register_effect(instruction), RegisterEffect(reads=(b"r1", b"r0")))

    def test_load_double_writes_pair_and_reads_address_register(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"4", b"00000000", b"ldrd", b"r0,", b"r1,", b"[r2]"]
        )

        self.assertEqual(register_effect(instruction), RegisterEffect(reads=(b"r2",), writes=(b"r1", b"r0")))

    def test_branch_return_has_no_register_transfer_effect(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"bx", b"lr"]
        )

        self.assertIsNone(register_effect(instruction))


if __name__ == "__main__":
    unittest.main()
