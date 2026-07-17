from __future__ import annotations

from dataclasses import replace
from typing import Protocol

from decomp.arch.arm_thumb import ArmThumbBackend
from decomp.core.cfg import BasicBlock, ControlFlowGraph, Edge
from decomp.core.flow import EdgeKind
from decomp.core.instruction import Instruction
from decomp.instruction_buffer import InstructionsBuffer
from decomp.instructions import (
    block_end,
    cond_block_end,
    cond_block_end_zero,
    exchange_return,
    func_end,
    tbb,
    uncond_block_end,
)


class InstructionSource(Protocol):
    def read_at(self, address: int) -> tuple[Instruction, ...]:
        """Read typed instructions starting at an address."""

    def refresh_at(self, address: int) -> None:
        """Refresh the backing window at an address when a suffix is too short."""


class InstructionsBufferSource:
    def __init__(self, buffer: InstructionsBuffer) -> None:
        self.buffer = buffer

    def read_at(self, address: int) -> tuple[Instruction, ...]:
        return self.buffer.read_typed_insns_at_loc(address)

    def refresh_at(self, address: int) -> None:
        self.buffer.update_loc(address)


class LegacyTokenInstructionSource:
    def __init__(self, legacy_tokens: list[list[object]], backend: ArmThumbBackend | None = None) -> None:
        self.legacy_tokens = legacy_tokens
        self.backend = backend or ArmThumbBackend()
        self.instructions = tuple(
            self.backend.decode_legacy_tokens(tokens)
            for tokens in legacy_tokens
        )
        self.index = {
            instruction.address: index
            for index, instruction in enumerate(self.instructions)
        }

    def read_at(self, address: int) -> tuple[Instruction, ...]:
        try:
            index = self.index[address]
        except KeyError as exc:
            raise KeyError(f"address {hex(address)} not found in override input") from exc
        return self.instructions[index:]

    def refresh_at(self, _address: int) -> None:
        return None


def build_control_flow_graph(source: InstructionSource, entry_point: int) -> ControlFlowGraph:
    blocks: dict[int, BasicBlock] = {}
    search_locs = [entry_point]

    while search_locs:
        search_locs.sort()
        search_loc = search_locs.pop(0)
        if search_loc in blocks:
            continue

        block, children = _read_block(source, search_loc)
        blocks[search_loc] = _with_outgoing_edges(block, children)

        for child in children:
            if child not in search_locs and child not in blocks:
                search_locs.append(child)

    blocks = _trim_overlapping_blocks(blocks)
    blocks = _attach_incoming_edges(entry_point, blocks)
    return ControlFlowGraph(entry=entry_point, blocks=blocks)


def cfg_to_legacy_block_graph(cfg: ControlFlowGraph) -> dict[str, object]:
    parents = _legacy_parent_index(cfg.entry, cfg.blocks)
    index = {}

    for address, block in cfg.blocks.items():
        index[address] = {
            "loc": block.address,
            "end_loc": block.end,
            "block": [_legacy_tokens(instruction) for instruction in block.instructions],
            "children": [edge.target for edge in block.outgoing],
            "parents": parents.get(address, []),
            "depth": block.depth,
        }

    return {
        "index": index,
        "start_block": index[cfg.entry],
    }


def _read_block(source: InstructionSource, address: int) -> tuple[BasicBlock, list[int]]:
    refreshed = False
    while True:
        instructions = source.read_at(address)
        block_instructions, end_of_function, is_complete = _collect_block_instructions(instructions)

        if is_complete:
            break
        if refreshed:
            raise ValueError(f"could not find block end after refreshing at {hex(address)}")

        source.refresh_at(address)
        refreshed = True

    end = block_instructions[-1].address + block_instructions[-1].size
    children = [] if end_of_function else _children_for_block(block_instructions)
    block = BasicBlock(
        address=address,
        end=end,
        instructions=tuple(block_instructions),
    )
    return block, children


def _collect_block_instructions(instructions: tuple[Instruction, ...]) -> tuple[list[Instruction], bool, bool]:
    block = []
    end_of_function = False
    found_block_end = False

    for index, instruction in enumerate(instructions):
        tokens = _legacy_tokens(instruction)
        mnemonic = _mnemonic(instruction)
        block.append(instruction)

        if mnemonic in block_end:
            found_block_end = True
            break

        if mnemonic in func_end + exchange_return:
            end_of_function = True
            if _contains_pc_return(tokens):
                break
            if mnemonic == b"bx" and len(tokens) >= 5 and tokens[4] == b"lr":
                break
            if _contains_lr_restore(tokens):
                for tail_instruction in instructions[index + 1:]:
                    block.append(tail_instruction)
                    if _mnemonic(tail_instruction) in uncond_block_end:
                        break
                break
            if (mnemonic == b"pop" and not _contains_pc_return(tokens)) or not _contains_lr_restore(tokens):
                end_of_function = False
                continue

            raise ValueError(f"unsupported function ending: {tokens!r}")

    return block, end_of_function, found_block_end or end_of_function


