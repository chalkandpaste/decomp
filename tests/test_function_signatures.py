import contextlib
import io
import unittest

from decomp.function_signatures import (
    ArgumentDeclaration,
    FunctionDeclaration,
    RegisterScope,
    RegisterSignature,
    ReturnDeclaration,
    add_function_sigs,
    get_function_signature,
    render_function_declaration,
)
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

        signature = _quiet_signature(graph)

        self.assertTrue(signature.return_scope.uses(b"r0"))
        self.assertFalse(signature.return_scope.uses(b"r1"))
        self.assertFalse(signature.argument_scope.uses(b"r0"))

    def test_detects_store_input_registers_as_arguments(self) -> None:
        graph = _single_block_graph(
            [
                [b"0x8020000", b"2", b"0000", b"str", b"r1,", b"[r0,", b"0]"],
                [b"0x8020002", b"2", b"0000", b"bx", b"lr"],
            ]
        )

        signature = _quiet_signature(graph)

        self.assertFalse(signature.return_scope.uses(b"r0"))
        self.assertTrue(signature.argument_scope.uses(b"r0"))
        self.assertTrue(signature.argument_scope.uses(b"r1"))

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

        signature = _quiet_signature(graph)

        self.assertTrue(signature.argument_scope.uses(b"r0"))
        self.assertTrue(signature.argument_scope.uses(b"r1"))
        self.assertTrue(signature.argument_scope.uses(b"r2"))
        self.assertTrue(signature.argument_scope.uses(b"r3"))

    def test_render_function_declaration_returns_named_record(self) -> None:
        signature = RegisterSignature(
            return_scope=_scope((b"r0",)),
            argument_scope=_scope((b"r0", b"r1")),
        )

        declaration = render_function_declaration(signature, 0x08034F48)

        self.assertIsInstance(declaration, FunctionDeclaration)
        self.assertEqual(declaration.render(), b"int func_0x8034f48 ( int r0, int r1 )")
        self.assertEqual(declaration.render_comment(), b"; int func_0x8034f48 ( int r0, int r1 )")

    def test_render_function_declaration_uses_highest_argument_register(self) -> None:
        signature = RegisterSignature(
            return_scope=_scope(()),
            argument_scope=_scope((b"r0", b"r2")),
        )

        declaration = render_function_declaration(signature, 0x08034F48)

        self.assertEqual(declaration.render(), b"void func_0x8034f48 ( int r0, int r1, int r2 )")

    def test_render_function_declaration_defaults_to_void_no_args(self) -> None:
        signature = RegisterSignature(
            return_scope=_scope(()),
            argument_scope=_scope(()),
        )

        declaration = render_function_declaration(signature, 0x08034F48)

        self.assertEqual(declaration.render(), b"void func_0x8034f48 ()")

    def test_declaration_conventions_are_named_records(self) -> None:
        argument = ArgumentDeclaration(
            highest_register=b"r1",
            prototype_suffix=b" ( int r0, int r1 )",
        )
        return_value = ReturnDeclaration(
            register=b"r0",
            return_type=b"int ",
        )

        self.assertEqual(argument.highest_register, b"r1")
        self.assertEqual(argument.prototype_suffix, b" ( int r0, int r1 )")
        self.assertEqual(return_value.register, b"r0")
        self.assertEqual(return_value.return_type, b"int ")

    def test_register_signature_scopes_are_read_only(self) -> None:
        return_scope = _scope((b"r0",))
        argument_scope = _scope((b"r1",))
        signature = RegisterSignature(
            return_scope=return_scope,
            argument_scope=argument_scope,
        )

        return_scope[b"r0"] = False
        argument_scope[b"r1"] = False

        self.assertTrue(signature.return_scope.uses(b"r0"))
        self.assertTrue(signature.argument_scope.uses(b"r1"))
        with self.assertRaises(TypeError):
            signature.return_scope._values[b"r0"] = False
        with self.assertRaises(TypeError):
            signature.argument_scope._values[b"r1"] = False

    def test_register_scope_reports_first_used_register(self) -> None:
        scope = RegisterScope.from_mapping(_scope((b"r0", b"r2")))

        self.assertTrue(scope.uses(b"r2"))
        self.assertEqual(scope.first_used((b"r3", b"r2", b"r0")), b"r2")
        self.assertIsNone(scope.first_used((b"s0", b"s1")))


def _single_block_graph(instructions: list[list[object]]) -> LegacyBlockGraph:
    block = LegacyBlock(
        address=0x08020000,
        end_address=0x08020004,
        successors=(),
        predecessors=(),
        instructions=tuple(instructions),
    )
    return LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})


def _quiet_signature(block_graph: LegacyBlockGraph) -> RegisterSignature:
    with contextlib.redirect_stdout(io.StringIO()):
        return get_function_signature(block_graph)


def _scope(enabled_registers: tuple[bytes, ...]) -> dict[bytes, bool]:
    registers = (
        b"r0",
        b"r1",
        b"r2",
        b"r3",
        b"s0",
        b"s1",
        b"s2",
        b"s3",
        b"d0",
        b"d1",
        b"d2",
        b"d3",
    )
    return {register: register in enabled_registers for register in registers}


if __name__ == "__main__":
    unittest.main()
