import contextlib
import io
import unittest

from block_graph import generate_block_graph


class BlockGraphTests(unittest.TestCase):
    def test_conditional_branch_splits_into_true_and_false_blocks(self):
        insns = [
            [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
            [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
            [b"0x8020004", b"2", b"0000", b"mov", b"r1,", b"1"],
            [b"0x8020006", b"2", b"0000", b"bx", b"lr"],
            [b"0x8020008", b"2", b"0000", b"mov", b"r1,", b"2"],
            [b"0x802000a", b"2", b"0000", b"bx", b"lr"],
        ]

        with contextlib.redirect_stdout(io.StringIO()):
            graph = generate_block_graph(
                None,
                0x08020000,
                use_cache=False,
                override_input=insns,
            )

        self.assertEqual(graph["start_block"]["loc"], 0x08020000)
        self.assertEqual(
            graph["index"][0x08020000]["children"],
            [0x08020008, 0x08020004],
        )
        self.assertEqual(graph["index"][0x08020004]["parents"], [0x08020000])
        self.assertEqual(graph["index"][0x08020008]["parents"], [0x08020000])


if __name__ == "__main__":
    unittest.main()
