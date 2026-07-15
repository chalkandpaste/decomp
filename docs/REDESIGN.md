# Redesign Plan

The old pipeline proved the idea, but its internal representation is too loose:
instructions are byte-token lists, blocks are dicts, and ARM Thumb assumptions
are spread through parsing, graph construction, function discovery, signature
inference, and C lowering.

The cleanup direction is to keep the legacy pipeline as a parity oracle while
new passes move onto typed data structures.

## Core Model

New analysis code should use `decomp.core` structures:

- `FirmwareImage` and `Segment` for addressable firmware bytes.
- `Instruction`, `Operand`, and `FlowInfo` for decoded instructions.
- `BasicBlock`, `Edge`, and `ControlFlowGraph` for function control flow.
- `Function` and `Program` for whole-program analysis state.

These structures make formerly implicit list positions explicit. For example,
branch targets belong in `instruction.flow.targets`, not `insn[4]` or `insn[5]`
depending on mnemonic family.

## Architecture Boundary

Architecture-specific behavior belongs behind `decomp.arch` backends. Core code
should not know about ARM register names, Thumb branch mnemonics, literal-pool
rules, `pop {pc}`, `bx lr`, or STM32 address ranges.

The first backend scaffold is `decomp.arch.arm_thumb.ArmThumbBackend`. It can
currently adapt legacy token lists into typed `Instruction` objects and classify
basic control flow. Future work should move these responsibilities fully out of
the old modules:

- disassembler configuration
- instruction parsing
- branch/call/return classification
- register and flag effects
- ABI/calling-convention rules
- low-level IR lowering
- peripheral and memory-map references

Target-specific artifacts such as STM32F405 peripheral maps and DD2-specific
skip lists should become profile data, not global Python constants.

## Legacy Adapter

`decomp.legacy_adapter` converts the current dict/list block graph into a typed
`ControlFlowGraph`. This is intentionally a bridge, not the final design. It
lets new tests and future passes use the typed model before the old graph builder
is replaced.

## Parity Harness

`decomp-parity` captures and checks structural fingerprints from the legacy
pipeline:

```bash
decomp-parity capture /Volumes/Locker/Synth/DD2.1.0.bin \
  tests/fixtures/dd2_1_0_parity_max10.json \
  --entry-point 0x080202cc \
  --max-functions 10

decomp-parity check /Volumes/Locker/Synth/DD2.1.0.bin \
  tests/fixtures/dd2_1_0_parity_max10.json
```

The snapshot records:

- binary size and SHA-256
- architecture, base address, and entry point
- discovered function order
- per-function status
- calls discovered by the legacy collector
- block starts, ends, instruction counts, incoming edges, and outgoing edges
- current legacy failures

The fixture does not include firmware bytes. The integration test is skipped
when the DD2 binary or `rasm2` is unavailable.

## Refactor Sequence

1. Keep parity snapshots green against known firmware.
2. Move legacy block-graph output through typed adapters.
3. Replace `instruction_buffer.py` with an architecture-backed decoder.
   Initial status: `InstructionsBuffer` is now a compatibility wrapper around
   `ArmThumbBackend`; old callers still receive legacy token lists, while new
   callers can request typed instructions.
4. Replace `block_graph.py` with a typed CFG builder.
5. Replace function discovery with an xref pass over typed instructions.
6. Replace signature inference with backend-provided register/ABI effects.
7. Introduce low-level IR before C emission.
8. Move STM32/DD2-specific assumptions into project profiles.

Any intentional parity drift should update the fixture in the same commit and
explain whether the drift is a bug fix, broader discovery, or a formatting-only
change.
