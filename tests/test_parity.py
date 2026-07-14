import tempfile
import unittest
import shutil
from pathlib import Path

from decomp.parity import (
    BlockFingerprint,
    FunctionFingerprint,
    ParitySnapshot,
    capture_legacy_snapshot,
    compare_snapshots,
    read_snapshot,
    write_snapshot,
)


class ParitySnapshotTests(unittest.TestCase):
    def make_snapshot(self, *, calls=(0x08020010,)):
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

    def test_round_trips_snapshot_json(self):
        snapshot = self.make_snapshot()
        with tempfile.TemporaryDirectory() as temp_dir:
            path = Path(temp_dir) / "snapshot.json"
            write_snapshot(snapshot, path)

            restored = read_snapshot(path)

        self.assertEqual(restored, snapshot)

    def test_compare_reports_structural_drift(self):
        expected = self.make_snapshot()
        actual = self.make_snapshot(calls=(0x08020020,))

        differences = compare_snapshots(expected, actual)

        self.assertTrue(any("0x80202cc.calls" in difference for difference in differences))

    def test_dd2_binary_matches_checked_in_parity_fixture_if_available(self):
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
