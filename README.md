# decomp

`decomp` is a personal ARM Thumb decompilation toolchain. I used it on
Cortex-M firmware to recover enough C-like structure to understand behavior,
patch bugs, and rebuild altered binaries.

It is not a general-purpose production decompiler. The code is intentionally
biased toward the firmware I was working on, especially STM32F405-era Cortex-M4
Thumb code and the calling/branching patterns emitted by GCC. Within those
constraints, the tool is useful: it discovers functions from an entry point,
builds control-flow graphs, structures basic blocks, lowers instructions into
C-like statements, and applies simple expression/liveness cleanup.

## Pipeline

The main driver is `decompile.py`. Given a binary and a fixed entry point, it:

1. Disassembles Thumb instructions with `rasm2`.
2. Builds basic blocks and control-flow edges.
3. Finds referenced functions and repeats the walk.
4. Infers rough function signatures from register use.
5. Structures blocks into `if`, `while`, and jump-table forms.
6. Converts instruction comments into C-like statements.
7. Reduces expressions and removes dead register assignments.

The important modules are:

- `instruction_buffer.py`: buffered `rasm2` disassembly plus literal-pool reads.
- `block_graph.py`: basic-block discovery and graph traversal.
- `function_signatures.py`: call discovery and ABI-ish signature inference.
- `disassemble.py`: control-flow structuring into meta-blocks.
- `convert_c.py`: instruction-to-C lowering.
- `reduce_c.py` and `liveness.py`: C AST cleanup passes using `pycparser`.

## Requirements

- Python 3.10+
- `pycparser`
- `rasm2` from radare2 on `PATH`

Install Python dependencies with:

```bash
python3 -m pip install -e .
```

Install radare2 separately for your platform.

## Usage

```bash
python3 decompile.py firmware.bin 0x08020004
```

The full pipeline writes disassembly, control-flow C, and reduced C into
`asm/`, `cf/`, and `c/` under the selected output directory. Those directories
are created automatically.

```bash
python3 decompile.py firmware.bin 0x08020004 --output-dir build/demo
```

After an editable install, the same driver is available as:

```bash
decomp-thumb firmware.bin 0x08020004 --output-dir build/demo
```

For smoke tests on real firmware, cap recursive discovery:

```bash
python3 decompile.py firmware.bin 0x080202cc --output-dir build/smoke --max-functions 10
```

For smaller stages:

```bash
python3 block_graph.py input.s output.s 0x08020004
python3 disassemble.py firmware.bin output.c 0x08020004
python3 convert_c.py control_flow.c lowered.c
```

## Current Limitations

- The disassembler integration is tied to `rasm2 -a arm.gnu -b 16 -c m4`.
- Function skipping and some address assumptions are currently hard-coded.
- Error handling still reflects exploratory use: many unsupported cases raise
  generic exceptions with nearby instruction dumps.
- The control-flow structurer assumes compiler-shaped code and can fail on
  irreducible or hand-written assembly.
- Generated outputs and scratch artifacts have historically lived beside the
  source; new transient outputs are ignored while the old examples are kept for
  reference.

## Cleanup Roadmap

1. Keep behavior stable while adding tests around known instruction-lowering
   and literal-handling edge cases.
2. Replace hard-coded output paths with CLI options and automatic directory
   creation.
3. Move source into a package, keeping the old script entry points as wrappers.
4. Replace dict-shaped graph records with typed objects once tests cover the
   pipeline.
5. Turn noisy debug prints and broad exceptions into logging plus contextual
   errors.
6. Add small shareable fixtures so the repo demonstrates the tool without
   depending on private firmware.

## Investigation Workflow

The direction for editor integration is to treat generated C and assembly as
views over project state. Function names, signatures, notes, and AI suggestions
should be stored durably so a firmware investigation can be resumed later.

Start a state database with:

```bash
python3 decomp_project.py init .decomp/state.sqlite \
  --binary firmware.bin \
  --architecture arm-thumb \
  --base-address 0x08020000 \
  --entry-point 0x080202cc
```

Then record naming work:

```bash
python3 decomp_project.py rename .decomp/state.sqlite 0x08034f48 system_clock_init
python3 decomp_project.py note .decomp/state.sqlite 0x08034f48 "writes CPACR and RCC registers"
```

See `docs/VIM_WORKFLOW.md` for the proposed Vim command surface and
`docs/ARCHITECTURES.md` for the architecture-extensibility plan.
