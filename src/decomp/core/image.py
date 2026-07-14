from __future__ import annotations

from dataclasses import dataclass

from .address import Address, AddressRange


@dataclass(frozen=True)
class Segment:
    name: str
    start: Address
    data: bytes
    permissions: str = "rx"

    @property
    def range(self) -> AddressRange:
        return AddressRange(self.start, self.start + len(self.data))

    def contains(self, address: Address) -> bool:
        return self.range.contains(address)

    def offset_of(self, address: Address) -> int:
        if not self.contains(address):
            raise ValueError(f"{hex(address)} is outside segment {self.name}")
        return address - self.start

    def read(self, address: Address, size: int) -> bytes:
        offset = self.offset_of(address)
        return self.data[offset:offset + size]


@dataclass(frozen=True)
class FirmwareImage:
    segments: tuple[Segment, ...]

    @classmethod
    def flat(cls, data: bytes, *, base_address: Address, name: str = "firmware") -> "FirmwareImage":
        return cls((Segment(name=name, start=base_address, data=data),))

    def segment_for(self, address: Address) -> Segment:
        for segment in self.segments:
            if segment.contains(address):
                return segment
        raise ValueError(f"{hex(address)} is outside all image segments")

    def read(self, address: Address, size: int) -> bytes:
        return self.segment_for(address).read(address, size)
