# Architecture Extensibility

The current implementation is ARM Thumb-specific, but synth firmware work will
benefit from a pluggable architecture layer. `src/decomp/architectures.py`
records the first target list and the feasibility notes.

## Current Target

`arm-thumb`

- Existing implementation target.
- Uses `rasm2 -a arm.gnu -b 16`.
- Needs ARM-specific instruction tables moved behind an architecture interface.

## Prospective Synth Targets

`m6800-6303`

- Hitachi 63B03 / Motorola 6800-family firmware.
- Local radare2 exposes `m680x`, but the exact 6303 dialect must be validated.
- Needs 8-bit accumulator/index-register data-flow and reset/vector parsing.

`m6809e`

- Motorola 68B09E / 6809-family firmware.
- Local radare2 exposes `m680x`, likely the first backend to test.
- Needs A/B/D, X/Y, U/S, DP, CC modeling and project-specific calling convention
  profiles.

`sh3-dsp`

- Renesas SH7727 / SH-3-DSP.
- Local radare2 exposes `sh` and `sh.cs`, but SH-3-DSP instruction coverage,
  delay slots, and endian behavior need validation.
- Needs delay-slot-aware block construction.

`xcore-xs1`

- XMOS XS1-family xCORE.
- Local radare2 exposes `xcore` through Capstone.
- Needs a different analysis model for threads, channels, and resource side
  effects.

## Interface To Extract

Each architecture should eventually provide:

- disassembler command/configuration
- instruction parser
- branch/call/return classification
- function-entry discovery
- ABI/calling-convention rules
- register and flag data-flow model
- vector/startup discovery
- memory map and peripheral symbol packs

Once that exists, the current ARM Thumb pipeline becomes one implementation of
the shared decompiler workflow rather than the workflow itself.
