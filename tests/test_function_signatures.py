import contextlib
import io
import unittest

from decomp.function_signatures import get_function_signature
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class FunctionSignatureTests(unittest.TestCase):
    def test_detects_integer_return_register_write(self) -> None:
        graph = _single_block_graph(
            [
                [b"0x8020000", b"2", b"0000", b"mov", b"r0,", b"1"],
                [b"0x8020002", b"2", b"0000", b"bx", b"lr"],
            ]
        )

        return_scope, arg_scope = _quiet_signature(graph)

        self.assertTrue(return_scope[b"r0"])
        self.assertFalse(return_scope[b"r1"])
        self.assertFalse(arg_scope[b"r0"])

    def test_detects_store_input_registers_as_arguments(self) -> None:
        graph = _single_block_graph(
            [
                [b"0x8020000", b"2", b"0000", b"str", b"r1,", b"[r0,", b"0]"],
                [b"0x8020002", b"2", b"0000", b"bx", b"lr"],
            ]
        )

        return_scope, arg_scope = _quiet_signature(graph)

        self.assertFalse(return_scope[b"r0"])
        self.assertTrue(arg_scope[b"r0"])
        self.assertTrue(arg_scope[b"r1"])


def _single_block_graph(instructions: list[list[object]]) -> LegacyBlockGraph:
    block = LegacyBlock(
        address=0x08020000,
        end_address=0x08020004,
        successors=(),
        predecessors=(),
        instructions=tuple(instructions),
    )
    return LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})


def _quiet_signature(block_graph: LegacyBlockGraph) -> tuple[dict[bytes, bool], dict[bytes, bool]]:
    with contextlib.redirect_stdout(io.StringIO()):
        return get_function_signature(block_graph)


if __name__ == "__main__":
    unittest.main()
