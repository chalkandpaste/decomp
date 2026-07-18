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

    def as_register(self) -> str | None:
        if isinstance(self.value, str):
            return self.value

        normalized = self.text.strip(",]")
        if _looks_like_register(normalized):
            return normalized
        return None

    def as_int(self) -> int | None:
        if isinstance(self.value, int):
            return self.value

        try:
            return int(self.text.strip(",]"), 0)
        except ValueError:
            return None

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

    def operand_at(self, index: int) -> Operand | None:
        if index >= len(self.operands):
            return None
        return self.operands[index]

    def operand_register(self, index: int) -> str | None:
        operand = self.operand_at(index)
        if operand is None:
            return None
        return operand.as_register()

    def operand_int(self, index: int) -> int | None:
        operand = self.operand_at(index)
        if operand is None:
            return None
        return operand.as_int()

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


def _looks_like_register(text: str) -> bool:
    if text in {"sp", "lr", "pc"}:
        return True
    return len(text) > 1 and text[0] in {"r", "s", "d"} and text[1:].isdigit()
