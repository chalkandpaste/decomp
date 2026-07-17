import unittest

from decomp.analysis import (
    CallReferenceKind,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    collect_call_references,
)
from decomp.function_signatures import collect_functions
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class CollectFunctionsTests(unittest.TestCase):
    def test_collects_literal_loaded_indirect_calls(self) -> None:
        block = LegacyBlock(
            loc=0x080202CC,
            end_loc=0x080202D4,
            children=[],
            parents=[],
            block=[
                [b"0x80202cc", b"2", b"0948", b"mov", b"r0,", b"0x8034f49"],
                [b"0x80202ce", b"2", b"8047", b"blx", b"r0"],
                [b"0x80202d0", b"2", b"0948", b"mov", b"r0,", b"0x8020189"],
                [b"0x80202d2", b"2", b"0047", b"bx", b"r0"],
            ],
        )
        graph = LegacyBlockGraph(start_block=block, index={block["loc"]: block})

        self.assertEqual(
            sorted(collect_functions(graph)),
            [0x08020188, 0x08034F48],
        )

    def test_collects_lower_address_unconditional_tail_branch(self) -> None:
        block = LegacyBlock(
            loc=0x08034F48,
            end_loc=0x08034F84,
            children=[0x0803228C],
            parents=[],
            block=[
                [b"0x8034f7e", b"2", b"0160", b"str", b"r1,", b"[r0,", b"0]"],
                [b"0x8034f80", b"4", b"fdf784b9", b"b.w", b"0x803228c"],
            ],
        )
        child = LegacyBlock(loc=0x0803228C, end_loc=0x0803228C, children=[], parents=[0x08034F48], block=[])
        graph = LegacyBlockGraph(
            start_block=block,
            index={
                block["loc"]: block,
                child["loc"]: child,
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
            loc=0x08034F48,
            end_loc=0x08034F4E,
            children=[],
            parents=[],
            block=[
                [b"0x8034f48", b"2", b"0000", b"pop", b"{r4,", b"lr}"],
                [b"0x8034f4a", b"4", b"00000000", b"b.w", b"0x803228c"],
            ],
        )
        graph = LegacyBlockGraph(start_block=block, index={block["loc"]: block})

        self.assertEqual(collect_functions(graph), [0x0803228C])


if __name__ == "__main__":
    unittest.main()
