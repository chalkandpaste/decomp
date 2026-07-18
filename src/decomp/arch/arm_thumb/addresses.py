from __future__ import annotations

from decomp.core.address import Address


def normalize_interworking_address(address: Address) -> Address:
    return address & ~1
