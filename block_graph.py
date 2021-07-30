from instruction_buffer import InstructionsBuffer
from instructions import *

import pickle
import os.path
import argparse

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

    fp = 'bgc/' + hex(entry_point_loc)
    
    if os.path.isfile(fp):
        return pickle.load(open(fp, 'rb'))
    else:
        return None

def cache_bg(entry_point_loc, block_graph):

    # print('caching')
    pickle.dump(block_graph, open('bgc/'+hex(entry_point_loc), 'wb'))

def generate_block_graph(binary, entry_point_loc, use_cache=True, override_input=None):
    print('generate_block_graph', hex(entry_point_loc))

    ## CACHING
    
    cached_bg = check_bg_cache(entry_point_loc)
    if cached_bg is not None and use_cache:
        return cached_bg

    ## END CACHING
    
    if override_input is None:
        insns_buff = InstructionsBuffer(binary, entry_point_loc)
    else:
        insns_buff = override_input

    block_graph = {'index' : {}, 'start_block': None}

    search_locs = [entry_point_loc]

    while len(search_locs) > 0:
        # do code in order, so as to save the buffer
        search_locs.sort()
        search_loc = search_locs.pop(0)

        # print('making block_node', hex(search_loc))

        end_of_function = False
        found_block_end = False
        block = []

        if search_loc not in block_graph['index']:
            if override_input is None:
                insns = insns_buff.read_insns_at_loc(search_loc)
            else:
                try:
                    insns_indexer = {int(insn[0],0) : i for (i,insn) in enumerate(insns_buff)}
                    index = insns_indexer[search_loc]
                    insns = insns_buff[index:]
                except:
                    print(insns_indexer)
                    raise Exception

            for i in range(len(insns)):
                insn = insns[i]
                block.append(insn)
                if insn[3] in block_end:
                    found_block_end = True
                    print('block end', insn)
                    break
                elif insn[3] in func_end + exchange_return:
                    print('func end', insn)
                    end_of_function = True
                    # check
                    # 1. if pop/ldmia contains pc (return immmediate)
                    # 2. if the pop/ldmia contains lr (aka, it exits this function implicitly)
                    #        and the go ahead until pc-altering instruction occurs
                    if b'pc,' in insn[5:] or b'pc}' in insn[4:] or b'{pc}' in insn[4:]:
                        break
                    elif insn[3] == b'bx' and insn[4] == b'lr':
                        break # return void case
                    elif b'lr,' in insn[5:] or b'lr}' in insn[4:]:
                        tail_end = []
                        j = 1
                        while True: 
                            tail_insn = insns[i + j]
                            tail_end.append(tail_insn)
                            if tail_insn[3] in uncond_block_end:
                                break
                            else:
                                j += 1
                        block += tail_end
                        break
                    elif insn[3] == b'pop' and not (b'pc,' in insn[5:] or b'pc}' in insn[4:] or b'{pc}' in insn[4:]) or not (b'lr,' in insn[5:] or b'lr}' in insn[4:]):
                        end_of_function = False
                        pass
                    else:
                        print(insn)
                        print(insns[i+1])
                        print(insns[i+2])
                        ## you could be here because of 1. unexpect case, 2. buffer was not full enough
                        ## and the program didn't reach a pc-altering instruction before reaching
                        ## the buffer end.
                        raise Exception
                else:
                    pass

            if not (found_block_end or end_of_function):
                insns_buff.update_loc(search_loc)
                search_locs.append(search_loc) ## redo with new buffer
                continue

            block_loc = int(block[0][0], 0) # read the first offset
            end_loc = int(block[-1][0],0) + int(block[-1][1])

            if not end_of_function:
                children = get_children(block)
            else:
                children = []

            new_block = mk_block(search_loc, block, end_loc, children)

            if block_graph['start_block'] is None:
                block_graph['start_block'] = new_block

            block_graph['index'][search_loc] = new_block

            for c in children:
                if c not in search_locs:
                    search_locs.append(c)


        else:
            pass
            # as long as we are not going over previously seen segments
            # we are fine and won't loop
            # raise Exception

    # Because we only did a forward pass and some blocks end without a block_end
    # we need to do a backwards pass to trim overlapping blocks

    block_locs = list(block_graph['index'].keys())
    block_locs.sort()
    block_locs.reverse()

    for i in range(0, len(block_locs) - 1):

        curr_block = block_graph['index'][block_locs[i]]
        prev_block = block_graph['index'][block_locs[i + 1]] # we reversed the list

        if curr_block['loc'] < prev_block['end_loc']:
            trimmed_block = []
            for insn in prev_block['block']:
                if int(insn[0], 0) < curr_block['loc']:
                    trimmed_block.append(insn)

            prev_block['children'] = [curr_block['loc']]
            prev_block['end_loc'] = curr_block['loc']
            prev_block['block'] = trimmed_block
            block_graph['index'][block_locs[i + 1]] = prev_block

    # determine parents for each node before we return

    def update_parents(block, _, block_index):
        # print("update_parents", hex(block['loc']))
        # print([hex(c) for c in block['children']])
        for child_loc in block['children']:
            child = block_index[child_loc]

            if block['loc'] not in child['parents']:
                child['parents'].append(block['loc'])
                block_index[child_loc] = child

        return block_index

    block_graph['index'] = recurse_graph(block_graph, update_parents, block_graph['index'], True)

    ## Block cache
    
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
