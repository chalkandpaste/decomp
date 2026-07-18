from __future__ import annotations

from collections.abc import Mapping
from dataclasses import dataclass, replace
from types import MappingProxyType
from typing import Callable, TypeAlias


LegacyToken: TypeAlias = bytes | int | list[int]
LegacyInstruction: TypeAlias = list[LegacyToken]
LegacyBlockIndex: TypeAlias = Mapping[int, "LegacyBlock"]
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

    def __post_init__(self) -> None:
        object.__setattr__(self, "blocks", MappingProxyType(dict(self.blocks)))

    def block_at(self, address: int) -> LegacyBlock:
        return self.blocks[address]

    def has_block(self, address: int) -> bool:
        return address in self.blocks

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

    def reachable_order(
        self,
        start_address: int | None = None,
        direction: bool = True,
        stop_address: int | None = None,
    ) -> tuple[int, ...]:
        start = self.entry_address if start_address is None else start_address
        pop_index = -1 if direction else 0
        retrace_nodes = [start]
        pending = {start}
        seen: set[int] = set()
        order = []

        while retrace_nodes:
            address = retrace_nodes.pop(pop_index)
            pending.remove(address)
            if address in seen or not self.has_block(address):
                continue
            seen.add(address)
            order.append(address)

            for child in self.successors(address):
                if child != stop_address and child not in seen and child not in pending:
                    retrace_nodes.append(child)
                    pending.add(child)

        return tuple(order)


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
