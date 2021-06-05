import argparse
import subprocess


def disassemble_section(section_bytes):
    cmd = [ b'rasm2',
            b'-a', b'arm.gnu', ## only disassembly that works
            b'-b', b'16', ## bit == thumb
            b'-c', b'm4', ## cpu set
            b'-d',        ## disassemble
            b'-D',        ## give me location information and stuff
            section_bytes
            ]
    command_result = subprocess.run(cmd, capture_output=True)
    return command_result.stdout

def fix_jump_offset(jump_offset):
    if int(jump_offset, 0) > 0x7FFFFFF:
        jump_offset = twos_complement(jump_offset)
    else:
        jump_offset = int(jump_offset, 0)

    return jump_offset

def twos_complement(hexstr):
    bits = len(hexstr[2:]) * 4
    value = int(hexstr, 0)
    if value & (1 << (bits-1)):
        value -= 1 << bits
    return value

class InstructionsBuffer:

    def __init__(self, binary, entry_point_loc = 0x08020004, binary_offset_loc=0x08020000, n_bytes=4096):
        # bin_obj
        self.binary = binary
        self.binary_offset_loc = binary_offset_loc

        # insns_buffer
        self.buff_len_bytes = n_bytes
        self.update_loc(entry_point_loc)

    # type
    # { 'offset' : 0x08020000, 'binary' : binary }

    def read_instructions_binary(self, loc):
        true_loc = loc - self.binary_offset_loc
        n_bytes = self.buff_len_bytes
        by = bytes(self.binary[true_loc:true_loc+n_bytes].hex(), 'utf-8')
        insns = disassemble_section(by)
        insns1 = []
        for i in filter(lambda i: i is not b'', insns.split(b'\n')):
            insn = list(filter(lambda p: p is not b'', i.split(b' ')))
            insn[0] = bytes(hex((loc + int(insn[0], 0))), 'utf-8')
            if insn[3] in cond_block_end + uncond_block_end + func_call:
                jump_offset = fix_jump_offset(insn[4])
                insn[4] = bytes(hex(loc + jump_offset), 'utf-8')
            if insn[3] in cond_block_end_zero:
                jump_offset = fix_jump_offset(insn[5])
                insn[5] = bytes(hex(loc + jump_offset), 'utf-8')
            insns1.append(insn)


        return insns1

    def update_loc(self, new_loc):
        self.curr_offset_loc = new_loc
        self.insns_buff = self.read_instructions_binary(self.curr_offset_loc)
        self.insns_buff_index = { int(v[0],0) : i for (i,v) in enumerate(self.insns_buff) }

    def read_insns_at_loc(self, loc):
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.insns_buff[idx:]

func_call = [b'bl', b'bl.w', b'bl.n']

func_start = [b'stmdb', b'stmdb.w', b'push.w', b'push', b'vpush', b'vpush.n', b'vpush.w' ]

# b'vpop', but we always do a pop
func_end = [ b'pop.w', b'pop.n', b'pop', b'ldmia', b'ldmia.w', b'ldmia.n' ]

block_end_start = [b'vcmpe.f32', b'cmp',   b'cmp.w']

cond_block_end_zero = [ b'cbnz', b'cbz' ]

# b'vmrs',

cond_block_end = [ b'bls.w', b'bls',
        b'beq', b'beq.n', b'beq.w',
        b'bne', b'bne.w',
        b'blt', b'blt.n', b'blt.w',
        b'blo', b'blo.n', b'blo.w',
        b'bhi', b'bhi.w',
        b'bhs', b'bhs.w',
        b'ble', b'ble.w', b'ble.n',
        b'bge', b'bge.w', b'bge.n',
        b'bls', b'bls.w', b'bls.n'
        ]

uncond_block_end = [ b'b', b'b.n',b'b.w' ]

tbb = [b'tbb', b'tbb.n', b'tbb.w', b'tbh', b'tbh.n', 'tbh.w']

branch = cond_block_end + uncond_block_end + cond_block_end_zero + tbb

block_end = cond_block_end + cond_block_end_zero + uncond_block_end + tbb


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
        raise Exception

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

