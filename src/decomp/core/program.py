from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum

from .address import Address
from .cfg import ControlFlowGraph


class FunctionStatus(str, Enum):
    DISCOVERED = "discovered"
    ANALYZED = "analyzed"
    NAMED = "named"
    FAILED = "failed"


@dataclass(frozen=True)
class Function:
    address: Address
    cfg: ControlFlowGraph | None = None
    calls: frozenset[Address] = frozenset()
    name: str | None = None
    signature: str | None = None
    status: FunctionStatus = FunctionStatus.DISCOVERED

    def to_json(self) -> dict[str, object]:
        return {
            "address": hex(self.address),
            "name": self.name,
            "signature": self.signature,
            "status": self.status.value,
            "calls": [hex(call) for call in sorted(self.calls)],
            "cfg": self.cfg.to_json() if self.cfg is not None else None,
        }


@dataclass(frozen=True)
class Program:
    architecture: str
    entry_point: Address
    functions: dict[Address, Function] = field(default_factory=dict)

    def to_json(self) -> dict[str, object]:
        return {
            "architecture": self.architecture,
            "entry_point": hex(self.entry_point),
            "functions": [
                self.functions[address].to_json()
                for address in sorted(self.functions)
            ],
        }
