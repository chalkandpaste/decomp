from __future__ import annotations

from dataclasses import dataclass, replace
from typing import Callable, Literal, TypeAlias


LegacyToken: TypeAlias = bytes | int | list[int]
LegacyInstruction: TypeAlias = list[LegacyToken]
LegacyBlockIndex: TypeAlias = dict[int, "LegacyBlock"]
LegacyRegisterScope: TypeAlias = dict[bytes, bool]

LegacyBlockKey: TypeAlias = Literal["loc", "end_loc", "block", "children", "parents", "depth"]
LegacyBlockGraphKey: TypeAlias = Literal["index", "start_block"]
LegacyLineSectionKey: TypeAlias = Literal["type", "section"]
LegacyConvertedSectionKey: TypeAlias = Literal["type", "section", "code"]


@dataclass(frozen=True)
class LegacyBlock:
    address: int
    end_address: int
    instructions: tuple[LegacyInstruction, ...]
    successors: tuple[int, ...]
    predecessors: tuple[int, ...]
    depth: int = 0

    @property
    def loc(self) -> int:
        return self.address

    @property
    def end_loc(self) -> int:
        return self.end_address

    @property
    def block(self) -> tuple[LegacyInstruction, ...]:
        return self.instructions

    @property
    def children(self) -> tuple[int, ...]:
        return self.successors

    @property
    def parents(self) -> tuple[int, ...]:
        return self.predecessors

    def with_instructions(self, instructions: tuple[LegacyInstruction, ...]) -> "LegacyBlock":
        return replace(self, instructions=instructions)

    def __getitem__(self, key: LegacyBlockKey) -> object:
        return getattr(self, key)

    def __contains__(self, key: object) -> bool:
        return isinstance(key, str) and hasattr(self, key)

    def get(self, key: LegacyBlockKey, default: object | None = None) -> object:
        if key in self:
            return getattr(self, key)
        return default


@dataclass(frozen=True)
class LegacyBlockGraph:
    blocks: LegacyBlockIndex
    entry_address: int

    @property
    def index(self) -> LegacyBlockIndex:
        return self.blocks

    @property
    def start_block(self) -> LegacyBlock:
        return self.block_at(self.entry_address)

    def block_at(self, address: int) -> LegacyBlock:
        return self.blocks[address]

    def addresses(self) -> tuple[int, ...]:
        return tuple(self.blocks.keys())

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

    def __getitem__(self, key: LegacyBlockGraphKey) -> object:
        return getattr(self, key)

    def __contains__(self, key: object) -> bool:
        return isinstance(key, str) and hasattr(self, key)

    def get(self, key: LegacyBlockGraphKey, default: object | None = None) -> object:
        if key in self:
            return getattr(self, key)
        return default


@dataclass(frozen=True)
class LegacyLineSection:
    type: bool
    section: tuple[bytes, ...]

    def __getitem__(self, key: LegacyLineSectionKey) -> object:
        return getattr(self, key)

    def __contains__(self, key: object) -> bool:
        return isinstance(key, str) and hasattr(self, key)


@dataclass(frozen=True)
class LegacyConvertedSection:
    type: bool
    section: tuple[bytes, ...]
    code: tuple[bytes, ...] | None

    def __getitem__(self, key: LegacyConvertedSectionKey) -> object:
        return getattr(self, key)

    def __contains__(self, key: object) -> bool:
        return isinstance(key, str) and hasattr(self, key)


LegacyTraversalFn: TypeAlias = Callable[[LegacyBlock, LegacyBlockGraph, object], object]
