import argparse
import subprocess

import struct

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
        insns = [i for i in filter(lambda i: i is not b'', insns.split(b'\n'))]
        for j in range(len(insns)):
            i = insns[j]
            insn = list(filter(lambda p: p is not b'', i.split(b' ')))

            insn[0] = bytes(hex((loc + int(insn[0], 0))), 'utf-8')
            
            if insn[3] in cond_block_end + uncond_block_end + func_call:
                jump_offset = fix_jump_offset(insn[4])
                insn[4] = bytes(hex(loc + jump_offset), 'utf-8')
            
            elif insn[3] in cond_block_end_zero:
                jump_offset = fix_jump_offset(insn[5])
                insn[5] = bytes(hex(loc + jump_offset), 'utf-8')
            
            elif insn[3] == b'vmov.f32':
                if len(insn) > 6:
                    insn[5] = insn[8]
                insn = insn[0:6]

            elif insn[3] in load:
                f = False
                if insn[5] == b'[pc,':
                    curr_loc = int(insn[0], 0)
                    insn_len = int(insn[1])
                    next_insn_line = insns[j+1]
                    next_insn = list(filter(lambda p: p is not b'', next_insn_line.split(b' ')))
                    next_insn_len = int(next_insn[1])
                    data_offset = int(insn[6].rstrip(b']'), 0)
                    data_loc = curr_loc + 4 + data_offset
                    off_word = data_loc % 4

                    data_loc -= off_word
                    
                    if insn[3] in load_u32:
                        data_val = self.read_data_at_loc(data_loc, 4)
                    elif insn[3] in load_u16:
                        data_val = self.read_data_at_loc(data_loc, 2)
                    elif insn[3] in load_s16:
                        data_val = self.read_data_at_loc(data_loc, 2, signed=True)
                    elif insn[3] in load_u8:
                        data_val = self.read_data_at_loc(data_loc, 1)
                    elif insn[3] in load_s8:
                        data_val = self.read_data_at_loc(data_loc, 1, signed=True)
                    elif insn[3] in load_fp:
                        f = True
                        if insn[4].startswith(b'd'):
                            data_val = self.read_data_at_loc(data_loc, 8, f = True)
                        if insn[4].startswith(b's'):
                            data_val = self.read_data_at_loc(data_loc, 4, f = True)
                    else:
                        raise Exception

                    insn[3] = b'mov' if not f else b'vmov'
                    insn[5] = data_val
                    insn = insn[0:6]
           
            insns1.append(insn)

        return insns1

    def update_loc(self, new_loc):
        self.curr_offset_loc = new_loc
        self.insns_buff = self.read_instructions_binary(self.curr_offset_loc)
        self.insns_buff_index = { int(v[0],0) : i for (i,v) in enumerate(self.insns_buff) }

    def read_data_at_loc(self, loc, length, signed = False, f = False):
        data_loc = loc - self.binary_offset_loc
        data = self.binary[data_loc:data_loc + length]

        if length == 8 and f:
            # data = data[4:8] + data[0:4]
            data_val, = struct.unpack('<d', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 4 and f:
            data_val, = struct.unpack('<f', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 4:
            if signed:
                data_val, = struct.unpack('<i', data)
            else:
                data_val, = struct.unpack('<I', data)
            # pre-emptively exclude things which might be in 
            # program mem (0x0802...) or stack (0x2..) or periphs (0x3... 0x4... 0x5...)
            # write it as an address, little endian rotation
            if 0x8020000 < data_val or data_val < 0x8040000 or\
                    0x20000000 < data_val or data_val < 0x50000000:
                data_val = bytes(hex(data_val), 'utf-8')
            else:
                data_val = bytes(str(data_val), 'utf-8')
        elif length == 2:
            if signed:
                data_val, = struct.unpack('<h', data)
            else:
                data_val, = struct.unpack('<H', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 1:
            if signed:
                data_val, = struct.unpack('<b', data)
            else:
                data_val, = struct.unpack('<B', data)
            data_val = bytes(str(data_val), 'utf-8')
        else:
            raise Exception

        return data_val



    def read_insns_at_loc(self, loc):
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.insns_buff[idx:]

load_fp = [ b'vldr' ]
load_u32 = [ b'ldr', b'ldr.w' ]
load_u16 = [ b'ldrh', b'ldrh.w' ]
load_s16 = [ b'ldrsh', b'ldrsh.w' ]
load_u8 = [ b'ldrb', b'ldrb.w' ]
load_s8 = [ b'ldrsb', b'ldrsb.w' ]

load = load_fp + load_u32 + load_u16 + load_s16 + load_u8 + load_s8

func_call = [b'bl', b'bl.w', b'bl.n']

func_start = [b'stmdb', b'stmdb.w', b'push.w', b'push', b'vpush', b'vpush.n', b'vpush.w' ]

# b'vpop', but we always do a pop
func_end = [ b'pop.w', b'pop.n', b'pop', b'ldmia', b'ldmia.w', b'ldmia.n' ]
vpop = [b'vpop'] # treated differently

compare = [ b'cmp',   b'cmp.w' ]
fp_compare = [ b'vcmpe.f32' ]

compares = compare + fp_compare

block_end_start = compare + fp_compare

cond_block_end_zero = [ b'cbnz', b'cbz' ]

# b'vmrs',

beq = [ b'beq', b'beq.n', b'beq.w' ]
bne = [ b'bne', b'bne.w', b'bne.n' ]
ble = [ b'bls', b'bls.w', b'bls.n', b'ble', b'ble.w', b'ble.n' ] 
blt = [ b'blt', b'blt.n', b'blt.w' , b'blo', b'blo.n', b'blo.w', b'bcc', b'bcc.n', b'bcc.w' ]
bge = [ b'bhs', b'bhs.w', b'bhs.n', b'bcs', b'bcs.w', b'bcs.n', b'bge', b'bge.w', b'bge.n' ]
bgt = [ b'bhi', b'bhi.w', b'bhi.n', b'bpl.n', b'bpl.w' ] 

cond_block_end = beq + bne + ble + blt + bge + bgt

uncond_block_end = [ b'b', b'b.n',b'b.w' ]

tbb = [b'tbb', b'tbb.n', b'tbb.w', b'tbh', b'tbh.n', 'tbh.w']

branch = cond_block_end + uncond_block_end + cond_block_end_zero + tbb

block_end = cond_block_end + cond_block_end_zero + uncond_block_end + tbb


base_arith = [
        b'add', b'add.w', b'adds', b'vadd.f32', 
        b'sub', b'sub.w', b'subs', b'vsub.f32', b'rsb', b'rsb.w', b'rsbs', b'negs',
        b'and', b'and.w', b'bic', b'lsrs', b'lsls', b'asrs'
        ]

mul = [ b'vmul.f32', b'muls' ]

smull = [ b'smull' ]

div = [ b'sdiv', b'udiv', b'vdiv.f32' ]

vmlas = [ b'vmla.f32', b'vmls.f32', b'vnmls.f32' ]

cast = [ b'vcvt.f32.s32', b'vcvt.f32.u32', b'vcvt.u32.f32', b'vcvt.s32.f32',
         b'uxth', b'ubfx', b'sxth', b'sxtb', b'sxth.w', b'uxtb' ]

sxtab = [ b'sxtab']

store = [ b'strb.w', b'strb', b'strh.w', b'vstr', b'str', b'strh', b'str.w' ]

move = [ b'mov', b'movw', b'movs', b'vmov.f32', b'mov.w', b'vmov', b'vmrs']

cond_branch = cond_block_end + cond_block_end_zero + tbb


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

def collect_functions(block_graph):
    start_block = block_graph['start_block']
    block_index = block_graph['index']

    def collect (block, _, functions):
        insns = block['block']
        for i in insns:
            if i[3] in func_call:
                functions.append(i[4])
        return functions

    functions = recurse_graph(block_graph, collect, [], True)
    
    list(set(functions))

def get_function_signature(block_graph):
    start_block = block_graph['start_block']
    block_index = block_graph['index']

    loop_tracker = LoopTracker(block_index)
    loops = {}

    search_locs = [start_block['loc']]

    init_forward_scope = {'r0' : False, 'r1': False, 's0' : False, 'd0': False}
    
    # mapping from loc to scope, to be updated
    loc_scope = {search_locs[0] : init_forward_scope}
    forward_alive = {}
    
    ends = []

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block = block_index[loc] 

        if loc not in loops:
            if loop_tracker.can_loop(loc):
                loops[loc] = True
            else:
                loops[loc] = False

        scope = loc_scope[loc]

        insns = block['block']
        for i in insns:
            insn = i[3:]
            if insn[0] in base_arith + mul + div + vmlas + cast + move + load:
                if len(insn) == 3:
                    reg_alive = insn[1]
                    reg_kill = insn[2]
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif len(insn) == 4 or len(insn) == 6:
                    reg_alive = insn[1]
                    reg_kill1 = insn[2]
                    reg_kill2 = insn[3]
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in smull: # multiplication
                reg_alive1 = insn[2]
                reg_alive2 = insn[1]
                reg_kill1 = insn[3]
                reg_kill2 = insn[4]
                if reg_kill1 in scope:
                    scope[reg_kill1] = False
                if reg_kill2 in scope:
                    scope[reg_kill2] = False
                if reg_alive1 in scope:
                    scope[reg_alive1] = True
                if reg_alive2 in scope:
                    scope[reg_alive2] = True
            elif insn[0] in sxtab:
                if len(insn) == 4 or len(insn) == 6:
                    reg_alive = insn[1]
                    reg_kill1 = insn[2]
                    reg_kill2 = insn[3]
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in store:
                if len(insn) == 3:
                    reg_kill = insn[1]
                    reg_alive = insn[2]
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif len(insn) == 4 or len(insn) == 6:
                    reg_kill = insn[1]
                    reg_alive1 = insn[2]
                    reg_alive2 = insn[3]
                    if reg_kill in scope:
                        scope[reg_kill1] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in compares:
                if len(insn) == 3:
                    reg_kill1 = insn[1]
                    reg_kill2 = insn[2]
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                else:
                    print(insn)
                    raise Exception

            elif insn[0] in cond_block_end_zero:
                if len(insn) == 3:
                    reg_kill = insn[1]
                    if reg_kill in scope:
                        scope[reg_kill1] = False
                else:
                    raise Exception
            elif insn[0] in func_start + func_end + func_call + uncond_block_end + vpop + cond_block_end + tbb: # ignore
                pass
            else:
                print(i)
                raise Exception

        loc_scope[loc] = scope

        c_locs = block['children']
        
        if len(c_locs) == 0:
            if loc not in ends:
                ends.append(loc)
        else:
            for c in c_locs:
                # merge_scope(c, loc_scope)
                if c not in loc_scope:
                    loc_scope[c] = scope.copy()
                else:
                    new_scope = scope.copy()
                    prev_scope = loc_scope[c]
                    for k in prev_scope:
                        if prev_scope[k] or scope[k]:
                            new_scope[k] = True
                        
                if c not in loops:
                    search_locs.append(c)
        

    print(ends)

    for e in ends:
        print(loc_scope[e])

    raise Exception



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

class LoopTracker:

    def __init__(self, block_index):
        self.block_index = block_index
        self.loc_to_loop_end = {}
        self.loc_to_loop_start = {}
        self.loc_to_loop_locs = {}
        self.not_loop_loc = {} # locs which are not in a loop
    
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

    def is_loop_start(self, loc):
        # print('is_loop_start', hex(loc))
        if loc in self.loc_to_loop_start and loc == self.loc_to_loop_start[loc]:
            return True
        elif loc in self.not_loop_loc:
            return False
        else:
            self.detect_loop(loc)
            if loc in self.loc_to_loop_start and loc == self.loc_to_loop_start[loc]:
                return True
            else:
                return False
    
    def get_loop_end(self, loc):
        print('get_loop_end', hex(loc))
        if loc in self.loc_to_loop_end:
            print('self.loc_to_loop_end[loc]', self.loc_to_loop_end[loc])
            return self.loc_to_loop_end[loc]
        elif loc not in self.not_loop_loc:
            return None
        else:
            return self.detect_loop(loc)
            if loc in self.loc_to_loop_end:
                print('self.loc_to_loop_end[loc]', self.loc_to_loop_end[loc])
                return self.loc_to_loop_end[loc]
            else:
                return None

    def can_loop(self, loc):
        if loc in self.loc_to_loop_start:
            return True
        elif loc not in self.not_loop_loc:
            return False
        else:
            return self.detect_loop(loc)

    def detect_loop(self, start_loc):
        # print('detect_loop', hex(start_loc))
        # we want to first detect all the points in the loop, do this by making a loop path
        # asserting if it is maximal and then expanding if not maximal.
        # maximality of a loop is defined by having the set of points in the loop containing 
        # each points' parent and child nodes as well.
        # for each point, if the parent is loopable (can reach itself) add it to the set
        # for each point, if the child is loopable, at it to the set

        def can_loop(sl):
            # print('can_loop', hex(sl))
            ls = [sl]
            sn = {}

            while len(ls) > 0:
                l = ls.pop(-1)

                sn[l] = True

                children_locs = self.block_index[l]['children']

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
        search_locs = []

        # pre-emptive first check

        if can_loop(start_loc):
            search_locs.append(start_loc)
        else: # if len(loop_locs) == 0:
            self.not_loop_loc[start_loc] = True
            return False

        while len(search_locs) > 0:
            loc = search_locs.pop(0)

            if loc not in self.not_loop_loc and can_loop(loc):
                loop_locs.append(loc)
                for c in self.block_index[loc]['children']:
                    if c not in seen:
                        search_locs.append(c)
            else:
                self.not_loop_loc[loc] = True

            seen[loc] = True

            children_locs = self.block_index[loc]['children']
            # print('children_locs', [hex(c) for c in children_locs])


        entrance_loc = None
        exit_loc = None

        for loc in loop_locs:
            p_locs = self.block_index[loc]['parents']
            for p in p_locs:
                if p not in loop_locs:
                    entrance_loc = loc
           
            c_locs = self.block_index[loc]['children']
            for c in c_locs:
                if c not in loop_locs:
                    exit_loc = loc

        if entrance_loc is None or exit_loc is None:
            print("entrance_loc", hex(entrance_loc) if entrance_loc is not None else None)
            print("exit_loc", hex(exit_loc) if exit_loc is not None else None)
            print("loop_locs", [hex(l) for l in loop_locs])
            raise Exception

        for loc in loop_locs:
            self.loc_to_loop_start[loc] = entrance_loc
            self.loc_to_loop_end[loc] = exit_loc
            self.loc_to_loop_locs[loc] = loop_locs

        return True


class MetaBlockFinder(LoopTracker):

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
        print('')
        print("get_next_meta_block_loc", hex(start_loc), hex(end_loc) if end_loc is not None else None)

        if start_loc == end_loc:
            return None

        # if start_loc == 134405328:
            # print(block_index[134405328])
            # raise Exception

        intersection = None
        
        paths_index = { start_loc : [] } # { dest1 : [src1, src2, ..] , ...}
        retrace_nodes = [start_loc]
        seen_loops = { }
        
        check = False
        while intersection is None:
            
            count = 0

            while len(retrace_nodes) > 0:
                loc = retrace_nodes.pop(0)
                c_locs = self.block_index[loc]['children']
                
                for c in c_locs:
                    if c not in seen_loops: 
                        paths_index[c] = list(set( paths_index[loc] + [loc] +\
                            (paths_index[c] if c in paths_index else []) ));
                    
                        if self.is_loop_start(c):
                            seen_loops[c] = True
                        
                        if loc != end_loc: 
                            retrace_nodes.append(c) # push

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

                if loc not in seen_loops and self.all_seen_are_reachable(paths_index[loc], loc):
                    if len(c_locs) != 1 or len(self.block_index[c_locs[0]]['parents']) != 1:
                        intersection = loc
                        break
                
                if end_loc is None or loc != end_loc:
                    for c in c_locs:
                        if c not in retrace_nodes2 and c not in tally2: # if it hasn't been visited
                            retrace_nodes2.append(c) # push

            if len(retrace_nodes) == 0 and not check:
                # print('pass1')
                check = True
            elif len(retrace_nodes) == 0 and check:
                print("early return")
                for k in paths_index:
                    print(hex(k), [hex(v) for v in paths_index[k]])
                
                # print([hex(k) for k in seen_loops])
                    
                return None
            else:
                pass

        return intersection


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
        while len(children) == 1 and len(children[0]['parents']) == 1 and children_locs[0] != end_loc:
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
                loop_end_loc = mbf.get_loop_end(meta_block_loc)
                print('loop_end_loc', hex(loop_end_loc))
                next_start_loc = mbf.get_next_meta_block_loc(loop_end_loc, end_loc)
                if next_start_loc is not None:
                    if not (next_start_loc, end_loc) in meta_block_locs and next_start_loc not in seen_locs:
                        meta_block_locs.append((next_start_loc, end_loc))
                
                meta_block_index[meta_block_loc] = {
                            'type' : 'while',
                            'inner' : None,
                            'cond' : loop_end_loc, 
                            'next' : next_start_loc
                        }
                loops[meta_block_loc] = True
                meta_block_locs.append((meta_block_loc, loop_end_loc))
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
                if meta_block_loc != mbf.get_loop_end(meta_block_loc):
                    print("making if", meta_block_loc)
                    
                    next_start_loc = None
                    # if the end_loc is None we are at the end so may be true/false but no "nexts"
                    # if we aren't at the end_loc, then there is a next
                    if end_loc is not None and meta_block_loc != end_loc:
                        # get the next block with reference to the last of the preface block locs
                        next_start_loc = mbf.get_next_meta_block_loc(preface[-1], end_loc)
                        # we are able to find a next loc
                        if next_start_loc is not None:
                            # there is a next but will be handled, so assign but don't handle
                            if next_start_loc != end_loc: 
                                # if the next loc is the end of a loop unassign and don't take it
                                if next_start_loc != mbf.get_loop_end(next_start_loc):
                                    # if we've seen our location and it isn't already
                                    # going to be searched, we finally add
                                    if not (next_start_loc,end_loc) in meta_block_locs and next_start_loc not in seen_locs:
                                        meta_block_locs.append((next_start_loc, end_loc))
                                        # pre-emptively mark seen?
                                        seen_locs[next_start_loc] = True
                                    else:
                                        next_start_loc = None
                                else:
                                    next_start_loc = None
                            else:
                                if next_start_loc == mbf.get_loop_end(next_start_loc) or\
                                        next_start_loc in seen_locs:
                                    next_start_loc = None
                    
                    child_end_loc = end_loc if next_start_loc is None else next_start_loc
                   
                    # for both true/false we want to check if the children are the immediate
                    # end, having determined if there is a next block above, and if they
                    # are, skip them.
                    temp_true_loc = children_locs[0]
                    temp_false_loc = children_locs[1]
                    true_loc = None
                    false_loc = None
                    print("block temp tflocs", hex(temp_true_loc), hex(temp_false_loc))
                    if temp_true_loc != child_end_loc:
                        if temp_true_loc not in loops:
                            true_end_loc = mbf.get_next_meta_block_loc(temp_true_loc, child_end_loc)
                            if (true_end_loc != child_end_loc and child_end_loc is not None) or\
                                    ((true_end_loc is None and end_loc is None) or\
                                    true_end_loc is not None):
                                true_loc = temp_true_loc
                                meta_block_locs.append((true_loc, child_end_loc))
                                
                    if temp_false_loc != child_end_loc:
                        if temp_false_loc not in loops:
                            false_end_loc = mbf.get_next_meta_block_loc(temp_false_loc, child_end_loc)
                            if (false_end_loc != child_end_loc or child_end_loc is not None) or\
                                    ((false_end_loc is None and end_loc is None) or\
                                    false_end_loc is not None): ## there is no endpoint/subgraph
                                false_loc = temp_false_loc
                                meta_block_locs.append((false_loc, child_end_loc))
                   
                    print("true_loc, false_loc, next_start_loc", 
                            hex(true_loc) if true_loc is not None else None,
                            hex(false_loc) if false_loc is not None else None,
                            hex(next_start_loc) if next_start_loc is not None else None)
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
                    

                        # else:
                            # print(false_end_loc)
                            # raise Exception



                # elif len(intersection_points) == 1:
                    # raise Exception
                    # # first we want to look to see if there is a premature intersection between branches
                    # # that is, if we see an intersection of the two branches before reaching the end block
                    # # then if there is a premature intersection, try to treat that as an additional
                    # # conjuctive condition (i.e., cond1 || cond2, cond1 && cond2)
                    # # get rid of else if it is empty, otherwise we carry out the naive strategy
                    # # one conjunction:
                    # #                      ( )                              ( )
                    # #                     _/ \_                            _/ \_
                    # #             true ( )<---( ) false             true ( )--->( ) false
                    # #                   |     / \_                        |      \_
                    # #               ib ( )  ( )   ( ) t/f            t/f ( )       ( ) ib
                    # #                  /     |      \                    /           \
                    # #                ...    ...     ...                ...           ...
                    # intersection_point = intersection_points[0]
                    # if intersection_point in start_block['children']:
                        # if intersection_point == children_locs[0]: # true
                            # preface.append(children[1]['loc'])
                            # if children[1]['children'][0] != intersection_point: # true
                                # true_loc = children_locs[0]
                                # false_loc = children[1]['children'][0]
                                # meta_block_index[meta_block_loc] = {
                                            # 'type' : 'if',
                                            # 'loc'  : meta_block_loc,
                                            # 'cond' : preface,
                                            # 'conj' : 'or',
                                            # 'true' : true_loc,
                                            # 'false': false_loc, 
                                            # 'next' : subgraph_end
                                        # }
                            # elif children[1]['children'][1] != intersection_point: # false
                                # true_loc = children_locs[0]
                                # children[1]['children'][1]
                                # meta_block_index[meta_block_loc] = {
                                            # 'type' : 'if',
                                            # 'loc'  : meta_block_loc,
                                            # 'cond' : preface,
                                            # 'conj' : 'or',
                                            # 'true' : true_loc,
                                            # 'false': false_loc,
                                            # 'next' : subgraph_end
                                        # }
                            # else:
                                # raise Exception
                        # else:
                            # preface.append(children[0]['loc'])
                            # if children[0]['children'][0] != intersection_point: # true
                                # true_loc = children[0]['children'][0]
                                # false_loc = children_locs[1]
                                # meta_block_index[meta_block_loc] = {
                                            # 'type' : 'if',
                                            # 'loc'  : meta_block_loc,
                                            # 'cond' : preface,
                                            # 'conj' : 'or',
                                            # 'true' : true_loc,
                                            # 'false': false_loc, 
                                            # 'next' : subgraph_end
                                        # }
                            # elif children[1]['children'][1] != intersection_point: # false
                                # true_loc = children[0]['children'][1]
                                # false_loc = children_locs[1]
                                # meta_block_index[meta_block_loc] = {
                                            # 'type' : 'if',
                                            # 'loc'  : meta_block_loc,
                                            # 'cond' : preface,
                                            # 'conj' : 'or',
                                            # 'true' : true_loc,
                                            # 'false': false_loc,
                                            # 'next' : subgraph_end
                                        # }
                            # else:
                                # raise Exception
                        
                        # if children_locs[0] == subgraph_end or children_locs[0] in seen_locs:
                            # meta_block_locs.append((false_subgraph, false_end_loc))
                        # elif children_locs[1] == subgraph_end or children_locs[1] in seen_locs:
                            # meta_block_locs.append((true_subgraph, true_end_loc))
                        # else:
                            # meta_block_locs += [(true_subgraph, true_end_loc), (false_subgraph, false_end_loc)]
                    
                    # else:
                        # print("intersections", [hex(i) for i in intersection_points])
                        # print(start_block)
                        # print(children)
                        # raise Exception
                
                # elif len(intersection_points) > 1:
                    # # can't handle this right now
                    # raise Exception
                else:
                    pass
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
            if end_loc is not None and next_loc != end_loc:
                next_end = mbf.get_next_meta_block_loc(next_loc, end_loc)
                if next_end != end_loc and next_end is not None and next_end != next_loc:
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

def print_if_cond(cond, block_index):

    cond_out = b''
   
    insns = []
    for c in cond:
        insns += block_index[c]['block']

    insns.reverse()

    last_i = insns[0]
    
    last_insn = last_i[3]
    if last_insn in cond_block_end_zero:
        # this changes checks condition (sets NZCV)
        # and sets PC to the new loc
        comp_reg = last_i[4].rstrip(b',')
        comp = False if last_insn == b'cbz' else True
        if comp:
            cond_out = comp_reg + b' == 0'
        else:
            cond_out = comp_reg + b' != 0'
    
    elif last_insn in cond_block_end:
        # we have the condition but not the operations
        # so search backwards for the cmp operation
        # which could either be normal or FP
        comp = None

        for i in insns:
            insn = i[3]
            if insn in compare:
                comp_reg1 = i[4].rstrip(b',')
                comp_reg2 = i[5].lstrip(b'#').rstrip(b',')
                comp = last_insn
                break
            
        # try for floating point
        if comp is None:
            nzcv_set = False

            for i in insns:
                insn = i[3]
              
                if insn == b'vmrs' and i[4] == b'APSR_nzcv,' and i[5] == b'fpscr':
                    nzcv_set = True

                if insn in fp_compare and nzcv_set:
                    comp_reg1 = i[4].rstrip(b',')
                    comp_reg2 = i[5].lstrip(b'#').rstrip(b',')
                    comp = last_insn
            if not nzcv_set:
                raise Exception # should not be here


        if comp in beq:
            cond_out = comp_reg1 + b' != ' + comp_reg2
        elif comp in bne:
            cond_out = comp_reg1 + b' == ' + comp_reg2
        elif comp in blt:
            cond_out = comp_reg1 + b' >= ' + comp_reg2
        elif comp in ble:
            cond_out = comp_reg1 + b' > ' + comp_reg2
        elif comp in bgt:
            cond_out = comp_reg1 + b' <= ' + comp_reg2
        elif comp in bge:
            cond_out = comp_reg1 + b' < ' + comp_reg2
        else:
            print(comp)
            raise Exception

    block_out = b''.join([print_block(block_index[c]) for c in cond])

    return cond_out, block_out

def generate_func_cf_from_graph(meta_block_graph):
    block_index = meta_block_graph['index']
    meta_index = meta_block_graph['meta_block_index']
    start = meta_block_graph['start_block']

    seen_loops = {} # prevent loops...

    start_node = meta_index[start]

    def print_base_node(node):
        out = b''
        ty = node['type']
        if ty == 'if':
            print("if node")
            cond = node['cond']
            cond_expr, cond_block_out = print_if_cond(cond, block_index)

            true_loc = node['false']
            false_loc = node['true']
            print("node tf_locs", hex(true_loc) if true_loc is not None else None,
                    hex(false_loc) if false_loc is not None else None)
            if true_loc is None or true_loc == node['next'] or true_loc in seen_loops:
                true_out = b'if ( ' + cond_expr + b' ) \n{\n\n}\n'
            else:
                true_out = b'if ( ' + cond_expr + b' ) \n{\n' + print_node_loc(true_loc) + b'\n}\n'

            if false_loc is None or false_loc == node['next'] or false_loc in seen_loops or false_loc is None:
                false_out = b''
            else:
                false_out = b'else\n{\n' + print_node_loc(false_loc) + b'\n}\n'


            out += (cond_block_out + true_out + false_out)
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

        elif ty == 'end':
            end_out = b'\n'.join( [print_block(block_index[b]) for b in node['blocks']] )
            out += end_out
            node_loc = None
        else:
            print("node", node)
            print(node['type'])
            raise Exception
        return node_loc, out

    def print_node(node):
        out = b''
        while node is not None:
            ty = node['type']
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if ty == 'while':
                seen_loops[node_loc] = True
                print("while node")
                inner = node['inner']
                cond = node['cond']
                while_out = print_node(inner)
                cond_out = print_block(block_index[cond]) # print_base_node(cond)
                while_out = b'while (1) \n{\n' + while_out + cond_out + b'\n}\n'
                out += while_out
                
                node_loc = node['next']
            else:
                print("base node")
                node_loc, base_out = print_base_node(node)

                out += base_out

            if node_loc is not None:
                print("node next", hex(node_loc))
            else:
                print("node end")
            
            node = meta_index[node_loc] if node_loc is not None else None
        return out

    def print_node_loc(node_loc):
        print("node_loc", hex(node_loc))
        node = meta_index[node_loc]
        return print_node(node)

    return print_node_loc(start)

# default to the RESET location on ARM M4
def generate_func_cf_asm(binary, entry_point_loc=0x08020004):
    block_graph = generate_block_graph(binary, entry_point_loc)
    functions = collect_functions(block_graph)

    get_function_signature(block_graph)

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
