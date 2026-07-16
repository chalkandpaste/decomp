# decomp

`decomp` is a firmware decompilation and reverse-engineering package. It grew
out of a practical ARM Thumb toolchain used on Cortex-M firmware to recover
C-like structure, understand behavior, patch bugs, and rebuild altered
binaries.

The current working backend is ARM Thumb/Cortex-M. The package is being shaped
so other older synth-firmware targets can be added without baking ARM-specific
assumptions into every layer.

## What It Does

- Disassembles firmware bytes through `rasm2`.
- Builds basic blocks and control-flow graphs from a fixed entry point.
- Discovers referenced functions and follows the call graph.
- Infers rough register-based function signatures.
- Structures blocks into C-like `if`, `while`, and jump-table forms.
- Lowers supported instructions into C-like statements.
- Reduces expressions and removes dead register assignments.
- Stores investigation state such as names, notes, and AI suggestions.

This is not a general-purpose production decompiler yet. It is a useful
firmware-analysis tool with an honest roadmap toward more robust packaging,
state management, editor integration, and architecture support.

## Install

Python 3.10+ is required. `rasm2` from radare2 must be available on `PATH`.

```bash
python3 -m pip install -e .
```

On macOS, radare2 can be installed with:

```bash
brew install radare2
```

## Command Line

Run the ARM Thumb pipeline:

```bash
decomp firmware.bin 0x080202cc --output-dir build/demo --max-functions 10
```

The pipeline writes:

- `asm/`: recovered assembly views
- `cf/`: structured control-flow C
- `c/`: lowered/reduced C-like output

`decomp-thumb` is kept as an alias for the same command.

Manage investigation state:

```bash
decomp-project init .decomp/state.sqlite \
  --binary firmware.bin \
  --architecture arm-thumb \
  --base-address 0x08020000 \
  --entry-point 0x080202cc

decomp-project rename .decomp/state.sqlite 0x08034f48 system_clock_init
decomp-project note .decomp/state.sqlite 0x08034f48 "writes CPACR and RCC registers"
decomp-project suggest .decomp/state.sqlite 0x08034f48 function_name clock_tree_init \
  --rationale "touches RCC and PLL constants" \
  --confidence 0.7
decomp-project export-names .decomp/state.sqlite build/names.json
```

List known architecture targets:

```bash
decomp-project architectures
```

Capture/check legacy parity before refactoring internals:

```bash
decomp-parity capture firmware.bin build/parity.json \
  --entry-point 0x080202cc \
  --max-functions 10

decomp-parity check firmware.bin build/parity.json
```

## Package Layout

```text
src/decomp/
  core/                 typed firmware/program/CFG/instruction model
  arch/                 architecture backend interfaces and ARM Thumb scaffold
  analysis/             typed analysis passes such as CFG construction
  cli.py                 main decompiler CLI
  parity.py             legacy parity snapshot capture/check CLI
  legacy_adapter.py     bridge from old dict/list graphs to typed CFGs
  project_cli.py         project-state CLI
  architectures.py       supported/prospective architecture registry
  project_state.py       SQLite project state
  instruction_buffer.py  rasm2 integration and literal reads
  block_graph.py         basic-block discovery and graph traversal
  function_signatures.py function signature heuristics and legacy xref wrapper
  disassemble.py         control-flow structuring
  convert_c.py           instruction-to-C lowering
  reduce_c.py            C AST expression reduction
  liveness.py            dead register-assignment cleanup
```

Legacy interactive mapping helpers live in `src/decomp/legacy/`.

Historical generated outputs from the original workflow are preserved under
`examples/legacy/`. New generated files should go under `build/` or another
ignored work directory.

## Editor Workflow

Generated C and assembly should be treated as disposable views over durable
project state. Names, notes, signatures, and AI suggestions belong in the
project database so a firmware investigation can be resumed later.

See [docs/VIM_WORKFLOW.md](docs/VIM_WORKFLOW.md) for the proposed Vim command
surface and state model.

See [docs/REDESIGN.md](docs/REDESIGN.md) for the typed model, architecture
boundary, and DD2 parity workflow that will guide the real internal refactor.

## Architecture Extensibility

The current backend is `arm-thumb`. Prospective synth-firmware targets are
tracked in [docs/ARCHITECTURES.md](docs/ARCHITECTURES.md):

- Hitachi 63B03 / Motorola 6800-family
- Motorola 68B09E / 6809-family
- Renesas SH7727 / SH-3-DSP
- XMOS XS1-family xCORE

Each architecture will need its own instruction parser, branch/call/return
classifier, calling-convention model, data-flow rules, and startup/vector
discovery.

## Development

Run tests from the repository root with `src` on `PYTHONPATH`:

```bash
PYTHONPATH=src python3 -m unittest discover -s tests -v
```

Compile-check the package:

```bash
PYTHONPATH=src python3 -m py_compile src/decomp/*.py src/decomp/legacy/*.py tests/*.py
```

## Current Limitations

- ARM Thumb is the only implemented architecture backend.
- Several passes still use dict-shaped records instead of typed models.
- Debug output is still noisy in deeper pipeline runs.
- Function-boundary recovery is heuristic and firmware/toolchain-sensitive.
- AI suggestions are stored, but model-backed suggestion generation is not wired
  into the CLI yet.
