from block_graph import generate_block_graph, recurse_graph

from loop_tracker import LoopTracker
from instructions import *
    
skip_functions = [ 134469972, 134471256, 134469472, 134471424, 134472782, 134455624, 134470750, 134472518,
            0x8020298, 0x80205d6, 0x802fe84, 0x8020ccc, 0x8020334, 0x8020f24, 0x8020c40, 0x8021470, 0x8021340,
            0x8021008, 0x803e2a4, 0x803e3ea, 0x803d870, 0x8020c38, 0x8020694, 0x8020c30, 0x803c29c,
            0x802f708, 0x802054c, 0x803dd04, 0x803df6c, 0x803e2f0, 0x803d778, 0x803e11c, 0x803a178,
            0x8020748, 
            ] 
            # 0x8020f24, 0x8020d4c, 0x8020c38, 0x803df84, 0x8020334, 0x8020c30, 0x8020ccc, 0x8020748, 0x802fe84,
            # 0x803c29c, 0x803adc8, 0x803d7dc, 0x803af48, 0x803af28, 0x8020688, 0x803c222, 0x803d440, 0x803aec0,
            # 0x8020244, 0x803af68, 0x8030144, 0x802ff6c, 0x802fd58, 0x803c23c,  ]

def add_function_sigs(block_graph, function_sigs):

    block_index = block_graph['index']
    start_block = block_graph['start_block']

    search_locs = [start_block['loc']]

    seen = {} # only need one pass ever

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        seen[loc] = True

        insns = block_index[loc]['block']

        new_insns = []

        for i in range(len(insns)):
            insn = insns[i]
            if insn[3] in func_call or insn[3] in uncond_block_end:
                func_loc = int(insn[4], 0)
                if func_loc in function_sigs:
                    fs = function_sigs[func_loc]
                    insn.append(fs)

            new_insns.append(insn)
        block_index[loc]['block'] = new_insns

        c_locs = block_index[loc]['children']

        for c in c_locs:
            if c not in seen and c not in search_locs:
                search_locs.append(c)

    block_graph['index'] = block_index

    return block_graph

def collect_functions(block_graph):
    start_block = block_graph['start_block']
    block_index = block_graph['index']

    def collect (block, _, functions):
        insns = block['block']
        for i in range(len(insns)):
            insn = insns[i]
            if insn[3] in func_call:
                functions.append(insn[4])
            elif insn[3] in func_end:
                for j in range(i, len(insns)):
                    insn1 = insns[j]
                    if insn1[3] in uncond_block_end:
                        functions.append(insn1[4])
        return functions

    functions = recurse_graph(block_graph, collect, [], True)
    
    functions = [int(f, 0) for f in functions]
    
    return list(set(functions))

