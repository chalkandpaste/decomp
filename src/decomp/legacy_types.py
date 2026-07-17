from __future__ import annotations

from typing import Any, Callable, TypeAlias


LegacyToken: TypeAlias = bytes | int | list[int]
LegacyInstruction: TypeAlias = list[LegacyToken]
LegacyBlock: TypeAlias = dict[str, Any]
LegacyBlockIndex: TypeAlias = dict[int, LegacyBlock]
LegacyBlockGraph: TypeAlias = dict[str, Any]
LegacySection: TypeAlias = dict[str, Any]
LegacyScope: TypeAlias = dict[str, Any]
LegacyRegisterScope: TypeAlias = dict[bytes, bool]
LegacyTraversalFn: TypeAlias = Callable[[LegacyBlock, LegacyBlockIndex, Any], Any]
