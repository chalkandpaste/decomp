import unittest

from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.render_asm import render_block_graph_asm


class RenderAsmTests(unittest.TestCase):
    def test_renders_legacy_block_graph_in_address_order(self) -> None:
        first = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08020010, 0x08020020]],
            ),
            successors=(0x08020010, 0x08020020),
            predecessors=(),
        )
        second = LegacyBlock(
            address=0x08020010,
            end_address=0x08020012,
            instructions=([b"0x8020010", b"2", b"0000", b"bx", b"lr"],),
            successors=(),
            predecessors=(first.address,),
        )
        graph = LegacyBlockGraph(
            entry_address=first.address,
            blocks={
                second.address: second,
                first.address: first,
            },
        )

        self.assertEqual(
            render_block_graph_asm(graph),
            (
                b"0x8020000 2 0000 tbb [pc, r0] 0x8020010, 0x8020020\n"
                b"0x8020010 2 0000 bx lr"
            ),
        )


if __name__ == "__main__":
    unittest.main()
