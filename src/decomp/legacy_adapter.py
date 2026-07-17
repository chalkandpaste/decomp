from __future__ import annotations

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.core.flow import EdgeKind
from decomp.core.instruction import Instruction
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


def legacy_block_graph_to_cfg(block_graph: LegacyBlockGraph, backend: ArmThumbBackend | None = None) -> ControlFlowGraph:
    backend = backend or ArmThumbBackend()
    start = block_graph["start_block"]["loc"]
    legacy_blocks = block_graph["index"]

    incoming: dict[int, list[Edge]] = {address: [] for address in legacy_blocks}
    outgoing: dict[int, list[Edge]] = {}

    for address, block in legacy_blocks.items():
        block_edges = []
        for index, child in enumerate(block["children"]):
            edge = Edge(
                source=address,
                target=child,
                kind=_edge_kind_for_child(index, len(block["children"])),
            )
            block_edges.append(edge)
            incoming.setdefault(child, []).append(edge)
        outgoing[address] = block_edges

    blocks = {}
    for address, block in legacy_blocks.items():
        instructions = tuple(
            backend.decode_legacy_tokens(tokens)
            for tokens in block["block"]
        )
        blocks[address] = BasicBlock(
            address=block["loc"],
            end=_legacy_block_end(block, instructions),
            instructions=instructions,
            outgoing=tuple(outgoing.get(address, ())),
            incoming=tuple(incoming.get(address, ())),
            depth=block.depth,
        )

    return ControlFlowGraph(entry=start, blocks=blocks)


def _legacy_block_end(block: LegacyBlock, instructions: tuple[Instruction, ...]) -> int:
    if "end_loc" in block:
        return block["end_loc"]
    if instructions:
        last = instructions[-1]
        return last.address + last.size
    return block["loc"]


def _edge_kind_for_child(index: int, child_count: int) -> EdgeKind:
    if child_count == 1:
        return EdgeKind.JUMP
    if child_count == 2:
        return EdgeKind.TRUE_BRANCH if index == 0 else EdgeKind.FALSE_BRANCH
    if child_count > 2:
        return EdgeKind.SWITCH_CASE
    return EdgeKind.UNKNOWN
