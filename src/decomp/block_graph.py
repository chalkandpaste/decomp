from .instruction_buffer import InstructionsBuffer
from .instructions import *
from .analysis.cfg_builder import (
    InstructionsBufferSource,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    cfg_to_legacy_block_graph,
)
from .legacy_types import (
    LegacyBlock,
    LegacyBlockGraph,
    LegacyInstruction,
    LegacyTraversalFn,
)
from .legacy_instruction import mnemonic, next_instruction_address, operand_int, table_targets

import pickle
import os.path
import argparse

CACHE_VERSION = 4

# type block_graph
# {
# 'index' : block_index,
# 'start_node' : block
# }

# type block_index
# {
# location1 : block1,
# ...
# }

# type block
# {
# 'offset_loc' : offset_loc,
# 'block' : block_instructions,
# 'children' : [child_loc1,..],
# 'parent' : parent_loc'
# '
# }

# type block_instructions
# {
# location1 : block1,
# ...
# }

def get_children(block_list: list[LegacyInstruction]) -> list[int]:
    last_insn = block_list[-1]
    end_insn = mnemonic(last_insn)
    if end_insn in cond_block_end:
        jump_loc = operand_int(last_insn, 0)
        next_block_loc = next_instruction_address(last_insn)

        false_loc = next_block_loc
        true_loc = jump_loc

        children = [true_loc, false_loc]

    elif end_insn in cond_block_end_zero:
        jump_loc = operand_int(last_insn, 1)
        next_block_loc = next_instruction_address(last_insn)

        false_loc = next_block_loc
        true_loc = jump_loc

        children = [true_loc, false_loc]

    elif end_insn in uncond_block_end:
        jump_loc = operand_int(last_insn, 0)
        children = [jump_loc]

    elif end_insn in tbb:
        children = table_targets(last_insn)

    else:
        child_loc = next_instruction_address(last_insn)
        children = [child_loc]

    return children

def mk_block(
    loc: int,
    block: list[LegacyInstruction],
    end_loc: int,
    children: list[int] | None = None,
    parents: list[int] | None = None,
) -> LegacyBlock:
    if children is None:
        children = []
    if parents is None:
        parents = []
    return LegacyBlock(
            address=loc,
            end_address=end_loc,
            instructions=tuple(block),
            successors=tuple(children),
            predecessors=tuple(parents),
            depth=0,
            )

def recurse_graph(block_graph: LegacyBlockGraph, f: LegacyTraversalFn, base_case: object, direction: bool) -> object:
    return recurse_blocks(block_graph, block_graph.entry_address, f, base_case, direction)

def recurse_blocks(
    block_graph: LegacyBlockGraph,
    start_address: int,
    f: LegacyTraversalFn,
    base_case: object,
    direction: bool,
) -> object:

    out = base_case

    retrace_nodes = [block_graph.block_at(start_address)]

    # mark them false as we proceed through, faster than lists
    tally = { i : True for i in block_graph.addresses() }

    direction = -1 if direction else 0

    while len(retrace_nodes) > 0:
        curr_block = retrace_nodes.pop(direction)
        children = [block_graph.block_at(i) for i in curr_block.successors]

        tally[curr_block.address] = False # visited

        # do thing
        out = f(curr_block, block_graph, out)

    
        # get it ready for the next iteration

        for c in children:
            if tally[c.address]: # if it hasn't been visited
                retrace_nodes.append(c) # push

    return out

def check_bg_cache(entry_point_loc: int) -> LegacyBlockGraph | None:

    fp = 'bgc/v' + str(CACHE_VERSION) + '-' + hex(entry_point_loc)
    
    if os.path.isfile(fp):
        with open(fp, 'rb') as handle:
            return pickle.load(handle)
    else:
        return None

def cache_bg(entry_point_loc: int, block_graph: LegacyBlockGraph) -> None:

    # print('caching')
    os.makedirs('bgc', exist_ok=True)
    fp = 'bgc/v' + str(CACHE_VERSION) + '-' + hex(entry_point_loc)
    with open(fp, 'wb') as handle:
        pickle.dump(block_graph, handle)

def generate_block_graph(
    binary: bytes | None,
    entry_point_loc: int,
    use_cache: bool = True,
    override_input: list[LegacyInstruction] | None = None,
) -> LegacyBlockGraph:
    print('generate_block_graph', hex(entry_point_loc))

    if use_cache:
        cached_bg = check_bg_cache(entry_point_loc)
        if cached_bg is not None:
            return cached_bg

    if override_input is None:
        source = InstructionsBufferSource(InstructionsBuffer(binary, entry_point_loc))
    else:
        source = LegacyTokenInstructionSource(override_input)

    cfg = build_control_flow_graph(source, entry_point_loc)
    block_graph = cfg_to_legacy_block_graph(cfg)
    
    if use_cache and override_input is None:
        cache_bg(entry_point_loc, block_graph)

    return block_graph

def print_block_graph(block_graph: LegacyBlockGraph) -> bytes:
    locs = list(block_graph.addresses())

    locs.sort()

    out = []

    for l in locs:
        block = block_graph.block_at(l).instructions
        out += block

    out2 = []

    for i in out:
        insn = []
        for j in i:
            if isinstance(j, bytes):
                insn.append(j)
            elif isinstance(j, list):
                j = [bytes(hex(c), 'utf-8') for c in j]
                insn.append(b', '.join(j))
        out2.append(b' '.join(insn))
    
    return b'\n'.join(out2)

def generate_asm(
    binary: bytes | None,
    entry_point_loc: int,
    cache: bool = True,
    override: list[LegacyInstruction] | None = None,
) -> bytes:

    block_graph = generate_block_graph(binary, entry_point_loc, cache, override)

    return print_block_graph(block_graph)

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")
    parser.add_argument('entry_loc', metavar='e', type=str, help="entry_loc")
    # parser.add_argument('func_loc', metavar='f', type=int, help="location to decompile")

    args = parser.parse_args()

    entry_loc = int(args.entry_loc, 0)

    f = open(args.input_file, 'rb')

    override_input = [l.split(b' ') for l in f.read().split(b'\n')]
    override_input = [l for l in override_input if l != [ b'' ]]
    override_input2 = []
    for l in override_input:
        if l[3] == b'tbb':
            insn = l[0:6]
            locs = [int(i.rstrip(b','),0) for i in l[6:-1]]
            insn.append(locs)

            print(insn)
        else:
            insn = l

        override_input2.append(insn)

    override_input = override_input2

    f.close()

    output = generate_asm( None, entry_loc, False, override_input)

    g = open(args.output_file, 'wb')

    g.write(output)
