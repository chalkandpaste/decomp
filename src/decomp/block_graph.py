from .instruction_buffer import InstructionsBuffer
from .instructions import *
from .analysis.cfg_builder import (
    InstructionsBufferSource,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    cfg_to_legacy_block_graph,
)

import pickle
import os.path
import argparse

CACHE_VERSION = 3

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

def get_children(block_list):
    last_insn = block_list[-1]
    end_insn = last_insn[3]
    if end_insn in cond_block_end:
        jump_loc = int(last_insn[4], 0)
        next_block_loc = int(last_insn[0],0) + int(last_insn[1])

        false_loc = next_block_loc
        true_loc = jump_loc

        children = [true_loc, false_loc]

    elif end_insn in cond_block_end_zero:
        jump_loc = int(last_insn[5], 0)

        next_block_loc = int(last_insn[0],0) + int(last_insn[1])

        false_loc = next_block_loc
        true_loc = jump_loc

        children = [true_loc, false_loc]

    elif end_insn in uncond_block_end:
        jump_loc = int(last_insn[4], 0)
        children = [jump_loc]

    elif end_insn in tbb:
        children = last_insn[-1]

    else:
        child_loc = int(last_insn[0],0) + int(last_insn[1])
        children = [child_loc]

    return children

def mk_block(loc, block, end_loc, children = [], parents = []):
    return {
            'loc'        : loc,
            'end_loc'    : end_loc,
            'block'      : block,
            'children'   : children,
            'parents'    : [], # parents
            'depth'      : 0
            }

def recurse_graph(block_graph, f, base_case, direction):
    start_block = block_graph['start_block']
    block_index = block_graph['index']
    return recurse_blocks(start_block, block_index, f, base_case, direction)

def recurse_blocks(block, block_index, f, base_case, direction):

    out = base_case

    retrace_nodes = [block]

    # mark them false as we proceed through, faster than lists
    tally = { i : True for i in block_index }

    direction = -1 if direction else 0

    while len(retrace_nodes) > 0:
        curr_block = retrace_nodes.pop(direction)
        children = [block_index[i] for i in curr_block['children']]

        tally[curr_block['loc']] = False # visited

        # do thing
        out = f(curr_block, block_index, out)

    
        # get it ready for the next iteration

        for c in children:
            if tally[c['loc']]: # if it hasn't been visited
                retrace_nodes.append(c) # push

    return out

def check_bg_cache(entry_point_loc):

    fp = 'bgc/v' + str(CACHE_VERSION) + '-' + hex(entry_point_loc)
    
    if os.path.isfile(fp):
        with open(fp, 'rb') as handle:
            return pickle.load(handle)
    else:
        return None

def cache_bg(entry_point_loc, block_graph):

    # print('caching')
    os.makedirs('bgc', exist_ok=True)
    fp = 'bgc/v' + str(CACHE_VERSION) + '-' + hex(entry_point_loc)
    with open(fp, 'wb') as handle:
        pickle.dump(block_graph, handle)

def generate_block_graph(binary, entry_point_loc, use_cache=True, override_input=None):
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

def print_block_graph(block_graph):
    block_index = block_graph['index']

    locs = [k for k in block_index.keys()]

    locs.sort()

    out = []

    for l in locs:
        block = block_index[l]['block']
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

def generate_asm(binary, entry_point_loc, cache=True, override=None):

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
