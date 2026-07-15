"""Analysis passes over typed decompiler models."""

from .cfg_builder import (
    InstructionSource,
    InstructionsBufferSource,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    cfg_to_legacy_block_graph,
)

__all__ = [
    "InstructionSource",
    "InstructionsBufferSource",
    "LegacyTokenInstructionSource",
    "build_control_flow_graph",
    "cfg_to_legacy_block_graph",
]
