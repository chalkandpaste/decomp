import unittest

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.arch.arm_thumb.addresses import normalize_interworking_address
from decomp.arch.arm_thumb.control_flow import (
    is_link_register_restore,
    is_pc_return,
    is_return_to_link_register,
)
from decomp.arch.arm_thumb.instruction_kinds import (
    is_block_terminator,
    is_exchange_transfer,
    is_function_end_candidate,
    is_move_to_register,
    is_register_restore,
    is_stack_pop,
    is_unconditional_branch,
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

    def test_normalizes_interworking_addresses(self) -> None:
        self.assertEqual(normalize_interworking_address(0x08030001), 0x08030000)
        self.assertEqual(normalize_interworking_address(0x08030000), 0x08030000)

    def test_classifies_exchange_transfer_instructions(self) -> None:
        blx = self.backend.decode_legacy_tokens([b"0x8020000", b"2", b"0000", b"blx", b"r0"])
        bx = self.backend.decode_legacy_tokens([b"0x8020002", b"2", b"0000", b"bx", b"r0"])

        self.assertTrue(is_exchange_transfer(blx))
        self.assertTrue(is_exchange_transfer(bx))

    def test_classifies_register_restore_instructions(self) -> None:
        restore = self.backend.decode_legacy_tokens([b"0x8020000", b"2", b"0000", b"pop", b"{r4,", b"lr}"])

        self.assertTrue(is_register_restore(restore))

    def test_classifies_cfg_block_boundary_instructions(self) -> None:
        beq = self.backend.decode_legacy_tokens([b"0x8020000", b"2", b"0000", b"beq", b"0x8020008"])
        branch = self.backend.decode_legacy_tokens([b"0x8020002", b"2", b"0000", b"b", b"0x8020010"])

        self.assertTrue(is_block_terminator(beq))
        self.assertTrue(is_block_terminator(branch))
        self.assertTrue(is_unconditional_branch(branch))
        self.assertFalse(is_unconditional_branch(beq))

    def test_classifies_function_end_candidates(self) -> None:
        pop = self.backend.decode_legacy_tokens([b"0x8020000", b"2", b"0000", b"pop", b"{r4,", b"lr}"])
        bx = self.backend.decode_legacy_tokens([b"0x8020002", b"2", b"0000", b"bx", b"lr"])

        self.assertTrue(is_function_end_candidate(pop))
        self.assertTrue(is_function_end_candidate(bx))
        self.assertTrue(is_stack_pop(pop))
        self.assertFalse(is_stack_pop(bx))

    def test_classifies_register_move_instructions(self) -> None:
        move = self.backend.decode_legacy_tokens([b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"0x8034f49"])

        self.assertTrue(is_move_to_register(move, "r0"))
        self.assertFalse(is_move_to_register(move, "r1"))


if __name__ == "__main__":
    unittest.main()