def get_function_signature(block_graph):
    start_block = block_graph['start_block']
    block_index = block_graph['index']

    loop_tracker = LoopTracker(block_index)
    loops = {}

    search_locs = [start_block['loc']]

    init_forward_scope = {b'r0' : False, b'r1': False, b's0' : False, b'd0': False}
    
    # mapping from loc to scope, to be updated
    loc_scope = {search_locs[0] : init_forward_scope}
    
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
            if insn[0] in base_arith + mul + div + vmlas + cast + bits + move + load:
                if len(insn) == 3:
                    reg_alive = crs(insn[1])
                    reg_kill = crs(insn[2])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif len(insn) == 4 or len(insn) == 6 or (insn[0] in add and len(insn) == 8):
                    reg_alive = crs(insn[1])
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif insn[0] in move and len(insn) == 5:
                    reg_alive = crs(insn[1])
                    reg_kill = crs(insn[2])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif insn[0] in bits and len(insn) == 4:
                    # don't make alive as rX gets re-used
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                elif insn[0] in vmlas + bits and len(insn) == 5:
                    reg_alive = crs(insn[1])
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[3])
                    reg_kill3 = crs(insn[4])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_kill3 in scope:
                        scope[reg_kill3] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in smull: # signed long mul + store double
                reg_alive1 = crs(insn[2])
                reg_alive2 = crs(insn[1])
                reg_kill1 = crs(insn[3])
                reg_kill2 = crs(insn[4])
                if reg_kill1 in scope:
                    scope[reg_kill1] = False
                if reg_kill2 in scope:
                    scope[reg_kill2] = False
                if reg_alive1 in scope:
                    scope[reg_alive1] = True
                if reg_alive2 in scope:
                    scope[reg_alive2] = True
            elif insn[0] in store:
                if len(insn) == 3:
                    reg_kill1 = crs(insn[1])
                    reg_kill2 = crs(insn[2])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                elif len(insn) == 4 or len(insn) == 6:
                    reg_kill1 = crs(insn[1])
                    reg_kill2 = crs(insn[2])
                    reg_kill3 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_kill3 in scope:
                        scope[reg_kill3] = False
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in store_d: #
                if len(insn) == 4: 
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[1])
                    reg_kill3 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_kill3 in scope:
                        scope[reg_kill3] = False
                elif len(insn) == 5:
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[1])
                    reg_kill3 = crs(insn[3])
                    reg_kill4 = crs(insn[4])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_kill3 in scope:
                        scope[reg_kill3] = False
                    if reg_kill4 in scope:
                        scope[reg_kill4] = False

                else:
                    print(insn)
                    raise Exception
            elif insn[0] in load_d: #
                if len(insn) == 4:
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[1])
                    reg_kill1 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                elif len(insn) == 5:
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[1])
                    reg_kill1 = crs(insn[3])
                    reg_kill2 = crs(insn[4])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True

                else:
                    print(insn)
                    raise Exception
            elif insn[0] in sxtab:
                if len(insn) == 4 or len(insn) == 6:
                    reg_alive = crs(insn[1])
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in compares + tst:
                if len(insn) == 3:
                    reg_kill1 = crs(insn[1])
                    reg_kill2 = crs(insn[2])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                else:
                    print(insn)
                    raise Exception

            elif insn[0] in cond_block_end_zero:
                if len(insn) == 3:
                    reg_kill = crs(insn[1])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                else:
                    raise Exception
            elif insn[0] in func_start + func_end + func_call + uncond_block_end + vpop + cond_block_end + tbb + nop + fucking_shit: # ignore
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
                    for k in init_forward_scope:
                        if prev_scope[k] or scope[k]:
                            new_scope[k] = True
                        
                if c not in loops:
                    search_locs.append(c)
        

    return_scope = None

    for e in ends:
        end_scope = loc_scope[e]
        if return_scope is None:
            return_scope = end_scope
        else:
            for reg in end_scope:
                if end_scope[reg] and return_scope[reg]:
                    return_scope[reg] = True

    loops = {}

    search_locs = ends

    init_backward_scope = {
            b'r0' : False, b'r1' : False, b'r2' : False, b'r3' : False,
            b's0' : False, b's1' : False, b's2' : False, b's3' : False,
            b'd0' : False, b'd1' : False, b'd2' : False, b'd3' : False
            }
    
    # mapping from loc to scope, to be updated
    loc_scope = { loc : init_backward_scope for loc in search_locs }
    
    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block = block_index[loc] 

        if loc not in loops:
            if loop_tracker.can_loop(loc):
                loops[loc] = True
            else:
                loops[loc] = False

        scope = loc_scope[loc]

        insns = block['block'].copy()
        insns.reverse()

        for i in insns:
            insn = i[3:]
            if insn[0] in base_arith + mul + div + vmlas + cast + bits + move + load:
                if len(insn) == 3:
                    reg_klll = crs(insn[1])
                    reg_alive = crs(insn[2])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif len(insn) == 4 or len(insn) == 6 or (insn[0] in add and len(insn) == 8):
                    reg_kill = crs(insn[1])
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[3])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                elif insn[0] in bits and len(insn) == 4:
                    # don't kill as rX gets re-used
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[3])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                elif insn[0] in move and len(insn) == 5:
                    reg_kill = crs(insn[1])
                    reg_alive = crs(insn[2])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive in scope:
                        scope[reg_alive] = True
                elif insn[0] in vmlas + bits and len(insn) == 5:
                    reg_kill = crs(insn[1])
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[3])
                    reg_alive3 = crs(insn[4])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                    if reg_alive3 in scope:
                        scope[reg_alive3] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in smull: # long signed multiplication, also store_d 
                reg_kill1 = crs(insn[2])
                reg_kill2 = crs(insn[1])
                reg_alive1 = crs(insn[3])
                reg_alive2 = crs(insn[4])
                if reg_kill1 in scope:
                    scope[reg_kill1] = False
                if reg_kill2 in scope:
                    scope[reg_kill2] = False
                if reg_alive1 in scope:
                    scope[reg_alive1] = True
                if reg_alive2 in scope:
                    scope[reg_alive2] = True
            elif insn[0] in store:
                if len(insn) == 3:
                    reg_alive1 = crs(insn[1])
                    reg_alive2 = crs(insn[2])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                elif len(insn) == 4 or len(insn) == 6:
                    reg_alive1 = crs(insn[1])
                    reg_alive2 = crs(insn[2])
                    reg_alive3 = crs(insn[3])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                    if reg_alive3 in scope:
                        scope[reg_alive3] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in store_d:
                if len(insn) == 4:
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[1])
                    reg_alive3 = crs(insn[3])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                    if reg_alive3 in scope:
                        scope[reg_alive2] = True
                elif len(insn) == 5:
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[1])
                    reg_alive3 = crs(insn[3])
                    reg_alive4 = crs(insn[3])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                    if reg_alive3 in scope:
                        scope[reg_alive3] = True
                    if reg_alive4 in scope:
                        scope[reg_alive4] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in load_d:
                if len(insn) == 4:
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[1])
                    reg_alive1 = crs(insn[3])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                elif len(insn) == 5:
                    reg_kill1 = crs(insn[2])
                    reg_kill2 = crs(insn[1])
                    reg_alive1 = crs(insn[3])
                    reg_alive2 = crs(insn[4])
                    if reg_kill1 in scope:
                        scope[reg_kill1] = False
                    if reg_kill2 in scope:
                        scope[reg_kill2] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in sxtab:
                if len(insn) == 4 or len(insn) == 6:
                    reg_kill = crs(insn[1])
                    reg_alive1 = crs(insn[2])
                    reg_alive2 = crs(insn[3])
                    if reg_kill in scope:
                        scope[reg_kill] = False
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_alive2 in scope:
                        scope[reg_alive2] = True
                else:
                    print(insn)
                    raise Exception
            elif insn[0] in compares + tst:
                if len(insn) == 3:
                    reg_alive1 = crs(insn[1])
                    reg_alive2 = crs(insn[2])
                    if reg_alive1 in scope:
                        scope[reg_alive1] = True
                    if reg_kill2 in scope:
                        scope[reg_alive2] = True
                else:
                    print(insn)
                    raise Exception

            elif insn[0] in cond_block_end_zero:
                if len(insn) == 3:
                    reg_alive = crs(insn[1])
                    if reg_alive in scope:
                        scope[reg_alive] = True
                else:
                    raise Exception
            elif insn[0] in func_start + func_end + func_call + uncond_block_end + vpop + cond_block_end + tbb + nop + fucking_shit: # ignore
                pass
            else:
                print(i)
                raise Exception

        loc_scope[loc] = scope

        p_locs = block['parents']
        
        for p in p_locs:
            if p not in loc_scope:
                loc_scope[p] = scope.copy()
            else:
                new_scope = scope.copy()
                prev_scope = loc_scope[p]
                for k in init_backward_scope:
                    if prev_scope[k] or scope[k]:
                        new_scope[k] = True
                    
            if p not in loops:
                search_locs.append(p)
        

    arg_scope = loc_scope[start_block['loc']]

    return return_scope, arg_scope