def generate_block_graph(binary, entry_point_loc=0x08020004):

    insns_buff = InstructionsBuffer(binary, entry_point_loc)

    block_graph = {'index' : {}, 'start_block': None}

    search_locs = [entry_point_loc]

    while len(search_locs) > 0:

        # do code in order, so as to save the buffer
        search_locs.sort()
        search_loc = search_locs.pop(0)
        # print(hex(search_loc))

        end_of_function = False
        found_block_end = False
        block = []

        if search_loc not in block_graph['index']:
            insns = insns_buff.read_insns_at_loc(search_loc)
            for i in range(len(insns)):
                insn = insns[i]
                block.append(insn)
                if insn[3] in block_end:
                    found_block_end = True
                    break
                elif insn[3] in func_end:
                    end_of_function = True
                    # check
                    # 1. if pop/ldmia contains pc (return immmediate)
                    # 2. if the pop/ldmia contains lr (aka, it exits this function implicitly)
                    #        and the go ahead until pc-altering instruction occurs
                    if b'pc,' in insn[5:] or b'pc}' in insn[4:]:
                        break
                    elif b'lr,' in insn[5:] or b'lr}' in insn[4:]:
                        tail_end = []
                        tail_end_found = False
                        j = 0
                        while not tail_end_found:
                            tail_insn = insns[i + j]
                            tail_end.append(tail_insn)
                            if tail_insn[3] in uncond_block_end:
                                break
                            else:
                                j += 1
                        block += tail_end
                        break
                    else:
                        print(insn)
                        print(insns)
                        ## you could be here because of 1. unexpect case, 2. buffer was not full enough
                        ## and the program didn't reach a pc-altering instruction before reaching
                        ## the buffer end.
                        raise Exception
                else:
                    pass
                    # raise Exception

            if not (found_block_end or end_of_function):
                insns_buff.update_loc(search_loc)
                search_locs.append(search_loc) ## redo with new buffer
                continue

            block_loc = int(block[0][0], 0) # read the first offset
            end_loc = int(block[-1][0],0) + int(block[-1][1])

            if not end_of_function:
                children = get_children(block)
            else:
                children = [] # hack because it's needed

            new_block = mk_block(search_loc, block, end_loc, children)

            if block_graph['start_block'] is None:
                block_graph['start_block'] = new_block

            block_graph['index'][search_loc] = new_block

            search_locs += children


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
        for child_loc in block['children']:
            child = block_index[child_loc]

            if block['loc'] not in child['parents']:
                child['parents'].append(block['loc'])
                block_index[child_loc] = child

        return block_index

    block_graph['index'] = recurse_graph(block_graph, update_parents, block_graph['index'], True)

    # determine depth to make meta_block construction easy

    def node_depth (block, _, block_index):
        num_of_parents = len(block['parents'])

        if num_of_parents == 0:
            depth = 0

        elif num_of_parents == 1:
            parent = block_index[block['parents'][0]]
            parent_depth = parent['depth']
            parent_num_of_children = len(parent['children'])

            depth = parent_depth + (1 if parent_num_of_children > 1 else 0)

        elif num_of_parents >= 2:
            parents = [block_index[p] for p in block['parents']]
            parent_depths = [p['depth'] for p in parents]
            depth = max(parent_depths) - 1

        block['depth'] = depth

        block_index[block['loc']] = block

        return block_index

    block_graph['index'] = recurse_graph(block_graph, node_depth, block_graph['index'], True)

    return block_graph

# type if_meta_block -- block to contain if (triangle control flow)
# { 'cond' cond, 'true' : meta_block  'next': meta_block }

# type if_meta_block -- block to contain if/else
# { 'conds' : [cond], 'true' : meta_block,  'false' : meta_block, 'next' : meta_block }
#
# type while_meta_block -- block to linearize while
# { 'while' : [meta_block], 'next': meta_block }
#
# type case_meta_block -- block containing returns
# { 'cases' : [meta_block] } + meta_block
# type end_meta_block
# { 'end' : block } + meta_blocki

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

def find_end_blocks(block, block_index):

    def f(block, block_index, end_blocks):
        if len(block['children']) == 0:
            end_blocks.append(block)

        return end_blocks

    recurse_blocks(block, block_index, f, [], True)


def get_next_meta_block_loc(block, block_index):
    search_depth = block['depth']
    
    intersection = []

    retrace_nodes = [block]

    subgraph_index = {}
    subgraph_start_block = block

    # mark them false as we proceed through, faster than lists
    tally = { i : True for i in block_index }

    while len(retrace_nodes) > 0:
        curr_block = retrace_nodes.pop(-1)
        children = [block_index[i] for i in curr_block['children']]

        subgraph_index[curr_block['loc']] = curr_block

        tally[curr_block['loc']] = False # visited

        if len(current_block['children']) == 0:
            continue
        
        elif current_block['depth'] <= search_depth:
            intersection.append(current_block['loc'])
            continue
        else:
            for c in children:
                if tally[c['loc']]: # if it hasn't been visited
                    retrace_nodes.append(c) # push
    
    subgraph = { 'index' : subgraph_index, 'start_block' : subgraph_start_block }
    
    print(intersection)
    if len(intersection) > 0:
        for i in range(0, len(intersection) - 1):
            if interesection[i] != intersection[i + 1]:
                raise Exception
        return subgraph, intersection[0]
    else:
        return subgraph, None



def is_bridge(block, block_index, bridge_blocks):
    print(block)

    if len(block['children']) == 1:
        child = block['children'][0]
        child_block = block_index[child]
        if len(child_block['parents']) == 1:
            bridge_blocks.append((block['loc'], child))

    return bridge_blocks

# broken
def reduce_overlap(bridge_blocks):
    bridge_blocks.sort()

    reduced_bridge_blocks = []

    while len(bridge_blocks) > 1:
        (start1, end1) = bridge_blocks[0]
        (start2, end2) = bridge_blocks[1]

        if end1 == start2:
            bridge_blocks[0] = (start1, end2)
            bridge_blocks.pop(1)
        else:
            bridge = bridge_blocks.pop(0)
            reduced_bridge_blocks.append(bridge)

    reduced_bridge_blocks.append(bridge_blocks.pop(0))

    return reduced_bridge_blocks

