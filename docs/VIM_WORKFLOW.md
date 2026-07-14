# Vim Integration Workflow

The next version of the Vim integration should treat generated decompiler
output as a view over durable project state. Names, notes, signatures, and AI
suggestions should live in `state.sqlite`, not in generated C files.

## Backend First

`decomp_project.py` is the first small backend for this. It supports:

```bash
python3 decomp_project.py init .decomp/state.sqlite \
  --binary /Volumes/Locker/Synth/DD2.1.0.bin \
  --architecture arm-thumb \
  --base-address 0x08020000 \
  --entry-point 0x080202cc

python3 decomp_project.py rename .decomp/state.sqlite 0x08034f48 system_clock_init
python3 decomp_project.py note .decomp/state.sqlite 0x08034f48 "writes CPACR and RCC registers"
python3 decomp_project.py suggest .decomp/state.sqlite 0x08034f48 function_name clock_tree_init \
  --rationale "touches RCC registers and PLL constants" \
  --confidence 0.7
python3 decomp_project.py list .decomp/state.sqlite
```

The Vim plugin can start by shelling out to this CLI. Later, replace that with
a long-running JSON-RPC server without changing the project data model.

## Proposed Vim Commands

```vim
:DecompProjectOpen .decomp/state.sqlite
:DecompFunction 0x08034f48
:DecompRename system_clock_init
:DecompNote writes CPACR and RCC registers
:DecompAISuggestName
:DecompAcceptSuggestion
:DecompRejectSuggestion
:DecompCallers
:DecompCallees
:DecompXrefs 0x40023800
```

Useful default layout:

- left split: function queue and naming status
- center split: regenerated C-like view
- right split: assembly view
- quickfix list: callers, callees, xrefs, and pending suggestions

## AI Contract

AI suggestions should be recorded as pending evidence, never directly applied.
Each suggestion should include:

- target address
- suggestion kind, such as `function_name`, `summary`, or `signature`
- proposed text
- confidence
- evidence/rationale
- accepted/rejected status

This keeps the human investigation loop intact while making the machine useful.
