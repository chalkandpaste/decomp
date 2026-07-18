import contextlib
from dataclasses import FrozenInstanceError
import io
import unittest

from decomp.block_graph import generate_block_graph
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.meta_blocks import EndBlock, IfBlock, LinearBlock, MetaBlockGraph, SwitchBlock
from decomp.structure import annotate_graph


class MetaBlockTests(unittest.TestCase):
    def test_annotate_graph_returns_typed_meta_blocks(self) -> None:
        insns = [
            [b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"1"],
            [b"0x8020002", b"2", b"0000", b"bx", b"lr"],
        ]

        with contextlib.redirect_stdout(io.StringIO()):
            graph = generate_block_graph(
                None,
                0x08020000,
                use_cache=False,
                override_input=insns,
            )
            meta_graph = annotate_graph(graph)

        self.assertIsInstance(meta_graph, MetaBlockGraph)
        self.assertIsInstance(meta_graph.block_at(0x08020000), EndBlock)
        self.assertEqual(meta_graph.entry_address, 0x08020000)

    def test_meta_block_graph_names_source_blocks_explicitly(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(),
            predecessors=(),
        )

        graph = MetaBlockGraph(
            source_blocks={block.address: block},
            meta_blocks={},
            entry_address=block.address,
        )

        self.assertIs(graph.source_block_at(block.address), block)
        self.assertEqual(graph.source_blocks, {block.address: block})

    def test_meta_block_graph_can_be_built_from_legacy_graph(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(),
            predecessors=(),
        )
        source_graph = LegacyBlockGraph(
            blocks={block.address: block},
            entry_address=block.address,
        )

        graph = MetaBlockGraph.from_legacy_graph(
            block_graph=source_graph,
            meta_blocks={},
            entry_address=block.address,
        )

        self.assertIs(graph.source_block_at(block.address), block)

    def test_meta_blocks_normalize_sequence_fields_to_tuples(self) -> None:
        if_block = IfBlock(
            address=0x08020000,
            condition_blocks=[0x08020000],
            flags=[True],
            conjunctions=[b" && "],
            true_address=0x08020004,
            false_address=None,
            next_address=None,
        )
        linear_block = LinearBlock(
            address=0x08020004,
            block_addresses=[0x08020004, 0x08020008],
            next_address=None,
        )
        switch_block = SwitchBlock(
            address=0x08020008,
            preface=[0x08020008],
            cases=[0x08020010, 0x08020014],
            next_address=None,
        )

        self.assertEqual(if_block.condition_blocks, (0x08020000,))
        self.assertEqual(if_block.flags, (True,))
        self.assertEqual(if_block.conjunctions, (b" && ",))
        self.assertEqual(linear_block.block_addresses, (0x08020004, 0x08020008))
        self.assertEqual(switch_block.preface, (0x08020008,))
        self.assertEqual(switch_block.cases, (0x08020010, 0x08020014))

    def test_meta_blocks_are_frozen(self) -> None:
        node = EndBlock(
            address=0x08020000,
            block_addresses=[0x08020000],
        )

        with self.assertRaises(FrozenInstanceError):
            node.block_addresses = ()


if __name__ == "__main__":
    unittest.main()
