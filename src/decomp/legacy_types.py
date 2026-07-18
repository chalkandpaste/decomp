from __future__ import annotations

from dataclasses import dataclass, replace
from typing import Callable, TypeAlias


LegacyToken: TypeAlias = bytes | int | list[int]
LegacyInstruction: TypeAlias = list[LegacyToken]
LegacyBlockIndex: TypeAlias = dict[int, "LegacyBlock"]
LegacyRegisterScope: TypeAlias = dict[bytes, bool]

@dataclass(frozen=True)
class LegacyBlock:
    address: int
    end_address: int
    instructions: tuple[LegacyInstruction, ...]
    successors: tuple[int, ...]
    predecessors: tuple[int, ...]
    depth: int = 0

    def with_instructions(self, instructions: tuple[LegacyInstruction, ...]) -> "LegacyBlock":
        return replace(self, instructions=instructions)


@dataclass(frozen=True)
class LegacyBlockGraph:
    blocks: LegacyBlockIndex
    entry_address: int

    @property
    def start_block(self) -> LegacyBlock:
        return self.block_at(self.entry_address)

    def block_at(self, address: int) -> LegacyBlock:
        return self.blocks[address]

    def addresses(self) -> tuple[int, ...]:
        return tuple(self.blocks.keys())

    def block_items(self) -> tuple[tuple[int, LegacyBlock], ...]:
        return tuple(self.blocks.items())

    def successors(self, address: int) -> tuple[int, ...]:
        return self.block_at(address).successors

    def predecessors(self, address: int) -> tuple[int, ...]:
        return self.block_at(address).predecessors

    def with_block(self, block: LegacyBlock) -> "LegacyBlockGraph":
        blocks = dict(self.blocks)
        blocks[block.address] = block
        return replace(self, blocks=blocks)

    def reachable_order(self) -> list[int]:
        retrace_nodes = [self.entry_address]
        seen: set[int] = set()
        order = []

        while retrace_nodes:
            address = retrace_nodes.pop()
            if address in seen or address not in self.blocks:
                continue
            seen.add(address)
            order.append(address)

            for child in self.successors(address):
                if child not in seen:
                    retrace_nodes.append(child)

        return order


@dataclass(frozen=True)
class LegacyLineSection:
    type: bool
    section: tuple[bytes, ...]


@dataclass(frozen=True)
class LegacyConvertedSection:
    type: bool
    section: tuple[bytes, ...]
    code: tuple[bytes, ...] | None


LegacyTraversalFn: TypeAlias = Callable[[LegacyBlock, LegacyBlockGraph, object], object]
