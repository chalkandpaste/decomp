import contextlib
import io
import unittest

from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.loop_tracker import LoopInfo, LoopTracker


def _legacy_block(address: int, successors: tuple[int, ...], predecessors: tuple[int, ...]) -> LegacyBlock:
    return LegacyBlock(
        address=address,
        end_address=address + 2,
        instructions=(),
        successors=successors,
        predecessors=predecessors,
    )


class LoopTrackerTests(unittest.TestCase):
    def test_loop_tracker_uses_block_graph_model(self) -> None:
        first = _legacy_block(0x08020000, (0x08020002,), (0x08020002,))
        second = _legacy_block(0x08020002, (0x08020000,), (0x08020000,))
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

        self.assertEqual(tracker.loop_locations(first.address), (first.address, second.address))
        self.assertEqual(
            tracker.loop_info(first.address),
            LoopInfo(start=None, end=None, locations=(first.address, second.address)),
        )
        self.assertIsNone(tracker.get_loop_start(first.address))
        self.assertIsNone(tracker.get_loop_end(first.address))
        self.assertFalse(tracker.is_loop_start(first.address))
        self.assertFalse(tracker.is_loop_end(first.address))

    def test_loop_tracker_exposes_cached_loop_boundaries_for_structured_loop(self) -> None:
        entry = _legacy_block(0x08020000, (0x08020002,), ())
        loop_start = _legacy_block(0x08020002, (0x08020004,), (entry.address, 0x08020004))
        loop_end = _legacy_block(0x08020004, (loop_start.address, 0x08020006), (loop_start.address,))
        exit_block = _legacy_block(0x08020006, (), (loop_end.address,))
        graph = LegacyBlockGraph(
            blocks={
                entry.address: entry,
                loop_start.address: loop_start,
                loop_end.address: loop_end,
                exit_block.address: exit_block,
            },
            entry_address=entry.address,
        )
        tracker = LoopTracker(graph)

        with contextlib.redirect_stdout(io.StringIO()):
            self.assertTrue(tracker.can_loop(loop_start.address))

        self.assertEqual(tracker.get_loop_start(loop_start.address), loop_start.address)
        self.assertEqual(tracker.get_loop_start(loop_end.address), loop_start.address)
        self.assertEqual(tracker.get_loop_end(loop_start.address), loop_end.address)
        self.assertEqual(tracker.get_loop_end(loop_end.address), loop_end.address)
        self.assertTrue(tracker.is_loop_start(loop_start.address))
        self.assertFalse(tracker.is_loop_start(loop_end.address))
        self.assertFalse(tracker.is_loop_end(loop_start.address))
        self.assertTrue(tracker.is_loop_end(loop_end.address))

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
        block = _legacy_block(0x08020000, (), ())
        graph = LegacyBlockGraph(
            blocks={block.address: block},
            entry_address=block.address,
        )
        tracker = LoopTracker(graph)

        with contextlib.redirect_stdout(io.StringIO()):
            self.assertFalse(tracker.can_loop(block.address))

        self.assertEqual(tracker.not_loop_loc, {block.address})
        self.assertIsNone(tracker.get_loop_start(block.address))
        self.assertIsNone(tracker.get_loop_end(block.address))
        self.assertFalse(tracker.is_loop_start(block.address))
        self.assertFalse(tracker.is_loop_end(block.address))

    def test_loop_start_and_end_accessors_do_not_trigger_detection(self) -> None:
        block = _legacy_block(0x08020000, (), ())
        graph = LegacyBlockGraph(
            blocks={block.address: block},
            entry_address=block.address,
        )
        tracker = LoopTracker(graph)

        self.assertIsNone(tracker.get_loop_start(block.address))
        self.assertIsNone(tracker.get_loop_end(block.address))
        self.assertEqual(tracker.not_loop_loc, set())


if __name__ == "__main__":
    unittest.main()
