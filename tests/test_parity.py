import tempfile
import unittest
import shutil
from pathlib import Path

from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.core.flow import EdgeKind
from decomp.parity import (
    BlockFingerprint,
    FunctionFingerprint,
    ParitySnapshot,
    _block_fingerprints,
    capture_legacy_snapshot,
    compare_snapshots,
    read_snapshot,
    write_snapshot,
)


class ParitySnapshotTests(unittest.TestCase):
    def make_snapshot(self, *, calls: tuple[int, ...] = (0x08020010,)) -> ParitySnapshot:
        return ParitySnapshot(
            architecture="arm-thumb",
            base_address=0x08020000,
            entry_point=0x080202CC,
            binary_sha256="abc",
            binary_size=10,
            max_functions=1,
            discovery_order=(0x080202CC,),
            functions=(
                FunctionFingerprint(
                    address=0x080202CC,
                    status="ok",
                    calls=tuple(calls),
                    blocks=(
                        BlockFingerprint(
                            address=0x080202CC,
                            end=0x080202D0,
                            instruction_count=2,
                            outgoing=(0x080202D0,),
                            incoming=(),
                        ),
                    ),
                ),
            ),
        )

    def test_round_trips_snapshot_json(self) -> None:
        snapshot = self.make_snapshot()
        with tempfile.TemporaryDirectory() as temp_dir:
            path = Path(temp_dir) / "snapshot.json"
            write_snapshot(snapshot, path)

            restored = read_snapshot(path)

        self.assertEqual(restored, snapshot)

    def test_compare_reports_structural_drift(self) -> None:
        expected = self.make_snapshot()
        actual = self.make_snapshot(calls=(0x08020020,))

        differences = compare_snapshots(expected, actual)

        self.assertTrue(any("0x80202cc.calls" in difference for difference in differences))

    def test_block_fingerprints_use_cfg_graph_order(self) -> None:
        entry = BasicBlock(
            address=0x08020004,
            end=0x08020006,
            instructions=(),
            outgoing=(
                Edge(
                    source=0x08020004,
                    target=0x08020000,
                    kind=EdgeKind.JUMP,
                ),
            ),
        )
        target = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
            incoming=(
                Edge(
                    source=0x08020004,
                    target=0x08020000,
                    kind=EdgeKind.JUMP,
                ),
            ),
        )
        cfg = ControlFlowGraph(
            entry=entry.address,
            blocks={
                entry.address: entry,
                target.address: target,
            },
        )

        self.assertEqual(
            _block_fingerprints(cfg),
            (
                BlockFingerprint(
                    address=0x08020000,
                    end=0x08020002,
                    instruction_count=0,
                    outgoing=(),
                    incoming=(0x08020004,),
                ),
                BlockFingerprint(
                    address=0x08020004,
                    end=0x08020006,
                    instruction_count=0,
                    outgoing=(0x08020000,),
                    incoming=(),
                ),
            ),
        )

    def test_dd2_binary_matches_checked_in_parity_fixture_if_available(self) -> None:
        binary_path = Path("/Volumes/Locker/Synth/DD2.1.0.bin")
        if not binary_path.exists():
            self.skipTest("DD2.1.0.bin is not available on this machine")
        if shutil.which("rasm2") is None:
            self.skipTest("rasm2 is not available on PATH")

        expected = read_snapshot("tests/fixtures/dd2_1_0_parity_max10.json")
        actual = capture_legacy_snapshot(
            binary_path,
            entry_point=expected.entry_point,
            base_address=expected.base_address,
            architecture=expected.architecture,
            max_functions=expected.max_functions,
        )

        self.assertEqual(compare_snapshots(expected, actual), [])


if __name__ == "__main__":
    unittest.main()
