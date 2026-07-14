from __future__ import annotations

from dataclasses import dataclass, field

from .address import Address, AddressRange
from .flow import EdgeKind
from .instruction import Instruction


@dataclass(frozen=True)
class Edge:
    source: Address
    target: Address
    kind: EdgeKind = EdgeKind.UNKNOWN

    def to_json(self) -> dict[str, str]:
        return {
            "source": hex(self.source),
            "target": hex(self.target),
            "kind": self.kind.value,
        }


@dataclass(frozen=True)
class BasicBlock:
    address: Address
    end: Address
    instructions: tuple[Instruction, ...]
    outgoing: tuple[Edge, ...] = ()
    incoming: tuple[Edge, ...] = ()
    depth: int = 0

    @property
    def range(self) -> AddressRange:
        return AddressRange(self.address, self.end)

    def to_json(self) -> dict[str, object]:
        return {
            "address": hex(self.address),
            "end": hex(self.end),
            "instruction_count": len(self.instructions),
            "outgoing": [edge.to_json() for edge in self.outgoing],
            "incoming": [edge.to_json() for edge in self.incoming],
            "instructions": [instruction.to_json() for instruction in self.instructions],
        }


@dataclass(frozen=True)
class ControlFlowGraph:
    entry: Address
    blocks: dict[Address, BasicBlock] = field(default_factory=dict)

    def block_starts(self) -> tuple[Address, ...]:
        return tuple(sorted(self.blocks))

    def edges(self) -> tuple[Edge, ...]:
        return tuple(
            edge
            for block in self.blocks.values()
            for edge in block.outgoing
        )

    def to_json(self) -> dict[str, object]:
        return {
            "entry": hex(self.entry),
            "block_count": len(self.blocks),
            "blocks": [
                self.blocks[address].to_json()
                for address in sorted(self.blocks)
            ],
        }
