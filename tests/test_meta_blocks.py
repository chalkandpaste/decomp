import contextlib
from dataclasses import FrozenInstanceError
import io
import unittest

from decomp.block_graph import generate_block_graph
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.meta_blocks import EndBlock, IfBlock, LinearBlock, MetaBlockGraph, SwitchBlock
from decomp.structure import annotate_graph, simplify_if


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

    def test_meta_block_graph_storage_is_read_only(self) -> None:
        original_source = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(),
            predecessors=(),
        )
        replacement_source = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            instructions=(),
            successors=(),
            predecessors=(),
        )
        original_meta = EndBlock(
            address=0x08020000,
            block_addresses=[0x08020000],
        )
        replacement_meta = EndBlock(
            address=0x08020000,
            block_addresses=[0x08020004],
        )
        source_blocks = {original_source.address: original_source}
        meta_blocks = {original_meta.address: original_meta}
        graph = MetaBlockGraph(
            source_blocks=source_blocks,
            meta_blocks=meta_blocks,
            entry_address=original_source.address,
        )

        source_blocks[original_source.address] = replacement_source
        meta_blocks[original_meta.address] = replacement_meta

        self.assertIs(graph.source_block_at(original_source.address), original_source)
        self.assertIs(graph.block_at(original_meta.address), original_meta)
        with self.assertRaises(TypeError):
            graph.source_blocks[original_source.address] = replacement_source
        with self.assertRaises(TypeError):
            graph.meta_blocks[original_meta.address] = replacement_meta
        with self.assertRaises(FrozenInstanceError):
            graph.entry_address = replacement_source.address

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

    def test_meta_block_graph_replaces_blocks_without_mutating_source_graph(self) -> None:
        original = EndBlock(
            address=0x08020000,
            block_addresses=[0x08020000],
        )
        replacement = EndBlock(
            address=0x08020000,
            block_addresses=[0x08020004],
        )
        graph = MetaBlockGraph(
            source_blocks={},
            meta_blocks={original.address: original},
            entry_address=original.address,
        )

        updated = graph.with_block(replacement)

        self.assertIs(graph.block_at(original.address), original)
        self.assertIs(updated.block_at(replacement.address), replacement)
        self.assertIsNot(updated, graph)

    def test_simplify_if_returns_updated_graph_without_mutating_input(self) -> None:
        parent = IfBlock(
            address=0x08020000,
            condition_blocks=[0x08020000],
            flags=[True],
            conjunctions=[],
            true_address=0x08020008,
            false_address=0x08020004,
            next_address=None,
        )
        child = IfBlock(
            address=0x08020004,
            condition_blocks=[0x08020004],
            flags=[False],
            conjunctions=[b" || "],
            true_address=None,
            false_address=0x08020008,
            next_address=None,
        )
        end = EndBlock(
            address=0x08020008,
            block_addresses=[0x08020008],
        )
        graph = MetaBlockGraph(
            source_blocks={},
            meta_blocks={
                parent.address: parent,
                child.address: child,
                end.address: end,
            },
            entry_address=parent.address,
        )

        updated = simplify_if(graph)

        self.assertIs(graph.block_at(parent.address), parent)
        self.assertIsNot(updated, graph)
        simplified = updated.block_at(parent.address)
        self.assertIsInstance(simplified, IfBlock)
        self.assertEqual(simplified.condition_blocks, (0x08020000, 0x08020004))
        self.assertEqual(simplified.false_address, None)
        self.assertEqual(simplified.conjunctions, (b" && ", b" && "))
        self.assertEqual(simplified.flags, (True, False))

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
