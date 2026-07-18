"""Architecture backends."""

from .arm_thumb import ArmThumbArchitectureBehavior, ArmThumbBackend
from .base import ArchitectureBackend, ArchitectureBehavior, DisassemblerConfig, RegisterEffect


def default_architecture_backend() -> ArchitectureBackend:
    return ArmThumbBackend()


def default_architecture_behavior() -> ArchitectureBehavior:
    return ArmThumbArchitectureBehavior()


__all__ = [
    "ArchitectureBackend",
    "ArchitectureBehavior",
    "ArmThumbArchitectureBehavior",
    "ArmThumbBackend",
    "DisassemblerConfig",
    "RegisterEffect",
    "default_architecture_backend",
    "default_architecture_behavior",
]
