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

    def block_at(self, address: Address) -> BasicBlock:
        return self.blocks[address]

    def has_block(self, address: Address) -> bool:
        return address in self.blocks

    def block_starts(self) -> tuple[Address, ...]:
        return tuple(sorted(self.blocks))

    def block_items(self) -> tuple[tuple[Address, BasicBlock], ...]:
        return tuple(self.blocks.items())

    def with_block(self, block: BasicBlock) -> "ControlFlowGraph":
        blocks = dict(self.blocks)
        blocks[block.address] = block
        return ControlFlowGraph(entry=self.entry, blocks=blocks)

    def successors(self, address: Address) -> tuple[Address, ...]:
        return tuple(edge.target for edge in self.block_at(address).outgoing)

    def predecessors(self, address: Address) -> tuple[Address, ...]:
        return tuple(edge.source for edge in self.block_at(address).incoming)

    def reachable_order(
        self,
        start_address: Address | None = None,
        direction: bool = True,
        stop_address: Address | None = None,
    ) -> tuple[Address, ...]:
        start = self.entry if start_address is None else start_address
        pop_index = -1 if direction else 0
        retrace_nodes = [start]
        pending = {start}
        seen: set[Address] = set()
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

    def edges(self) -> tuple[Edge, ...]:
        return tuple(
            edge
            for _address, block in self.block_items()
            for edge in block.outgoing
        )

    def to_json(self) -> dict[str, object]:
        return {
            "entry": hex(self.entry),
            "block_count": len(self.blocks),
            "blocks": [
                self.block_at(address).to_json()
                for address in self.block_starts()
            ],
        }
