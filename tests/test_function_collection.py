import unittest

from decomp.analysis import (
    CallReferenceKind,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    collect_call_references,
)
from decomp.arch.arm_thumb import ArmThumbArchitectureBehavior
from decomp.core.cfg import BasicBlock, ControlFlowGraph
from decomp.core.flow import FlowInfo, FlowKind
from decomp.core.instruction import Instruction
from decomp.function_signatures import collect_functions
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class IdentityAddressBehavior(ArmThumbArchitectureBehavior):
    def normalize_code_address(self, address: int) -> int:
        return address


class CollectFunctionsTests(unittest.TestCase):
    def test_collects_literal_loaded_indirect_calls(self) -> None:
        block = LegacyBlock(
            address=0x080202CC,
            end_address=0x080202D4,
            successors=(),
            predecessors=(),
            instructions=(
                [b"0x80202cc", b"2", b"0948", b"mov", b"r0,", b"0x8034f49"],
                [b"0x80202ce", b"2", b"8047", b"blx", b"r0"],
                [b"0x80202d0", b"2", b"0948", b"mov", b"r0,", b"0x8020189"],
                [b"0x80202d2", b"2", b"0047", b"bx", b"r0"],
            ),
        )
        graph = LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})

        self.assertEqual(
            sorted(collect_functions(graph)),
            [0x08020188, 0x08034F48],
        )

    def test_collects_lower_address_unconditional_tail_branch(self) -> None:
        block = LegacyBlock(
            address=0x08034F48,
            end_address=0x08034F84,
            successors=(0x0803228C,),
            predecessors=(),
            instructions=(
                [b"0x8034f7e", b"2", b"0160", b"str", b"r1,", b"[r0,", b"0]"],
                [b"0x8034f80", b"4", b"fdf784b9", b"b.w", b"0x803228c"],
            ),
        )
        child = LegacyBlock(
            address=0x0803228C,
            end_address=0x0803228C,
            successors=(),
            predecessors=(0x08034F48,),
            instructions=(),
        )
        graph = LegacyBlockGraph(
            entry_address=block.address,
            blocks={
                block.address: block,
                child.address: child,
            },
        )

        self.assertEqual(collect_functions(graph), [0x0803228C])

    def test_typed_xrefs_collect_direct_calls(self) -> None:
        insns = [
            [b"0x8020000", b"4", b"00000000", b"bl", b"0x8030001"],
            [b"0x8020004", b"2", b"0000", b"bx", b"lr"],
        ]
        cfg = build_control_flow_graph(LegacyTokenInstructionSource(insns), 0x08020000)

        references = collect_call_references(cfg)

        self.assertEqual(len(references), 1)
        self.assertEqual(references[0].target, 0x08030000)
        self.assertEqual(references[0].kind, CallReferenceKind.DIRECT_CALL)

    def test_typed_xrefs_accept_architecture_behavior(self) -> None:
        instruction = Instruction(
            address=0x08020000,
            size=4,
            data=b"\x00\x00\x00\x00",
            mnemonic="bl",
            flow=FlowInfo(kind=FlowKind.CALL, targets=(0x08030001,)),
        )
        block = BasicBlock(
            address=instruction.address,
            end=instruction.address + instruction.size,
            instructions=(instruction,),
        )
        cfg = ControlFlowGraph(entry=block.address, blocks={block.address: block})

        references = collect_call_references(cfg, behavior=IdentityAddressBehavior())

        self.assertEqual(references[0].target, 0x08030001)

    def test_typed_xrefs_collect_indirect_literal_calls(self) -> None:
        insns = [
            [b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"0x8034f49"],
            [b"0x8020002", b"2", b"0000", b"blx", b"r0"],
            [b"0x8020004", b"2", b"0000", b"bx", b"lr"],
        ]
        cfg = build_control_flow_graph(LegacyTokenInstructionSource(insns), 0x08020000)

        references = collect_call_references(cfg)

        self.assertEqual(len(references), 1)
        self.assertEqual(references[0].target, 0x08034F48)
        self.assertEqual(references[0].kind, CallReferenceKind.INDIRECT_LITERAL_CALL)

    def test_typed_xrefs_collect_lower_tail_branch_from_entry_block(self) -> None:
        insns = [
            [b"0x8034f80", b"4", b"00000000", b"b.w", b"0x803228c"],
            [b"0x803228c", b"2", b"0000", b"bx", b"lr"],
        ]
        cfg = build_control_flow_graph(LegacyTokenInstructionSource(insns), 0x08034F80)

        references = collect_call_references(cfg)

        self.assertEqual(len(references), 1)
        self.assertEqual(references[0].target, 0x0803228C)
        self.assertEqual(references[0].kind, CallReferenceKind.LOWER_TAIL_BRANCH)

    def test_typed_xrefs_collect_tail_branch_after_restore(self) -> None:
        block = LegacyBlock(
            address=0x08034F48,
            end_address=0x08034F4E,
            successors=(),
            predecessors=(),
            instructions=(
                [b"0x8034f48", b"2", b"0000", b"pop", b"{r4,", b"lr}"],
                [b"0x8034f4a", b"4", b"00000000", b"b.w", b"0x803228c"],
            ),
        )
        graph = LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})

        self.assertEqual(collect_functions(graph), [0x0803228C])


if __name__ == "__main__":
    unittest.main()