def _children_for_block(instructions: list[Instruction]) -> list[int]:
    last = instructions[-1]
    tokens = _legacy_tokens(last)
    mnemonic = _mnemonic(last)

    if mnemonic in cond_block_end:
        jump_loc = int(tokens[4], 0)
        next_block_loc = last.address + last.size
        return [jump_loc, next_block_loc]

    if mnemonic in cond_block_end_zero:
        jump_loc = int(tokens[5], 0)
        next_block_loc = last.address + last.size
        return [jump_loc, next_block_loc]

    if mnemonic in uncond_block_end:
        return [int(tokens[4], 0)]

    if mnemonic in tbb:
        return list(tokens[-1])

    return [last.address + last.size]


def _with_outgoing_edges(block: BasicBlock, children: list[int]) -> BasicBlock:
    return replace(
        block,
        outgoing=tuple(
            Edge(
                source=block.address,
                target=child,
                kind=_edge_kind_for_child(index, len(children)),
            )
            for index, child in enumerate(children)
        ),
    )


def _trim_overlapping_blocks(blocks: dict[int, BasicBlock]) -> dict[int, BasicBlock]:
    updated = dict(blocks)
    block_locs = sorted(updated.keys(), reverse=True)

    for index in range(0, len(block_locs) - 1):
        curr_block = updated[block_locs[index]]
        prev_block = updated[block_locs[index + 1]]

        if curr_block.address < prev_block.end:
            trimmed_instructions = tuple(
                instruction
                for instruction in prev_block.instructions
                if instruction.address < curr_block.address
            )
            trimmed_block = BasicBlock(
                address=prev_block.address,
                end=curr_block.address,
                instructions=trimmed_instructions,
            )
            updated[prev_block.address] = _with_outgoing_edges(trimmed_block, [curr_block.address])

    return updated


def _attach_incoming_edges(entry_point: int, blocks: dict[int, BasicBlock]) -> dict[int, BasicBlock]:
    incoming = {address: [] for address in blocks}

    for source in _reachable_block_order(entry_point, blocks):
        for edge in blocks[source].outgoing:
            if edge.target in incoming and edge.source not in [existing.source for existing in incoming[edge.target]]:
                incoming[edge.target].append(edge)

    return {
        address: replace(block, incoming=tuple(incoming[address]))
        for address, block in blocks.items()
    }


def _legacy_parent_index(entry_point: int, blocks: dict[int, BasicBlock]) -> dict[int, list[int]]:
    parents = {address: [] for address in blocks}
    for source in _reachable_block_order(entry_point, blocks):
        for edge in blocks[source].outgoing:
            if edge.target in parents and edge.source not in parents[edge.target]:
                parents[edge.target].append(edge.source)
    return parents


def _reachable_block_order(entry_point: int, blocks: dict[int, BasicBlock]) -> list[int]:
    retrace_nodes = [entry_point]
    tally = {address: True for address in blocks}
    order = []

    while retrace_nodes:
        address = retrace_nodes.pop(-1)
        if address not in blocks or not tally[address]:
            continue
        tally[address] = False
        order.append(address)

        for edge in blocks[address].outgoing:
            if edge.target in tally and tally[edge.target]:
                retrace_nodes.append(edge.target)

    return order


def _edge_kind_for_child(index: int, child_count: int) -> EdgeKind:
    if child_count == 1:
        return EdgeKind.JUMP
    if child_count == 2:
        return EdgeKind.TRUE_BRANCH if index == 0 else EdgeKind.FALSE_BRANCH
    if child_count > 2:
        return EdgeKind.SWITCH_CASE
    return EdgeKind.UNKNOWN


def _legacy_tokens(instruction: Instruction) -> list[object]:
    if instruction.legacy_tokens:
        return list(instruction.legacy_tokens)
    return list(instruction.raw_tokens)


def _mnemonic(instruction: Instruction) -> bytes:
    return instruction.mnemonic.encode("ascii")


def _contains_pc_return(tokens: list[object]) -> bool:
    return b"pc," in tokens[5:] or b"pc}" in tokens[4:] or b"{pc}" in tokens[4:]


def _contains_lr_restore(tokens: list[object]) -> bool:
    return b"lr," in tokens[5:] or b"lr}" in tokens[4:]
