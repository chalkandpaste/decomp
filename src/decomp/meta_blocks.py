from __future__ import annotations

from collections.abc import Sequence
from dataclasses import dataclass
from typing import TypeAlias

from .legacy_types import LegacyBlock, LegacyBlockGraph, LegacyBlockIndex


Address: TypeAlias = int


@dataclass(frozen=True)
class IfBlock:
    address: Address
    condition_blocks: tuple[Address, ...]
    flags: tuple[bool, ...]
    conjunctions: tuple[bytes, ...]
    true_address: Address | None
    false_address: Address | None
    next_address: Address | None

    def __post_init__(self) -> None:
        object.__setattr__(self, "condition_blocks", tuple(self.condition_blocks))
        object.__setattr__(self, "flags", tuple(self.flags))
        object.__setattr__(self, "conjunctions", tuple(self.conjunctions))


@dataclass(frozen=True)
class WhileBlock:
    address: Address
    inner: "MetaBlock | None"
    condition_address: Address
    next_address: Address | None


@dataclass(frozen=True)
class LinearBlock:
    address: Address
    block_addresses: tuple[Address, ...]
    next_address: Address | None

    def __post_init__(self) -> None:
        object.__setattr__(self, "block_addresses", tuple(self.block_addresses))


@dataclass(frozen=True)
class SwitchBlock:
    address: Address
    preface: tuple[Address, ...]
    cases: tuple[Address, ...]
    next_address: Address | None

    def __post_init__(self) -> None:
        object.__setattr__(self, "preface", tuple(self.preface))
        object.__setattr__(self, "cases", tuple(self.cases))


@dataclass(frozen=True)
class EndBlock:
    address: Address
    block_addresses: tuple[Address, ...]

    def __post_init__(self) -> None:
        object.__setattr__(self, "block_addresses", tuple(self.block_addresses))


MetaBlock: TypeAlias = IfBlock | WhileBlock | LinearBlock | SwitchBlock | EndBlock
MetaBlockIndex: TypeAlias = dict[Address, MetaBlock]


@dataclass(init=False)
class MetaBlockGraph:
    source_blocks: LegacyBlockIndex
    meta_blocks: MetaBlockIndex
    entry_address: Address

    def __init__(
        self,
        source_blocks: LegacyBlockIndex | None = None,
        meta_blocks: MetaBlockIndex | None = None,
        entry_address: Address | None = None,
        block_index: LegacyBlockIndex | None = None,
    ) -> None:
        if source_blocks is None:
            if block_index is None:
                raise TypeError("MetaBlockGraph requires source_blocks")
            source_blocks = block_index
        elif block_index is not None:
            raise TypeError("pass source_blocks, not both source_blocks and block_index")
        if meta_blocks is None:
            raise TypeError("MetaBlockGraph requires meta_blocks")
        if entry_address is None:
            raise TypeError("MetaBlockGraph requires entry_address")

        self.source_blocks = source_blocks
        self.meta_blocks = meta_blocks
        self.entry_address = entry_address

    @classmethod
    def from_legacy_graph(
        cls,
        block_graph: LegacyBlockGraph,
        meta_blocks: MetaBlockIndex,
        entry_address: Address,
    ) -> "MetaBlockGraph":
        return cls(
            source_blocks=dict(block_graph.block_items()),
            meta_blocks=meta_blocks,
            entry_address=entry_address,
        )

    def block_at(self, address: Address) -> MetaBlock:
        return self.meta_blocks[address]

    def with_block(self, block: MetaBlock) -> "MetaBlockGraph":
        meta_blocks = dict(self.meta_blocks)
        meta_blocks[block.address] = block
        return MetaBlockGraph(
            source_blocks=self.source_blocks,
            meta_blocks=meta_blocks,
            entry_address=self.entry_address,
        )

    def source_block_at(self, address: Address) -> LegacyBlock:
        return self.source_blocks[address]

    def source_blocks_at(self, addresses: Sequence[Address]) -> tuple[LegacyBlock, ...]:
        return tuple(self.source_block_at(address) for address in addresses)