def generate_set_of_funcs(binary, entry_point_loc):
    search_locs = [entry_point_loc]
    seen = {}

    functions = []

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        seen[loc] = True
        block_graph = generate_block_graph(binary, loc)
        sub_funcs = collect_functions(block_graph)
        functions += sub_funcs
        for f in sub_funcs:
            if f not in seen and f not in search_locs and f not in skip_functions:
                search_locs.append(f)

    return list(set(functions))


def generate_func_sigs(binary, entry_point_loc):

    search_locs = [entry_point_loc]
    func_call_graph = {}
    func_block_graph = {}
    func_signatures = {}

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block_graph = generate_block_graph(binary, loc)
        func_block_graph[loc] = block_graph
        functions = collect_functions(block_graph)
        func_call_graph[loc] = functions
        for f in functions:
            if f not in func_call_graph and f not in search_locs and f not in skip_functions:
                search_locs.append(f)
   
    funcs = []
    for f in func_call_graph:
        for addnl_f in func_call_graph[f]:
            if addnl_f not in funcs and addnl_f not in skip_functions:
                funcs.append(addnl_f)

    for f in funcs:
        block_graph = func_block_graph[f]
        func_signatures[f] = get_function_signature(block_graph)

    func_comments = {}

    for f in func_signatures:
        fs = func_signatures
        if fs[f][1][b'r3']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( int r0, int r1, int r2, int r3 )'
        elif fs[f][1][b'r2']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( int r0, int r1, int r2 )'
        elif fs[f][1][b'r1']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( int r0, int r1 )'
        elif fs[f][1][b'r0']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( int r0 )'
        elif fs[f][1][b's3']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( float s0, float s1, float s2, float s3 )'
        elif fs[f][1][b's2']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( float s0, float s1, float s2 )'
        elif fs[f][1][b's1']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b'  ( float s0, float s1 )'
        elif fs[f][1][b's0']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( float s0 )'
        elif fs[f][1][b'd1']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( double d0, double d1 )'
        elif fs[f][1][b'd0']:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ( double d0 )'
        else:
            args_type = b'func_' + bytes(hex(f), 'utf-8') + b' ()'

        if fs[f][0][b'r1']:
            return_type = b'long '
        elif fs[f][0][b'r0']:
            return_type = b'int '
        elif fs[f][0][b's0']:
            return_type = b'float '
        elif fs[f][0][b'd0']:
            return_type = b'double '
        else:
            return_type = b'void '

        func_comments[f] = b'; ' + return_type + args_type

    return func_comments

    
if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")
    # parser.add_argument('func_loc', metavar='f', type=int, help="location to decompile")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    binary = f.read()

    f.close()

    output = generate_func_sigs( binary, 0x08020000 + 0xa4f4 )
    # output = generate_asm( binary, 0x08020000 + 0xa4f4 )

    g = open(args.output_file, 'wb')

    g.write(output)
