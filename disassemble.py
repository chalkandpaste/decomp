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
        b'bne', b'bne.w', b'bne.n',
        b'blt', b'blt.n', b'blt.w',
        b'blo', b'blo.n', b'blo.w', b'bcc', b'bcc.n', b'bcc.w'
        b'bhi', b'bhi.w', b'bpl.n', b'bpl.w'
        b'bhs', b'bhs.w', b'bhs.n', b'bcs', b'bcs.w', b'bcs.n',
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
                children = []

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
        # print("update_parents", hex(block['loc']))
        # print([hex(c) for c in block['children']])
        for child_loc in block['children']:
            child = block_index[child_loc]

            if block['loc'] not in child['parents']:
                child['parents'].append(block['loc'])
                # print(child)
                block_index[child_loc] = child

        return block_index

    block_graph['index'] = recurse_graph(block_graph, update_parents, block_graph['index'], True)

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
# { 'cases' : [meta_block], 'next' : meta_block }

# type end_meta_block
# { 'end' : block }

class MetaBlockFinder:

    def __init__(self, block_index):
        self.block_index = block_index
        self.loc_to_loop_end = {}
        self.loc_to_loop_start = {}
        self.loc_to_loop_locs = {}
        self.not_loop_loc = {} # locs which are not in a loop

    def all_seen_are_reachable(self, reachable, end_loc):
        # print("all_seen_are_reachable", [hex(r) for r in reachable], hex(end_loc))
        if len(reachable) == 0:
            return False
        for loc in reachable:
            block = self.block_index[loc]
            
            retrace_nodes = [block]
            tally = { }
    
            visited = []

            while len(retrace_nodes) > 0:
                block = retrace_nodes.pop(-1)
                children = [self.block_index[i] for i in block['children']]

                tally[block['loc']] = True
                visited.append(block['loc'])
                
                if block['loc'] not in reachable:
                    print("non-reachable", hex(block['loc']))
                    return False

                for c in children:
                    if c['loc'] not in tally and c not in retrace_nodes and c['loc'] != end_loc:
                        retrace_nodes.append(c) # push

            # print("visited", [hex(v) for v in visited])

        return True


    ## look forward until you find a block through which every other block passes
    ## Q: why can't another location reach this area?
    ## A: Because of where we start (namely, the beginning) and the assumption that 
    ##       this is structured like C code
    def get_next_meta_block_loc(self, start_loc, end_loc = None):
        print("get_next_meta_block_loc", hex(start_loc), hex(end_loc) if end_loc is not None else None)

        if start_loc == end_loc:
            return None

        # if start_loc == 134405328:
            # print(block_index[134405328])
            # raise Exception

        intersection = None
        
        paths_index = { start_loc : [] } # { dest1 : [src1, src2, ..] , ...}
        retrace_nodes = [start_loc]
        loops = { }
        
        check = False
        while intersection is None:
            
            count = 0

            while len(retrace_nodes) > 0:
                loc = retrace_nodes.pop(0)
                c_locs = self.block_index[loc]['children']
                p_locs = self.block_index[loc]['parents'] 
                # this prevents the last block of a loop being marked a loop
                children_not_already_loops = True
                for c in c_locs:
                    children_not_already_loops = children_not_already_loops and (c not in loops)
                # this is a cheap and faultly check to make sure we aren't the start of a loop
                # keyfailing: doesn't address loops in loops
                parents_not_already_loops = True
                for p in p_locs:
                    parents_not_already_loops = parents_not_already_loops and (p not in loops)
                if children_not_already_loops or parents_not_already_loops:
                    is_loop = self.can_loop(loc)
                    if is_loop:
                        loops[loc] = True # prevent loops
                
                for c in c_locs:
                    if c not in loops: 
                        paths_index[c] = list(set( paths_index[loc] + [loc] +\
                            (paths_index[c] if c in paths_index else []) ));
                        
                        if loc != end_loc: 
                            retrace_nodes.append(c) # push
                    else:
                        print("is loop loc", hex(c))

                count += 1
                if count > 512:
                    break
            
            retrace_nodes2 = [start_loc]
            tally2 = { }
    
            while len(retrace_nodes2) > 0:
                loc = retrace_nodes2.pop(0)
                c_locs = self.block_index[loc]['children']
                
                tally2[loc] = True # visited
                
                print("checking", hex(loc))
                print([hex(v) for v in paths_index[loc]])
                # print("block parents", [hex(p) for p in block_index[loc]['parents']])
                # print("block children", [hex(c) for c in block_index[loc]['children']])

                if loc not in loops and self.all_seen_are_reachable(paths_index[loc], loc):
                    intersection = loc
                    break
                
                for c in c_locs:
                    print('c in c_locs', hex(c))
                    if c not in retrace_nodes2 and c not in tally2: # if it hasn't been visited
                        # we can be the end, but not move past the end
                        if end_loc is not None and loc == end_loc:
                            pass
                        else:
                            retrace_nodes2.append(c) # push

            if len(retrace_nodes) == 0 and not check:
                # print('pass1')
                check = True
            elif len(retrace_nodes) == 0 and check:
                print("early return")
                for k in paths_index:
                    print(hex(k), [hex(v) for v in paths_index[k]])
                
                print([hex(k) for k in loops])
                    
                return None
            else:
                pass

        return intersection

    # def intersection_of(block1, block2, index, end_loc):

        # # print('intersection_of', hex(block1['loc']), hex(block2['loc']) )

        # tally = { }

        # if block1['loc'] != end_loc and block2['loc'] != end_loc:
            # retrace_nodes = [block1]

            # while len(retrace_nodes) > 0:
                # block = retrace_nodes.pop(-1)
                # # print("block1 block", hex(block['loc']))
                # children = [index[i] for i in block['children']]

                # tally[block['loc']] = True

                # for c in children:
                    # if c['loc'] not in tally and c['loc'] != end_loc: # if it hasn't been visited
                        # retrace_nodes.append(c) # push

            # intersection = []
            
            # retrace_nodes = [block2]
            
            # while len(retrace_nodes) > 0:
                # block = retrace_nodes.pop(-1)
                # # print("block2 block", hex(block['loc']))
                # children = [index[i] for i in block['children']]

                # if block['loc'] in tally:
                    # intersection.append(block['loc'])
                # else:
                    # tally[block['loc']] = True

                # for c in children:
                    # if c['loc'] not in tally and c['loc'] != end_loc: # if it hasn't been visited
                        # retrace_nodes.append(c) # push
            
            # return intersection
        # else:
            # return []

    def can_loop(self, loc):
    
        print('can_loop', hex(loc))

        if loc in self.loc_to_loop_start:
            return True
        elif loc not in self.not_loop_loc:
            return False
        else:
            return self.detect_loop(loc)

    def detect_loop(self, start_loc):
        # we want to first detect all the points in the loop, do this by making a loop path
        # asserting if it is maximal and then expanding if not maximal.
        # maximality of a loop is defined by having the set of points in the loop containing 
        # each points' parent and child nodes as well.
        # for each point, if the parent is loopable (can reach itself) add it to the set
        # for each point, if the child is loopable, at it to the set


        # determine if we can loop via parents and children and determine if this is the
        # start of a loop.
        # i.e., loop starts can only loop via children 
        #       (loop ends, consequently can only loop via parents)
        
        def can_loop(sl):
            ls = [sl]
            sn = {}

            while len(ls) > 0:
                l = ls.pop(-1)

                sn[l] = True

                children_locs = self.block_index[loc]['children']

                for c in children_locs:
                    # only need one counter-example
                    if c == sl:
                        return True
                    elif c not in sn and c not in ls:
                        ls.append(c)
                    else:
                        pass

            return False

        seen = {}
        loop_locs = []
        search_locs = [start_loc]

        while len(search_locs) > 0:
            loc = search_locs.pop(0)

            if can_loop(loc):
                loop_locs.append(loc)

            seen[loc] = True

            loop_locs += self.block_index[loc]['children']

        entrance_loc = None
        exit_loc = None

        if len(loop_locs) == 0:
            return False

        for loc in loop_locs:

            for p in self.block_index[loc]['parent']:
                if p not in loop_locs:
                    entrance_loc = p
            
            for c in self.block_index[loc]['children']:
                if c not in loop_locs:
                    entrance_loc = c

        if entrance_loc is None or exit_loc is None:
            raise Exception

        for loc in loop_locs:
            self.loc_to_loop_start[loc] = entrance_loc
            self.loc_to_loop_end[loc] = exit_loc
            self.loc_to_loop_locs[loc] = loop_locs

        return True

