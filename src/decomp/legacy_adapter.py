from __future__ import annotations

from decomp.arch import ArchitectureBackend, default_architecture_backend
from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.core.flow import EdgeKind
from decomp.legacy_types import LegacyBlock, LegacyBlockGraph


def legacy_block_graph_to_cfg(
    block_graph: LegacyBlockGraph,
    backend: ArchitectureBackend | None = None,
) -> ControlFlowGraph:
    decoder = backend or default_architecture_backend()
    start = block_graph.entry_address
    legacy_blocks = block_graph.block_items()

    incoming: dict[int, list[Edge]] = {address: [] for address, _block in legacy_blocks}
    outgoing: dict[int, list[Edge]] = {}

    for address, block in legacy_blocks:
        block_edges = []
        for index, child in enumerate(block.successors):
            edge = Edge(
                source=address,
                target=child,
                kind=_edge_kind_for_child(index, len(block.successors)),
            )
            block_edges.append(edge)
            incoming.setdefault(child, []).append(edge)
        outgoing[address] = block_edges

    blocks = {}
    for address, block in legacy_blocks:
        instructions = tuple(
            decoder.decode_legacy_tokens(tokens)
            for tokens in block.instructions
        )
        blocks[address] = BasicBlock(
            address=block.address,
            end=_legacy_block_end(block),
            instructions=instructions,
            outgoing=tuple(outgoing.get(address, ())),
            incoming=tuple(incoming.get(address, ())),
            depth=block.depth,
        )

    return ControlFlowGraph(entry=start, blocks=blocks)


def _legacy_block_end(block: LegacyBlock) -> int:
    return block.end_address


def _edge_kind_for_child(index: int, child_count: int) -> EdgeKind:
    if child_count == 1:
        return EdgeKind.JUMP
    if child_count == 2:
        return EdgeKind.TRUE_BRANCH if index == 0 else EdgeKind.FALSE_BRANCH
    if child_count > 2:
        return EdgeKind.SWITCH_CASE
    return EdgeKind.UNKNOWN
