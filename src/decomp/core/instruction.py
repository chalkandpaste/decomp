from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum

from .address import Address, AddressRange
from .flow import FlowInfo


class OperandKind(str, Enum):
    REGISTER = "register"
    IMMEDIATE = "immediate"
    ADDRESS = "address"
    MEMORY = "memory"
    REGISTER_LIST = "register_list"
    LABEL = "label"
    RAW = "raw"


@dataclass(frozen=True)
class Operand:
    kind: OperandKind
    text: str
    value: int | float | str | None = None

    def to_json(self) -> dict[str, object]:
        return {
            "kind": self.kind.value,
            "text": self.text,
            "value": self.value,
        }


@dataclass(frozen=True)
class Instruction:
    address: Address
    size: int
    data: bytes
    mnemonic: str
    operands: tuple[Operand, ...] = ()
    flow: FlowInfo = field(default_factory=FlowInfo)
    raw_tokens: tuple[bytes, ...] = ()
    legacy_tokens: tuple[object, ...] = ()
    source: str = "unknown"

    @property
    def range(self) -> AddressRange:
        return AddressRange(self.address, self.address + self.size)

    def to_json(self) -> dict[str, object]:
        return {
            "address": hex(self.address),
            "size": self.size,
            "bytes": self.data.hex(),
            "mnemonic": self.mnemonic,
            "operands": [operand.to_json() for operand in self.operands],
            "flow": self.flow.to_json(),
            "source": self.source,
        }