def annotate_graph(block_graph):

    start_loc = block_graph['start_block']['loc']
    block_index = block_graph['index']

    mbf = MetaBlockFinder(block_index)

    meta_block_index = {}
    meta_block_start = start_loc

    end_loc = mbf.get_next_meta_block_loc(start_loc)
    meta_block_locs = [(start_loc, end_loc)]

    while end_loc is not None:
        start_loc = end_loc
        end_loc = mbf.get_next_meta_block_loc(start_loc)
        meta_block_locs.append((start_loc, end_loc))

    # print([(hex(s), hex(e) if e is not None else 0) for (s,e) in meta_block_locs])
    # raise Exception

    meta_block_locs.reverse()
    # print([(hex(sg['start_block']['loc']), hex(loc)) for (sg, loc) in meta_block_locs])

    seen_locs = {}
    loops = { }

    while len(meta_block_locs) > 0:
        print("meta_block_locs", [(hex(s),(hex(e) if e is not None else None)) for (s,e) in meta_block_locs])
        start_loc, end_loc = meta_block_locs.pop(-1)
    
        start_block = block_index[start_loc]

        print("annotate loop", hex(start_loc))
        # print([hex(p) for p in start_block['parents']])
        # print([hex(c) for c in start_block['children']])
        # print(start_block)

        meta_block_loc = start_loc

        seen_locs[start_loc] = True


        # proceed the start block forward to the first condition, and fold into `preface`
        # which we'll either switch into another variable if we thing
        # this is something other than an if, if/then, switch (i.e., while or function endings)
        preface = []

        children_locs = block_index[start_loc]['children']
        children = [block_index[c] for c in children_locs]

        print("pre-eating", hex(start_loc))
        while len(children) == 1 and len(children[0]['parents']) == 1:
            preface.append(start_loc)
            # print("add to preface", hex(start_block['loc']))
            start_loc = children_locs[0]
            print("eating", hex(start_loc))
            seen_locs[start_loc] = True
            children_locs = block_index[start_loc]['children']
            children = [block_index[c] for c in children_locs]

        preface.append(start_loc)
        seen_locs[start_loc] = True

        # print("loop block", start_block)

        if len(children) == 2:
            have_not_made_meta_block = meta_block_loc not in meta_block_index
            is_loop = mbf.can_loop(meta_block_loc)
            have_seen_children = children_locs[0] in seen_locs or children_locs[1] in seen_locs
            if have_not_made_meta_block and is_loop and not have_seen_children: # children_locs[0] in seen_locs and 
                print('making while', hex(children_locs[0]), hex(meta_block_loc))
                curr_loc = meta_block_loc
                if next_start_loc != end_loc and curr_loc != end_loc:
                    if  next_start_loc is not None and end_loc is not None:
                        next_start_loc = mbf.get_next_meta_block_loc(curr_loc, end_loc)
                        if not (next_start_loc,end_loc) in meta_block_locs and next_block_loc not in seen_locs:
                            meta_block_locs.append((next_start_loc, end_loc))
                        # if next_start_loc in seen_locs or (next_start_loc, end_loc) in meta_block_locs:
                            # raise Exception
                meta_block_index[meta_block_loc] = {
                            'type' : 'while',
                            'inner' : None,
                            'next' : next_start_loc
                        }
                loops[meta_block_loc] = True
                meta_block_locs.append((meta_block_loc, end_loc))
                #nothing to append since this is handled from the end unlike everything else
            # elif can_loop(children_locs[1], block_index):
                # print('making while')
                # # this case will probably be never used given index == 1 corresponds to false branch
                # meta_block_index[meta_block_loc] = {
                            # 'type' : 'while',
                            # 'inner' : None,
                            # 'next' : end_loc
                        # }
                # #nothing to append since this is handled from the end unlike everything else
            else: # elif children_locs[0] not in seen_locs or children_locs[1] not in seen_locs:
                # [true, false] == c[0], c[1]
                # intersection_points = intersection_of(children[0], children[1], block_index, end_loc)
                
                # if len(intersection_points) == 0:
                if True:
                    curr_loc = meta_block_loc
                    if end_loc is not None and curr_loc != end_loc:
                        next_start_loc = mbf.get_next_meta_block_loc(curr_loc, end_loc)
                        if  next_start_loc is not None and next_start_loc != end_loc:
                            if not (next_start_loc,end_loc) in meta_block_locs and next_start_loc not in seen_locs:
                                meta_block_locs.append((next_start_loc, end_loc))
                            # if next_start_loc in seen_locs or (next_start_loc, end_loc) in meta_block_locs:
                                # print((hex(next_start_loc), hex(end_loc)))
                                # raise Exception

                    print("making if", meta_block_loc)
                    true_loc = children_locs[0]
                    false_loc = children_locs[1]
                    print("block tflocs", hex(true_loc), hex(false_loc))
                    if meta_block_loc in meta_block_index and meta_block_index[meta_block_loc]['type'] == 'while':
                        meta_block_index[meta_block_loc]['inner'] = {
                                'type' : 'if',
                                'loc'  : meta_block_loc,
                                'cond' : preface,
                                'true' : true_loc,
                                'false': false_loc,
                                'next' : next_start_loc
                                }
                    else:
                        meta_block_index[meta_block_loc] = {
                                'type' : 'if',
                                'loc'  : meta_block_loc,
                                'cond' : preface,
                                'true' : true_loc,
                                'false': false_loc,
                                'next' : next_start_loc
                                }

                    if true_loc != end_loc:
                        true_end_loc = mbf.get_next_meta_block_loc(true_loc, end_loc)
                        if true_loc not in loops and true_end_loc is not None:
                            meta_block_locs.append((true_loc, end_loc))
                    if false_loc != end_loc:
                        false_end_loc = mbf.get_next_meta_block_loc(false_loc, end_loc)
                        if false_loc not in loops and false_end_loc is not None:
                            meta_block_locs.append((false_loc, end_loc))
                        else:
                            print(false_end_loc)
                            raise Exception



                elif len(intersection_points) == 1:
                    raise Exception
                    # first we want to look to see if there is a premature intersection between branches
                    # that is, if we see an intersection of the two branches before reaching the end block
                    # then if there is a premature intersection, try to treat that as an additional
                    # conjuctive condition (i.e., cond1 || cond2, cond1 && cond2)
                    # get rid of else if it is empty, otherwise we carry out the naive strategy
                    # one conjunction:
                    #                      ( )                              ( )
                    #                     _/ \_                            _/ \_
                    #             true ( )<---( ) false             true ( )--->( ) false
                    #                   |     / \_                        |      \_
                    #               ib ( )  ( )   ( ) t/f            t/f ( )       ( ) ib
                    #                  /     |      \                    /           \
                    #                ...    ...     ...                ...           ...
                    intersection_point = intersection_points[0]
                    if intersection_point in start_block['children']:
                        if intersection_point == children_locs[0]: # true
                            preface.append(children[1]['loc'])
                            if children[1]['children'][0] != intersection_point: # true
                                true_loc = children_locs[0]
                                false_loc = children[1]['children'][0]
                                meta_block_index[meta_block_loc] = {
                                            'type' : 'if',
                                            'loc'  : meta_block_loc,
                                            'cond' : preface,
                                            'conj' : 'or',
                                            'true' : true_loc,
                                            'false': false_loc, 
                                            'next' : subgraph_end
                                        }
                            elif children[1]['children'][1] != intersection_point: # false
                                true_loc = children_locs[0]
                                children[1]['children'][1]
                                meta_block_index[meta_block_loc] = {
                                            'type' : 'if',
                                            'loc'  : meta_block_loc,
                                            'cond' : preface,
                                            'conj' : 'or',
                                            'true' : true_loc,
                                            'false': false_loc,
                                            'next' : subgraph_end
                                        }
                            else:
                                raise Exception
                        else:
                            preface.append(children[0]['loc'])
                            if children[0]['children'][0] != intersection_point: # true
                                true_loc = children[0]['children'][0]
                                false_loc = children_locs[1]
                                meta_block_index[meta_block_loc] = {
                                            'type' : 'if',
                                            'loc'  : meta_block_loc,
                                            'cond' : preface,
                                            'conj' : 'or',
                                            'true' : true_loc,
                                            'false': false_loc, 
                                            'next' : subgraph_end
                                        }
                            elif children[1]['children'][1] != intersection_point: # false
                                true_loc = children[0]['children'][1]
                                false_loc = children_locs[1]
                                meta_block_index[meta_block_loc] = {
                                            'type' : 'if',
                                            'loc'  : meta_block_loc,
                                            'cond' : preface,
                                            'conj' : 'or',
                                            'true' : true_loc,
                                            'false': false_loc,
                                            'next' : subgraph_end
                                        }
                            else:
                                raise Exception
                        
                        if children_locs[0] == subgraph_end or children_locs[0] in seen_locs:
                            meta_block_locs.append((false_subgraph, false_end_loc))
                        elif children_locs[1] == subgraph_end or children_locs[1] in seen_locs:
                            meta_block_locs.append((true_subgraph, true_end_loc))
                        else:
                            meta_block_locs += [(true_subgraph, true_end_loc), (false_subgraph, false_end_loc)]
                    
                    else:
                        print("intersections", [hex(i) for i in intersection_points])
                        print(start_block)
                        print(children)
                        raise Exception
                
                elif len(intersection_points) > 1:
                    # can't handle this right now
                    raise Exception
            # else:
                # raise Exception # how did we get here?
        # switch case
        elif len(children) > 2:
            # TBB for now, so just write out the cases
            pass
        elif len(children) == 1:
            print("making block node", hex(meta_block_loc))
            blocks = preface
            next_loc = children_locs[0]
            # print("next_loc", hex(next_loc) if next_loc is not None else None)
            # print("end_loc", hex(end_loc) if end_loc is not None else None)
            next_end = None
            if next_loc != end_loc and end_loc is not None:
                next_end = mbf.get_next_meta_block_loc(next_loc, end_loc)
                if next_end != end_loc and next_end is not None:
                    if next_loc not in seen_locs and (next_loc,end_loc) not in meta_block_locs :
                        meta_block_locs.append((next_loc, end_loc))
                    # if next_loc in seen_locs and (next_loc,end_loc) not in meta_block_locs:
                        # print((hex(next_loc), hex(end_loc)))
                        # raise Exception

            if next_end is not None:
                meta_block_index[meta_block_loc] = {
                            'type' : 'block',
                            'blocks' : blocks,
                            'next' : next_loc
                        }

            else:
                meta_block_index[meta_block_loc] = {
                            'type' : 'block',
                            'blocks' : blocks,
                            'next' : None
                        }
            

        elif len(children) == 0:
            end_block = preface
            meta_block_index[meta_block_loc] = {
                        'type' : 'end',
                        'blocks' : preface
                    }
        else:
            raise Exception

    meta_block_graph = { 
            'index' : block_index, 
            'meta_block_index': meta_block_index, 
            'start_block' : meta_block_start 
            }

    return meta_block_graph

