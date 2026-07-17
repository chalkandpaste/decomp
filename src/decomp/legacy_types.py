from __future__ import annotations

from typing import Callable, Literal, NamedTuple, TypeAlias


LegacyToken: TypeAlias = bytes | int | list[int]
LegacyInstruction: TypeAlias = list[LegacyToken]
LegacyBlockIndex: TypeAlias = dict[int, "LegacyBlock"]
LegacyRegisterScope: TypeAlias = dict[bytes, bool]

LegacyBlockKey: TypeAlias = Literal["loc", "end_loc", "block", "children", "parents", "depth"]
LegacyBlockValue: TypeAlias = int | list[LegacyInstruction] | list[int]
LegacyBlockGraphKey: TypeAlias = Literal["index", "start_block"]
LegacyLineSectionKey: TypeAlias = Literal["type", "section"]
LegacyConvertedSectionKey: TypeAlias = Literal["type", "section", "code"]


class LegacyBlock(NamedTuple):
    loc: int
    end_loc: int
    block: list[LegacyInstruction]
    children: list[int]
    parents: list[int]
    depth: int = 0

    def __getitem__(self, key: int | LegacyBlockKey) -> object:
        if isinstance(key, str):
            return getattr(self, key)
        return tuple.__getitem__(self, key)

    def __contains__(self, key: object) -> bool:
        if isinstance(key, str):
            return key in self._fields
        return tuple.__contains__(self, key)

    def get(self, key: LegacyBlockKey, default: object | None = None) -> object:
        if key in self:
            return getattr(self, key)
        return default


class LegacyBlockGraph(NamedTuple):
    index: LegacyBlockIndex
    start_block: LegacyBlock

    def __getitem__(self, key: int | LegacyBlockGraphKey) -> object:
        if isinstance(key, str):
            return getattr(self, key)
        return tuple.__getitem__(self, key)

    def __contains__(self, key: object) -> bool:
        if isinstance(key, str):
            return key in self._fields
        return tuple.__contains__(self, key)

    def get(self, key: LegacyBlockGraphKey, default: object | None = None) -> object:
        if key in self:
            return getattr(self, key)
        return default


class LegacyLineSection(NamedTuple):
    type: bool
    section: list[bytes]

    def __getitem__(self, key: int | LegacyLineSectionKey) -> object:
        if isinstance(key, str):
            return getattr(self, key)
        return tuple.__getitem__(self, key)

    def __contains__(self, key: object) -> bool:
        if isinstance(key, str):
            return key in self._fields
        return tuple.__contains__(self, key)


class LegacyConvertedSection(NamedTuple):
    type: bool
    section: list[bytes]
    code: list[bytes] | None

    def __getitem__(self, key: int | LegacyConvertedSectionKey) -> object:
        if isinstance(key, str):
            return getattr(self, key)
        return tuple.__getitem__(self, key)

    def __contains__(self, key: object) -> bool:
        if isinstance(key, str):
            return key in self._fields
        return tuple.__contains__(self, key)


LegacyTraversalFn: TypeAlias = Callable[[LegacyBlock, LegacyBlockIndex, object], object]
