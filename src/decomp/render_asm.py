from __future__ import annotations

from .block_graph import generate_block_graph
from .legacy_types import LegacyBlockGraph, LegacyInstruction, LegacyToken


def render_block_graph_asm(block_graph: LegacyBlockGraph) -> bytes:
    locations = sorted(block_graph.addresses())
    instructions: list[LegacyInstruction] = []

    for location in locations:
        instructions.extend(block_graph.block_at(location).instructions)

    return b"\n".join(_render_instruction(instruction) for instruction in instructions)


def generate_asm(
    binary: bytes | None,
    entry_point_loc: int,
    cache: bool = True,
    override: list[LegacyInstruction] | None = None,
) -> bytes:
    block_graph = generate_block_graph(binary, entry_point_loc, cache, override)
    return render_block_graph_asm(block_graph)


def _render_instruction(instruction: LegacyInstruction) -> bytes:
    return b" ".join(
        rendered
        for token in instruction
        if (rendered := _render_token(token)) is not None
    )


def _render_token(token: LegacyToken) -> bytes | None:
    if isinstance(token, bytes):
        return token
    if isinstance(token, list):
        return b", ".join(bytes(hex(target), "utf-8") for target in token)
    return None
