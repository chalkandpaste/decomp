"""Analysis passes over typed decompiler models."""

from .cfg_builder import (
    InstructionSource,
    InstructionsBufferSource,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    cfg_to_legacy_block_graph,
)
from .xrefs import (
    CallReference,
    CallReferenceKind,
    collect_call_references,
    collect_function_addresses,
)

__all__ = [
    "InstructionSource",
    "InstructionsBufferSource",
    "LegacyTokenInstructionSource",
    "build_control_flow_graph",
    "CallReference",
    "CallReferenceKind",
    "cfg_to_legacy_block_graph",
    "collect_call_references",
    "collect_function_addresses",
]
