import contextlib
import io
import unittest

from decomp.block_graph import generate_block_graph
from decomp.legacy_types import LegacyBlock
from decomp.meta_blocks import EndBlock, MetaBlockGraph
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
        self.assertEqual(graph.block_index, graph.source_blocks)


if __name__ == "__main__":
    unittest.main()