def annotate_graph(block_graph):

    start_block = block_graph['start_block']
    print(start_block)
    block_index = block_graph['index']

    
    # simultaneously turn the graph in to meta_blocks and reduce those metablocks
    # using a stack and DFS
    # the aim is to output a graph with all the syntactic information to output
    # the instructions within C control flow and print out the conditions correctly
    # ERRORs if this encounters anything unfamiliar--it doesn't try hard.
    
    meta_block_index = {}
    meta_block_start = start_block

    meta_block_subgraph, subgraph_end_loc = get_next_meta_block_loc(start_block, block_index)
    meta_block_locs = [(meta_block_subgraph, subgraph_end_loc)]

    seen_locs = {}

    while len(meta_block_locs) > 0:
        subgraph, end_loc = meta_block_locs.pop(-1)

        start_block = subgraph['start_block']

        subgraph['end'] = end_loc # type violation, but it'll be handy
        subgraph_index = subgraph['index']
        meta_block_loc = start_block['loc']

        seen_locs[start_block['loc']] = True

        # proceed the start block forward to the first condition, and fold into `preface`
        # which we'll either switch into another variable if we thing
        # this is something other than an if, if/then, switch (i.e., while or function endings)
        preface = []

        children_locs = start_block['children']
        children = [subgraph_index[c] for c in children_locs]

        while len(children) == 1 and len(children[0]['parents']) == 1:
            preface.append(start_block)
            start_block = subgraph_index[children[0]['loc']]
            seen_locs[start_block['loc']] = True
            children = [subgraph_index[c] for c in start_block['children']]

        if len(children) == 2:
        # [true, false]
            if children_locs[0] in seen_locs:
                meta_block_index[meta_block_loc] = {
                            'type' : 'while',
                            'loc' : children_locs[0],
                            'end' : meta_block_loc,
                            'next' : subgraph_end
                        }
                #nothing to append since this is handled from the end unlike everything else
            elif children_locs[1] in seen_locs:
                # this case will probably be never used given index == 1 corresponds to false branch
                meta_block_index[meta_block_loc] = {
                            'type' : 'while',
                            'loc' : children_loc[1],
                            'end' : meta_block_loc,
                            'next' : subgraph_end
                        }
                #nothing to append since this is handled from the end unlike everything else
            else:
                intersection_points = intersection_of(children[0], children[1], subgraph_end)
                if len(intersection_points) == 0:
                    true_loc = children[0]['loc']
                    false_loc = children[1]['loc']
                    meta_block_index[meta_block_loc] = {
                            'type' : 'if',
                            'loc'  : meta_block_loc,
                            'cond' : preface,
                            'true' : true_loc,
                            'false': false_loc,
                            'next' : subgraph_end
                            }
                    
                    true_subgraph, true_end_loc = get_next_meta_block_loc(children[0], subgraph_index)
                    false_subgraph, false_end_loc = get_next_meta_block_loc(children[1], subgraph_index)
                    meta_block_locs += [(true_subgraph, true_end_loc), (false_subgraph, false_end_loc)]


                elif len(intersection_points) == 1:
                    # first we want to look to see if there is a premature intersection between branches
                    # that is, if we see an intersection of the two branches before reaching the end block
                    # then if there is a premature intersection, try to treat that as an additional
                    # conjuctive condition (i.e., cond1 || cond2, cond1 && cond2)
                    # get rid of else if it is empty, otherwise we carry out the naive strategy
                    # one conjunction:
                    #                     ( )                              ( )
                    #                    _/ \_                            _/ \_
                    #             true ( )<---( ) false             true ( )--->( ) false
                    #                   |     / \_                        |      \_
                    #               ib ( )  ( )   ( ) t/f            t/f ( )       ( ) ib
                    #                  /     |      \                    /           \
                    #                ...    ...     ...                ...           ...
                    true_block = children[0]
                    false_block = children[1]
                    intersection_point = intersection_points[0]
                    if intersection_point in true_block['children']:
                        pass
                    
                    elif intersection_point in false_block['children']:
                        pass
                    
                
                elif len(intersection_points) > 1:
                    # can't handle this right now
                    raise Exception
        
        # switch case
        elif len(children) > 2:
            # TBB for now, so just write out the cases
            pass
        elif len(children) == 1:
            raise Exception # not sure we should be here
        elif len(children) == 0:
            end_block = preface
        else:
            raise Exception

    raise Exception

# default to the RESET location on ARM M4
def generate_func_cf_asm(binary, entry_point_loc=0x08020004):
    block_graph = generate_block_graph(binary, entry_point_loc)

    annotated_graph = annotate_graph(block_graph)

    return generate_func_cf_from_graph(annotated_graph)

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    # parser.add_argument('output_file', metavar='o', type=str, help="output file")
    # parser.add_argument('func_loc', metavar='f', type=int, help="location to decompile")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    binary = f.read()

    f.close()

    output = generate_func_cf_asm( binary, 0x08020000 + 0xd630 )
