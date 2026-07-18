import contextlib
import io
import unittest

from decomp.block_graph import generate_block_graph, recurse_graph
from decomp.analysis import LegacyTokenInstructionSource, build_control_flow_graph
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class BlockGraphTests(unittest.TestCase):
    def test_conditional_branch_splits_into_true_and_false_blocks(self) -> None:
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

        self.assertEqual(graph.start_block.address, 0x08020000)
        self.assertEqual(
            graph.successors(0x08020000),
            (0x08020008, 0x08020004),
        )
        self.assertEqual(graph.predecessors(0x08020004), (0x08020000,))
        self.assertEqual(graph.predecessors(0x08020008), (0x08020000,))
        self.assertEqual(
            sorted(graph.addresses()),
            [0x08020000, 0x08020004, 0x08020008],
        )

    def test_recurse_graph_callback_receives_graph_model(self) -> None:
        insns = [
            [b"0x8020000", b"2", b"0000", b"b", b"0x8020004"],
            [b"0x8020004", b"2", b"0000", b"bx", b"lr"],
        ]

        with contextlib.redirect_stdout(io.StringIO()):
            graph = generate_block_graph(
                None,
                0x08020000,
                use_cache=False,
                override_input=insns,
            )

        def collect_address(block: LegacyBlock, callback_graph: LegacyBlockGraph, seen: object) -> object:
            addresses = list(seen if isinstance(seen, list) else [])
            self.assertIs(callback_graph, graph)
            self.assertEqual(callback_graph.block_at(block.address), block)
            addresses.append(block.address)
            return addresses

        seen_addresses = recurse_graph(graph, collect_address, [], direction=True)

        self.assertEqual(seen_addresses, [0x08020000, 0x08020004])

    def test_unconditional_branch_has_single_jump_child(self) -> None:
        insns = [
            [b"0x8020000", b"2", b"0000", b"b", b"0x8020008"],
            [b"0x8020008", b"2", b"0000", b"bx", b"lr"],
        ]

        with contextlib.redirect_stdout(io.StringIO()):
            graph = generate_block_graph(
                None,
                0x08020000,
                use_cache=False,
                override_input=insns,
            )

        self.assertEqual(graph.successors(0x08020000), (0x08020008,))
        self.assertEqual(graph.predecessors(0x08020008), (0x08020000,))

    def test_return_block_has_no_children(self) -> None:
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

        self.assertEqual(graph.successors(0x08020000), ())

    def test_typed_cfg_builder_trims_overlapping_blocks(self) -> None:
        insns = [
            [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
            [b"0x8020002", b"2", b"0000", b"beq", b"0x8020006"],
            [b"0x8020004", b"2", b"0000", b"mov", b"r0,", b"1"],
            [b"0x8020006", b"2", b"0000", b"bx", b"lr"],
        ]

        cfg = build_control_flow_graph(
            LegacyTokenInstructionSource(insns),
            0x08020000,
        )

        self.assertEqual(cfg.blocks[0x08020004].end, 0x08020006)
        self.assertEqual([edge.target for edge in cfg.blocks[0x08020004].outgoing], [0x08020006])


if __name__ == "__main__":
    unittest.main()
