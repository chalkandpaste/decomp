import unittest

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.core.cfg import BasicBlock, ControlFlowGraph
from decomp.core import EdgeKind, FlowInfo, FlowKind
from decomp.core.instruction import Instruction
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph
from decomp.legacy_adapter import legacy_block_graph_to_cfg


class SourceMarkingBackend(ArmThumbBackend):
    def decode_legacy_tokens(self, tokens: list[object]) -> Instruction:
        instruction = super().decode_legacy_tokens(tokens)
        return type(instruction)(
            address=instruction.address,
            size=instruction.size,
            data=instruction.data,
            mnemonic=instruction.mnemonic,
            operands=instruction.operands,
            flow=instruction.flow,
            raw_tokens=instruction.raw_tokens,
            legacy_tokens=instruction.legacy_tokens,
            source="test-backend",
        )


class CoreModelAdapterTests(unittest.TestCase):
    def test_flow_info_reports_conditional_successors_in_branch_order(self) -> None:
        flow = FlowInfo(
            kind=FlowKind.CONDITIONAL_BRANCH,
            targets=(0x08020010,),
            fallthrough=0x08020004,
        )

        self.assertEqual(flow.successor_addresses(0x08020002), (0x08020010, 0x08020004))

    def test_flow_info_reports_normalized_target_addresses(self) -> None:
        flow = FlowInfo(kind=FlowKind.CALL, targets=(0x08020011, 0x08020020))

        self.assertEqual(flow.target_addresses(lambda address: address & ~1), (0x08020010, 0x08020020))

    def test_flow_info_reports_call_and_branch_predicates(self) -> None:
        self.assertTrue(FlowInfo(kind=FlowKind.CALL).is_direct_call())
        self.assertFalse(FlowInfo(kind=FlowKind.INDIRECT_CALL).is_direct_call())
        self.assertTrue(FlowInfo(kind=FlowKind.UNCONDITIONAL_BRANCH).is_unconditional_branch())
        self.assertFalse(FlowInfo(kind=FlowKind.CONDITIONAL_BRANCH).is_unconditional_branch())

    def test_flow_info_rejects_incomplete_conditional_branch_successors(self) -> None:
        flow = FlowInfo(kind=FlowKind.CONDITIONAL_BRANCH, targets=())

        with self.assertRaisesRegex(ValueError, "conditional branch lacks typed target information"):
            flow.successor_addresses(0x08020002)

    def test_flow_info_reports_jump_and_switch_targets(self) -> None:
        jump = FlowInfo(kind=FlowKind.UNCONDITIONAL_BRANCH, targets=(0x08020010,))
        switch = FlowInfo(kind=FlowKind.SWITCH, targets=(0x08020010, 0x08020020))

        self.assertEqual(jump.successor_addresses(0x08020002), (0x08020010,))
        self.assertEqual(switch.successor_addresses(0x08020002), (0x08020010, 0x08020020))

    def test_flow_info_reports_fallthrough_and_exits(self) -> None:
        default_flow = FlowInfo(kind=FlowKind.FALLTHROUGH)
        explicit_flow = FlowInfo(kind=FlowKind.CALL, fallthrough=0x08020020)
        exit_flow = FlowInfo(kind=FlowKind.RETURN, is_function_exit=True)

        self.assertEqual(default_flow.successor_addresses(0x08020002), (0x08020002,))
        self.assertEqual(explicit_flow.successor_addresses(0x08020002), (0x08020020,))
        self.assertEqual(exit_flow.successor_addresses(0x08020002), ())

    def test_legacy_block_exposes_common_instruction_and_edge_facts(self) -> None:
        first = [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"]
        last = [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"]
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            successors=(0x08020008, 0x08020004),
            predecessors=(),
            instructions=(first, last),
        )

        self.assertEqual(block.instruction_count, 2)
        self.assertIs(block.first_instruction(), first)
        self.assertIs(block.last_instruction(), last)
        self.assertEqual(block.successor_count, 2)

    def test_converts_legacy_block_graph_to_typed_cfg(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020004,
            successors=(0x08020008, 0x08020004),
            predecessors=(),
            depth=0,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"cmp", b"r0,", b"0"],
                [b"0x8020002", b"2", b"0000", b"beq", b"0x8020008"],
            ),
        )
        true_block = LegacyBlock(
            address=0x08020008,
            end_address=0x0802000A,
            successors=(),
            predecessors=(0x08020000,),
            depth=0,
            instructions=([b"0x8020008", b"2", b"0000", b"bx", b"lr"],),
        )
        false_block = LegacyBlock(
            address=0x08020004,
            end_address=0x08020006,
            successors=(),
            predecessors=(0x08020000,),
            depth=0,
            instructions=([b"0x8020004", b"2", b"0000", b"bx", b"lr"],),
        )
        graph = LegacyBlockGraph(
            entry_address=block.address,
            blocks={
                block.address: block,
                true_block.address: true_block,
                false_block.address: false_block,
            },
        )

        cfg = legacy_block_graph_to_cfg(graph)

        self.assertEqual(cfg.entry, 0x08020000)
        self.assertEqual(cfg.block_starts(), (0x08020000, 0x08020004, 0x08020008))
        self.assertEqual(cfg.outgoing_edges(0x08020000)[0].kind, EdgeKind.TRUE_BRANCH)
        self.assertEqual(cfg.outgoing_edges(0x08020000)[1].kind, EdgeKind.FALSE_BRANCH)
        self.assertEqual(cfg.block_at(0x08020000).instructions[1].flow.kind, FlowKind.CONDITIONAL_BRANCH)
        self.assertEqual(cfg.incoming_edges(0x08020004)[0].source, 0x08020000)
        self.assertEqual(cfg.block_at(0x08020000).address, 0x08020000)
        self.assertEqual(cfg.block_at(0x08020000).instruction_count, 2)
        self.assertEqual(cfg.block_at(0x08020000).successor_addresses(), (0x08020008, 0x08020004))
        self.assertEqual(cfg.block_at(0x08020004).predecessor_addresses(), (0x08020000,))
        self.assertEqual(cfg.successors(0x08020000), (0x08020008, 0x08020004))
        self.assertEqual(cfg.predecessors(0x08020004), (0x08020000,))

    def test_legacy_block_graph_adapter_accepts_architecture_backend(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            successors=(),
            predecessors=(),
            depth=0,
            instructions=([b"0x8020000", b"2", b"0000", b"bx", b"lr"],),
        )
        graph = LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})

        cfg = legacy_block_graph_to_cfg(graph, backend=SourceMarkingBackend())

        self.assertEqual(cfg.block_at(block.address).instructions[0].source, "test-backend")

    def test_control_flow_graph_reachable_order_matches_graph_api(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            successors=(0x08020002, 0x08020004),
            predecessors=(),
            depth=0,
            instructions=([b"0x8020000", b"2", b"0000", b"beq", b"0x8020004"],),
        )
        left = LegacyBlock(
            address=0x08020002,
            end_address=0x08020004,
            successors=(0x08020006,),
            predecessors=(block.address,),
            depth=0,
            instructions=([b"0x8020002", b"2", b"0000", b"b", b"0x8020006"],),
        )
        right = LegacyBlock(
            address=0x08020004,
            end_address=0x08020006,
            successors=(0x08020006,),
            predecessors=(block.address,),
            depth=0,
            instructions=([b"0x8020004", b"2", b"0000", b"b", b"0x8020006"],),
        )
        exit_block = LegacyBlock(
            address=0x08020006,
            end_address=0x08020008,
            successors=(),
            predecessors=(left.address, right.address),
            depth=0,
            instructions=([b"0x8020006", b"2", b"0000", b"bx", b"lr"],),
        )
        graph = LegacyBlockGraph(
            entry_address=block.address,
            blocks={
                block.address: block,
                left.address: left,
                right.address: right,
                exit_block.address: exit_block,
            },
        )
        cfg = legacy_block_graph_to_cfg(graph)

        self.assertTrue(cfg.has_block(block.address))
        self.assertFalse(cfg.has_block(0x08029999))
        self.assertEqual(
            cfg.reachable_order(direction=True),
            (block.address, right.address, exit_block.address, left.address),
        )
        self.assertEqual(
            cfg.reachable_order(direction=False),
            (block.address, left.address, right.address, exit_block.address),
        )
        self.assertEqual(
            cfg.reachable_order(left.address, stop_address=exit_block.address),
            (left.address,),
        )

    def test_control_flow_graph_replaces_blocks_without_mutating_source_graph(self) -> None:
        original = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
        )
        replacement = BasicBlock(
            address=0x08020000,
            end=0x08020004,
            instructions=(),
        )
        cfg = ControlFlowGraph(
            entry=original.address,
            blocks={original.address: original},
        )

        updated = cfg.with_block(replacement)

        self.assertIs(cfg.block_at(original.address), original)
        self.assertIs(updated.block_at(replacement.address), replacement)
        self.assertIsNot(updated, cfg)

    def test_control_flow_graph_blocks_are_read_only(self) -> None:
        original = BasicBlock(
            address=0x08020000,
            end=0x08020002,
            instructions=(),
        )
        replacement = BasicBlock(
            address=0x08020000,
            end=0x08020004,
            instructions=(),
        )
        blocks = {original.address: original}
        cfg = ControlFlowGraph(
            entry=original.address,
            blocks=blocks,
        )

        blocks[original.address] = replacement

        self.assertIs(cfg.block_at(original.address), original)
        with self.assertRaises(TypeError):
            cfg.blocks[original.address] = replacement

    def test_preserves_legacy_table_branch_targets(self) -> None:
        block = LegacyBlock(
            address=0x08020000,
            end_address=0x08020002,
            successors=(0x08020010, 0x08020020),
            predecessors=(),
            depth=0,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"tbb", b"[pc,", b"r0]", [0x08020010, 0x08020020]],
            ),
        )
        graph = LegacyBlockGraph(entry_address=block.address, blocks={block.address: block})

        cfg = legacy_block_graph_to_cfg(graph)

        instruction = cfg.block_at(0x08020000).instructions[0]
        self.assertEqual(instruction.flow.kind, FlowKind.SWITCH)
        self.assertEqual(instruction.flow.targets, (0x08020010, 0x08020020))


if __name__ == "__main__":
    unittest.main()
