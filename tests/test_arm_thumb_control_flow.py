import unittest

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.arch.arm_thumb.control_flow import (
    is_link_register_restore,
    is_pc_return,
    is_return_to_link_register,
)


class ArmThumbControlFlowTests(unittest.TestCase):
    def setUp(self) -> None:
        self.backend = ArmThumbBackend()

    def test_detects_pop_pc_return(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"pop", b"{r4,", b"pc}"]
        )

        self.assertTrue(is_pc_return(instruction))
        self.assertFalse(is_link_register_restore(instruction))

    def test_detects_link_register_restore(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"pop", b"{r4,", b"lr}"]
        )

        self.assertTrue(is_link_register_restore(instruction))
        self.assertFalse(is_pc_return(instruction))

    def test_detects_bx_lr_return(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"bx", b"lr"]
        )

        self.assertTrue(is_return_to_link_register(instruction))

    def test_rejects_indirect_exchange_as_link_register_return(self) -> None:
        instruction = self.backend.decode_legacy_tokens(
            [b"0x8020000", b"2", b"0000", b"bx", b"r0"]
        )

        self.assertFalse(is_return_to_link_register(instruction))


if __name__ == "__main__":
    unittest.main()
