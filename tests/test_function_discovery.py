import unittest

from decomp.function_discovery import FunctionDiscovery
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class FunctionDiscoveryTests(unittest.TestCase):
    def test_called_functions_preserves_order_and_filters_skips(self) -> None:
        entry = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            instructions=(),
            successors=(),
            predecessors=(),
        )
        discovery = FunctionDiscovery(
            entry_address=entry.address,
            call_graph={
                entry.address: (0x08030000, 0x08020298, 0x08030000),
                0x08030000: (0x08040000,),
            },
            block_graphs={
                entry.address: LegacyBlockGraph(entry_address=entry.address, blocks={entry.address: entry}),
            },
        )

        self.assertEqual(discovery.called_functions(), (0x08030000, 0x08040000))


if __name__ == "__main__":
    unittest.main()
