import unittest

from decomp.core import EdgeKind, FlowKind
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.legacy_adapter import legacy_block_graph_to_cfg


class CoreModelAdapterTests(unittest.TestCase):
    def test_converts_legacy_block_graph_to_typed_cfg(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            successors=(0x08020008, 0x08020004),
            predecessors=(),
            depth=0,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
                [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
            ),
        )
        true_block = LegacyBlock(
            address=0x08020008,
            end_address=0x0802000A,
            successors=(),
            predecessors=(0x08020000,),
            depth=0,
            instructions=([b"0x8020008", b"2", b"0000", b"bx", b"lr"],),
        )
        false_block = LegacyBlock(
            address=0x08020004,
            end_address=0x08020006,
            successors=(),
            predecessors=(0x08020000,),
            depth=0,
            instructions=([b"0x8020004", b"2", b"0000", b"bx", b"lr"],),
        )
        graph = LegacyBlockGraph(
            entry_address=block.address,
            blocks={
                block.address: block,
                true_block.address: true_block,
                false_block.address: false_block,
            },
        )

        cfg = legacy_block_graph_to_cfg(graph)

        self.assertEqual(cfg.entry, 0x08020000)
        self.assertEqual(cfg.block_starts(), (0x08020000, 0x08020004, 0x08020008))
        self.assertEqual(cfg.blocks[0x08020000].outgoing[0].kind, EdgeKind.TRUE_BRANCH)
        self.assertEqual(cfg.blocks[0x08020000].outgoing[1].kind, EdgeKind.FALSE_BRANCH)
        self.assertEqual(cfg.blocks[0x08020000].instructions[1].flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(cfg.blocks[0x08020004].incoming[0].source, 0x08020000)
        self.assertEqual(cfg.block_at(0x08020000), cfg.blocks[0x08020000])
        self.assertEqual(cfg.successors(0x08020000), (0x08020008, 0x08020004))
        self.assertEqual(cfg.predecessors(0x08020004), (0x08020000,))

    def test_preserves_legacy_table_branch_targets(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            successors=(0x08020010, 0x08020020),
            predecessors=(),
            depth=0,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08020010, 0x08020020]],
            ),
        )
        graph = LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})

        cfg = legacy_block_graph_to_cfg(graph)

        instruction = cfg.blocks[0x08020000].instructions[0]
        self.assertEqual(instruction.flow.kind, FlowKind.SWITCH)
        self.assertEqual(instruction.flow.targets, (0x08020010, 0x08020020))


if __name__ == "__main__":
    unittest.main()