def print_block(block):
    prefix = b'/*' + bytes(hex(block['loc']), 'utf-8') + b'\n'
    suffix = b'\n*/\n'

    body = b'\n'.join( [b' '.join(insn) for insn in block['block']] )

    return prefix + body + suffix

def generate_func_cf_from_graph(meta_block_graph):
    block_index = meta_block_graph['index']
    meta_index = meta_block_graph['meta_block_index']
    start = meta_block_graph['start_block']

    seen_locs = {start : True} # prevent loops...

    start_node = meta_index[start]

    def print_base_node(node):
        out = b''
        ty = node['type']
        if ty == 'if':
            print("if node")
            cond = node['cond']
            for c in cond:
                seen_locs[c] = True
            cond_out = b''.join( [print_block(block_index[loc]) for loc in cond] )

            true_loc = node['false']
            false_loc = node['true']
            print("node tf_locs", hex(true_loc), hex(false_loc))
            if true_loc == node['next'] or true_loc in seen_locs:
                true_out = b'if () \n{\n\n}\n'
            else:
                seen_locs[true_loc] = True
                true_out = b'else\n{\n' + print_node(true_loc) + b'\n}\n'

            if false_loc == node['next'] or false_loc in seen_locs:
                false_out = b''
            else:
                seen_locs[false_loc] = True
                false_out = b'else\n{\n' + print_node(false_loc) + b'\n}\n'


            out += (cond_out + true_out + false_out)
            # if node['next'] != 
            node_loc = node['next']
            if node['next'] is not None:
                print("if node_next:", hex(node_loc))
            else:
                print("if end")

        elif ty == 'while':
            raise Exception # don't think we should come here, but otherwise pass
            pass

        elif ty == 'block':
            block_out = b'\n'.join( [print_block(block_index[b]) for b in node['blocks']] )

            out += block_out
            node_loc = node['next']
            if node['next'] is not None:
                print("node block node_next:", hex(node_loc))
            else:
                print("node block end")

        elif ty == 'end':
            end_out = b'\n'.join( [print_block(block_index[b]) for b in node['blocks']] )
            out += end_out
            node_loc = None
        else:
            print("node", node)
            print(node['type'])
            raise Exception
        return node_loc, out

    def print_node(node_loc):
        out = b''
        while node_loc is not None:
            print("node_loc", hex(node_loc))
            seen_locs[node_loc] = True
            node = meta_index[node_loc]
            ty = node['type']
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if ty == 'while':
                print("while node")
                inner = node['inner']

                next_loc, out = print_base_node(inner)

                while_out = b'while (1) \n{\n' + out + b'\n}\n'

                out += while_out

                node_loc = next_loc # node['next']
            else:
                print("base node")
                node_loc, out = print_base_node(node)

            if node_loc is not None:
                print("node next", hex(node_loc))
            else:
                print("node end")
        return out

    return print_node(start)

# default to the RESET location on ARM M4
def generate_func_cf_asm(binary, entry_point_loc=0x08020004):
    block_graph = generate_block_graph(binary, entry_point_loc)

    annotated_graph = annotate_graph(block_graph)

    for k in annotated_graph['meta_block_index']:
        print(hex(k))

    return generate_func_cf_from_graph(annotated_graph)

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")
    # parser.add_argument('func_loc', metavar='f', type=int, help="location to decompile")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    binary = f.read()

    f.close()

    output = generate_func_cf_asm( binary, 0x08020000 + 0xd630 )

    g = open(args.output_file, 'wb')

    g.write(output)
