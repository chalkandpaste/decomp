from __future__ import annotations

from dataclasses import dataclass


Address = int


@dataclass(frozen=True, order=True)
class AddressRange:
    start: Address
    end: Address

    def __post_init__(self):
        if self.end < self.start:
            raise ValueError("address range end must be greater than or equal to start")

    @property
    def size(self) -> int:
        return self.end - self.start

    def contains(self, address: Address) -> bool:
        return self.start <= address < self.end

    def to_json(self) -> dict[str, str | int]:
        return {
            "start": hex(self.start),
            "end": hex(self.end),
            "size": self.size,
        }
