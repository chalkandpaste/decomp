import unittest

from decomp.core.cfg import BasicBlock, ControlFlowGraph
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
        self.assertEqual(cfg.block_at(0x08020000).outgoing[0].kind, EdgeKind.TRUE_BRANCH)
        self.assertEqual(cfg.block_at(0x08020000).outgoing[1].kind, EdgeKind.FALSE_BRANCH)
        self.assertEqual(cfg.block_at(0x08020000).instructions[1].flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(cfg.block_at(0x08020004).incoming[0].source, 0x08020000)
        self.assertEqual(cfg.block_at(0x08020000).address, 0x08020000)
        self.assertEqual(cfg.successors(0x08020000), (0x08020008, 0x08020004))
        self.assertEqual(cfg.predecessors(0x08020004), (0x08020000,))

    def test_control_flow_graph_reachable_order_matches_graph_api(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            successors=(0x08020002, 0x08020004),
            predecessors=(),
            depth=0,
            instructions=([b"0x8020000", b"2", b"0000", b"beq", b"0x8020004"],),
        )
        left = LegacyBlock(
            address=0x08020002,
            end_address=0x08020004,
            successors=(0x08020006,),
            predecessors=(block.address,),
            depth=0,
            instructions=([b"0x8020002", b"2", b"0000", b"b", b"0x8020006"],),
        )
        right = LegacyBlock(
            address=0x08020004,
            end_address=0x08020006,
            successors=(0x08020006,),
            predecessors=(block.address,),
            depth=0,
            instructions=([b"0x8020004", b"2", b"0000", b"b", b"0x8020006"],),
        )
        exit_block = LegacyBlock(
            address=0x08020006,
            end_address=0x08020008,
            successors=(),
            predecessors=(left.address, right.address),
            depth=0,
            instructions=([b"0x8020006", b"2", b"0000", b"bx", b"lr"],),
        )
        graph = LegacyBlockGraph(
            entry_address=block.address,
            blocks={
                block.address: block,
                left.address: left,
                right.address: right,
                exit_block.address: exit_block,
            },
        )
        cfg = legacy_block_graph_to_cfg(graph)

        self.assertTrue(cfg.has_block(block.address))
        self.assertFalse(cfg.has_block(0x08029999))
        self.assertEqual(
            cfg.reachable_order(direction=True),
            (block.address, right.address, exit_block.address, left.address),
        )
        self.assertEqual(
            cfg.reachable_order(direction=False),
            (block.address, left.address, right.address, exit_block.address),
        )
        self.assertEqual(
            cfg.reachable_order(left.address, stop_address=exit_block.address),
            (left.address,),
        )

    def test_control_flow_graph_replaces_blocks_without_mutating_source_graph(self) -> None:
        original = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
        )
        replacement = BasicBlock(
            address=0x08020000,
            end=0x08020004,
            instructions=(),
        )
        cfg = ControlFlowGraph(
            entry=original.address,
            blocks={original.address: original},
        )

        updated = cfg.with_block(replacement)

        self.assertIs(cfg.block_at(original.address), original)
        self.assertIs(updated.block_at(replacement.address), replacement)
        self.assertIsNot(updated, cfg)

    def test_control_flow_graph_blocks_are_read_only(self) -> None:
        original = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
        )
        replacement = BasicBlock(
            address=0x08020000,
            end=0x08020004,
            instructions=(),
        )
        blocks = {original.address: original}
        cfg = ControlFlowGraph(
            entry=original.address,
            blocks=blocks,
        )

        blocks[original.address] = replacement

        self.assertIs(cfg.block_at(original.address), original)
        with self.assertRaises(TypeError):
            cfg.blocks[original.address] = replacement

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

        instruction = cfg.block_at(0x08020000).instructions[0]
        self.assertEqual(instruction.flow.kind, FlowKind.SWITCH)
        self.assertEqual(instruction.flow.targets, (0x08020010, 0x08020020))


if __name__ == "__main__":
    unittest.main()
