import contextlib
import io
import unittest

from decomp.function_signatures import add_function_sigs, get_function_signature
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


class FunctionSignatureTests(unittest.TestCase):
    def test_add_function_sigs_uses_reachable_graph_order(self) -> None:
        entry = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            successors=(0x08020004,),
            predecessors=(),
            instructions=(
                [b"0x8020000", b"4", b"00000000", b"bl", b"0x8030000"],
            ),
        )
        reachable = LegacyBlock(
            address=0x08020004,
            end_address=0x08020008,
            successors=(),
            predecessors=(entry.address,),
            instructions=(
                [b"0x8020004", b"4", b"00000000", b"b.w", b"0x8040000"],
            ),
        )
        unreachable = LegacyBlock(
            address=0x08020008,
            end_address=0x0802000C,
            successors=(),
            predecessors=(),
            instructions=(
                [b"0x8020008", b"4", b"00000000", b"bl", b"0x8050000"],
            ),
        )
        graph = LegacyBlockGraph(
            entry_address=entry.address,
            blocks={
                entry.address: entry,
                reachable.address: reachable,
                unreachable.address: unreachable,
            },
        )

        updated = add_function_sigs(
            graph,
            {
                0x08030000: b"; void func_0x8030000()",
                0x08040000: b"; int func_0x8040000()",
                0x08050000: b"; float func_0x8050000()",
            },
        )

        self.assertEqual(updated.block_at(entry.address).instructions[0][-1], b"; void func_0x8030000()")
        self.assertEqual(updated.block_at(reachable.address).instructions[0][-1], b"; int func_0x8040000()")
        self.assertEqual(updated.block_at(unreachable.address).instructions, unreachable.instructions)
        self.assertEqual(graph.block_at(entry.address).instructions, entry.instructions)

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

    def test_merges_arguments_from_multiple_branch_exits(self) -> None:
        entry = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            successors=(0x08020008, 0x08020004),
            predecessors=(),
            instructions=(
                [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
                [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
            ),
        )
        false_block = LegacyBlock(
            address=0x08020004,
            end_address=0x08020008,
            successors=(),
            predecessors=(entry.address,),
            instructions=(
                [b"0x8020004", b"2", b"0000", b"str", b"r1,", b"[r3,", b"0]"],
                [b"0x8020006", b"2", b"0000", b"bx", b"lr"],
            ),
        )
        true_block = LegacyBlock(
            address=0x08020008,
            end_address=0x0802000C,
            successors=(),
            predecessors=(entry.address,),
            instructions=(
                [b"0x8020008", b"2", b"0000", b"str", b"r2,", b"[r3,", b"0]"],
                [b"0x802000a", b"2", b"0000", b"bx", b"lr"],
            ),
        )
        graph = LegacyBlockGraph(
            entry_address=entry.address,
            blocks={
                entry.address: entry,
                false_block.address: false_block,
                true_block.address: true_block,
            },
        )

        _return_scope, arg_scope = _quiet_signature(graph)

        self.assertTrue(arg_scope[b"r0"])
        self.assertTrue(arg_scope[b"r1"])
        self.assertTrue(arg_scope[b"r2"])
        self.assertTrue(arg_scope[b"r3"])


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
