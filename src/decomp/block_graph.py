from .instruction_buffer import InstructionsBuffer
from .analysis.cfg_builder import (
    InstructionsBufferSource,
    LegacyTokenInstructionSource,
    build_control_flow_graph,
    cfg_to_legacy_block_graph,
)
from .legacy_types import (
    LegacyBlockGraph,
    LegacyInstruction,
    LegacyTraversalFn,
)

import pickle
import os.path

CACHE_VERSION = 4

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
