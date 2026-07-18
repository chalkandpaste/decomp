import contextlib
import io
import unittest

from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.loop_tracker import LoopTracker


class LoopTrackerTests(unittest.TestCase):
    def test_loop_tracker_uses_block_graph_model(self) -> None:
        first = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(0x08020002,),
            predecessors=(0x08020002,),
        )
        second = LegacyBlock(
            address=0x08020002,
            end_address=0x08020004,
            instructions=(),
            successors=(0x08020000,),
            predecessors=(0x08020000,),
        )
        graph = LegacyBlockGraph(
            blocks={
                first.address: first,
                second.address: second,
            },
            entry_address=first.address,
        )

        tracker = LoopTracker(graph)

        with contextlib.redirect_stdout(io.StringIO()):
            self.assertTrue(tracker.can_loop(first.address))

        self.assertEqual(tracker.loc_to_loop_locs[first.address], (first.address, second.address))

    def test_loop_tracker_accepts_typed_control_flow_graph(self) -> None:
        first = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
            outgoing=(Edge(source=0x08020000, target=0x08020002),),
            incoming=(Edge(source=0x08020002, target=0x08020000),),
        )
        second = BasicBlock(
            address=0x08020002,
            end=0x08020004,
            instructions=(),
            outgoing=(Edge(source=0x08020002, target=0x08020000),),
            incoming=(Edge(source=0x08020000, target=0x08020002),),
        )
        graph = ControlFlowGraph(
            entry=first.address,
            blocks={
                first.address: first,
                second.address: second,
            },
        )

        tracker = LoopTracker(graph)

        with contextlib.redirect_stdout(io.StringIO()):
            self.assertTrue(tracker.can_loop(first.address))

    def test_loop_tracker_tracks_non_loop_locations_with_set_membership(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(),
            predecessors=(),
        )
        graph = LegacyBlockGraph(
            blocks={block.address: block},
            entry_address=block.address,
        )
        tracker = LoopTracker(graph)

        with contextlib.redirect_stdout(io.StringIO()):
            self.assertFalse(tracker.can_loop(block.address))

        self.assertEqual(tracker.not_loop_loc, {block.address})


if __name__ == "__main__":
    unittest.main()
