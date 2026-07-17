import unittest

from decomp.core import EdgeKind, FlowKind
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.legacy_adapter import legacy_block_graph_to_cfg


class CoreModelAdapterTests(unittest.TestCase):
    def test_converts_legacy_block_graph_to_typed_cfg(self) -> None:
        block = LegacyBlock(
            loc=0x08020000,
            end_loc=0x08020004,
            children=[0x08020008, 0x08020004],
            parents=[],
            depth=0,
            block=[
                [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
                [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
            ],
        )
        true_block = LegacyBlock(
            loc=0x08020008,
            end_loc=0x0802000A,
            children=[],
            parents=[0x08020000],
            depth=0,
            block=[[b"0x8020008", b"2", b"0000", b"bx", b"lr"]],
        )
        false_block = LegacyBlock(
            loc=0x08020004,
            end_loc=0x08020006,
            children=[],
            parents=[0x08020000],
            depth=0,
            block=[[b"0x8020004", b"2", b"0000", b"bx", b"lr"]],
        )
        graph = LegacyBlockGraph(
            start_block=block,
            index={
                block["loc"]: block,
                true_block["loc"]: true_block,
                false_block["loc"]: false_block,
            },
        )

        cfg = legacy_block_graph_to_cfg(graph)

        self.assertEqual(cfg.entry, 0x08020000)
        self.assertEqual(cfg.block_starts(), (0x08020000, 0x08020004, 0x08020008))
        self.assertEqual(cfg.blocks[0x08020000].outgoing[0].kind, EdgeKind.TRUE_BRANCH)
        self.assertEqual(cfg.blocks[0x08020000].outgoing[1].kind, EdgeKind.FALSE_BRANCH)
        self.assertEqual(cfg.blocks[0x08020000].instructions[1].flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(cfg.blocks[0x08020004].incoming[0].source, 0x08020000)

    def test_preserves_legacy_table_branch_targets(self) -> None:
        block = LegacyBlock(
            loc=0x08020000,
            end_loc=0x08020002,
            children=[0x08020010, 0x08020020],
            parents=[],
            depth=0,
            block=[
                [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08020010, 0x08020020]],
            ],
        )
        graph = LegacyBlockGraph(start_block=block, index={block["loc"]: block})

        cfg = legacy_block_graph_to_cfg(graph)

        instruction = cfg.blocks[0x08020000].instructions[0]
        self.assertEqual(instruction.flow.kind, FlowKind.SWITCH)
        self.assertEqual(instruction.flow.targets, (0x08020010, 0x08020020))


if __name__ == "__main__":
    unittest.main()
