from __future__ import annotations

from collections.abc import Callable
from dataclasses import dataclass, field
from enum import Enum

from .address import Address


class FlowKind(str, Enum):
    FALLTHROUGH = "fallthrough"
    CONDITIONAL_BRANCH = "conditional_branch"
    UNCONDITIONAL_BRANCH = "unconditional_branch"
    CALL = "call"
    RETURN = "return"
    TAIL_CALL = "tail_call"
    INDIRECT_CALL = "indirect_call"
    INDIRECT_BRANCH = "indirect_branch"
    SWITCH = "switch"
    STOP = "stop"
    UNKNOWN = "unknown"


class EdgeKind(str, Enum):
    FALLTHROUGH = "fallthrough"
    TRUE_BRANCH = "true_branch"
    FALSE_BRANCH = "false_branch"
    JUMP = "jump"
    SWITCH_CASE = "switch_case"
    CALL = "call"
    TAIL_CALL = "tail_call"
    UNKNOWN = "unknown"


@dataclass(frozen=True)
class FlowInfo:
    kind: FlowKind = FlowKind.UNKNOWN
    targets: tuple[Address, ...] = ()
    fallthrough: Address | None = None
    is_function_exit: bool = False
    metadata: dict[str, str] = field(default_factory=dict)

    def target_addresses(self, normalize: Callable[[Address], Address] | None = None) -> tuple[Address, ...]:
        if normalize is None:
            return self.targets
        return tuple(normalize(target) for target in self.targets)

    def successor_addresses(self, default_fallthrough: Address) -> tuple[Address, ...]:
        if self.kind == FlowKind.CONDITIONAL_BRANCH:
            if len(self.targets) != 1 or self.fallthrough is None:
                raise ValueError("conditional branch lacks typed target information")
            return (self.targets[0], self.fallthrough)

        if self.kind in {FlowKind.UNCONDITIONAL_BRANCH, FlowKind.SWITCH}:
            return self.targets

        if self.is_function_exit:
            return ()

        return (self.fallthrough if self.fallthrough is not None else default_fallthrough,)

    def to_json(self) -> dict[str, object]:
        return {
            "kind": self.kind.value,
            "targets": [hex(target) for target in self.targets],
            "fallthrough": hex(self.fallthrough) if self.fallthrough is not None else None,
            "is_function_exit": self.is_function_exit,
            "metadata": dict(self.metadata),
        }
