from __future__ import annotations

from dataclasses import dataclass
from typing import TypeAlias

from .legacy_types import LegacyBlock, LegacyBlockIndex


Address: TypeAlias = int


@dataclass
class IfBlock:
    address: Address
    condition_blocks: list[Address]
    flags: list[bool]
    conjunctions: list[bytes]
    true_address: Address | None
    false_address: Address | None
    next_address: Address | None


@dataclass
class WhileBlock:
    address: Address
    inner: "MetaBlock | None"
    condition_address: Address
    next_address: Address | None


@dataclass
class LinearBlock:
    address: Address
    block_addresses: list[Address]
    next_address: Address | None


@dataclass
class SwitchBlock:
    address: Address
    preface: list[Address]
    cases: tuple[Address, ...]
    next_address: Address | None


@dataclass
class EndBlock:
    address: Address
    block_addresses: list[Address]


MetaBlock: TypeAlias = IfBlock | WhileBlock | LinearBlock | SwitchBlock | EndBlock
MetaBlockIndex: TypeAlias = dict[Address, MetaBlock]


@dataclass
class MetaBlockGraph:
    block_index: LegacyBlockIndex
    meta_blocks: MetaBlockIndex
    entry_address: Address

    def block_at(self, address: Address) -> MetaBlock:
        return self.meta_blocks[address]

    def source_block_at(self, address: Address) -> LegacyBlock:
        return self.block_index[address]

    def source_blocks_at(self, addresses: list[Address] | tuple[Address, ...]) -> tuple[LegacyBlock, ...]:
        return tuple(self.source_block_at(address) for address in addresses)
