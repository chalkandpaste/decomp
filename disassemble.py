import argparse

from loop_tracker import LoopTracker
from instructions import *
from function_signatures import generate_func_sigs, add_function_sigs, get_function_signature
from block_graph import generate_block_graph, print_block_graph


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
                
                if block['loc'] not in reachable and (not len(children) == 0 or not self.branch_intersects(reachable, block['loc'])):
                    # print("non-reachable", hex(block['loc']))
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
            return end_loc
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


                if self.is_loop_start(loc) and loc not in seen_loops:
                    seen_loops[loc] = True

                for c in c_locs:
                    if c not in seen_loops: 
                        paths_index[c] = list(set( paths_index[loc] + [loc] +\
                            (paths_index[c] if c in paths_index else []) ));
                    
                        if self.is_loop_start(c):
                            seen_loops[c] = True
                        
                        if loc != end_loc: # and c not in seen_loops:
                            retrace_nodes.append(c) # push

                count += 1
                if count > 1024:
                    break
            
            retrace_nodes2 = [start_loc]
            tally2 = { }
            seen_loops2 = {}
            try:
                while len(retrace_nodes2) > 0:
                    loc = retrace_nodes2.pop(0)
                    c_locs = self.block_index[loc]['children']
                    
                    tally2[loc] = True # visited
                    
                    print("checking", hex(loc))
                    # print([hex(v) for v in paths_index[loc]])

                    
                    if not self.is_loop_start(loc) and not self.is_loop_end(loc) and self.all_seen_are_reachable(paths_index[loc], loc):
                        if len(c_locs) != 1 or len(self.block_index[c_locs[0]]['parents']) != 1:
                            intersection = loc
                            break
                
                    if loc in seen_loops and loc not in seen_loops2:
                        seen_loops2[loc] = True

                    if end_loc is None or loc != end_loc:
                        for c in c_locs:
                            if c not in retrace_nodes2 and c not in tally2 and not self.is_loop_start(c): # if it hasn't been visited
                                # TODO check for end blocks?
                                retrace_nodes2.append(c) # push
            except:
                # print('exception1')
                continue
            if len(retrace_nodes) == 0 and not check:
                # print('pass1')
                check = True
            elif len(retrace_nodes) == 0 and check:
                # print("early return")
                # for k in paths_index:
                    # print(hex(k), [hex(v) for v in paths_index[k]])
                
                # print([hex(k) for k in seen_loops])
                    
                return None
            else:
                pass

        return intersection


def annotate_graph(block_graph):
    print('annotate_graph', hex(block_graph['start_block']['loc']))

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
        # print("meta_block_locs", [(hex(s),(hex(e) if e is not None else None)) for (s,e) in meta_block_locs])
        start_loc, end_loc = meta_block_locs.pop(-1)
    
        start_block = block_index[start_loc]

        # print("annotate loop", hex(start_loc))

        meta_block_loc = start_loc

        seen_locs[start_loc] = True


        # proceed the start block forward to the first condition, and fold into `preface`
        # which we'll either switch into another variable if we thing
        # this is something other than an if, if/then, switch (i.e., while or function endings)
        preface = []

        children_locs = block_index[start_loc]['children']
        children = [block_index[c] for c in children_locs]

        # print("pre-eating", hex(start_loc))
        while len(children) == 1 and len(children[0]['parents']) == 1 and children_locs[0] != end_loc:
            preface.append(start_loc)
            # print("add to preface", hex(start_block['loc']))
            start_loc = children_locs[0]
            # print("eating", hex(start_loc))
            seen_locs[start_loc] = True
            children_locs = block_index[start_loc]['children']
            children = [block_index[c] for c in children_locs]

        preface.append(start_loc)
        seen_locs[start_loc] = True

        # print("loop block", start_block)

        if len(children) == 2:
            have_not_made_meta_block = meta_block_loc not in meta_block_index
            # print('have not made', have_not_made_meta_block)
            is_loop = mbf.can_loop(meta_block_loc)
            # print('is_loop', is_loop)
            have_seen_children = (children_locs[0] in seen_locs or children_locs[1] in seen_locs) and\
                    (meta_block_loc != children_locs[1] and meta_block_loc != children_locs[0]) # loop of 1 block
            # print('have_seen_children', have_seen_children)
            if have_not_made_meta_block and is_loop and not have_seen_children: # children_locs[0] in seen_locs and 
                # print('making while', hex(children_locs[0]), hex(meta_block_loc))
                loop_end_loc = mbf.get_loop_end(meta_block_loc)
                seen_locs[loop_end_loc] = True
                # print('loop_end_loc', hex(loop_end_loc))
                next_start_loc = mbf.get_next_meta_block_loc(loop_end_loc, end_loc)
                if next_start_loc is not None:
                    if not (next_start_loc, end_loc) in meta_block_locs and next_start_loc not in seen_locs:
                        meta_block_locs.append((next_start_loc, end_loc))
                    elif next_start_loc in seen_locs:
                        next_start_loc = None
                # print('next_start_loc', hex(next_start_loc) if next_start_loc is not None else None)

                meta_block_index[meta_block_loc] = {
                            'type' : 'while',
                            'loc' : meta_block_loc,
                            'inner' : None,
                            'cond' : loop_end_loc, 
                            'next' : next_start_loc
                        }
                loops[meta_block_loc] = True
                meta_block_locs.append((meta_block_loc, loop_end_loc))
            else: # elif children_locs[0] not in seen_locs or children_locs[1] not in seen_locs:
                # [true, false] == c[0], c[1]
                
                if meta_block_loc != mbf.get_loop_end(meta_block_loc):
                    # print("making if", hex(meta_block_loc))
                    
                    next_start_loc = None
                    # if the end_loc is None we are at the end so may be true/false but no "nexts"
                    # if we aren't at the end_loc, then there is a next
                    if meta_block_loc != end_loc: #  end_loc is not None and 
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
                                    # print('2')
                                    next_start_loc = None
                            else:
                                # print('3')
                                if next_start_loc == mbf.get_loop_end(next_start_loc) or\
                                        next_start_loc in seen_locs:
                                    # print('3.1')
                                    next_start_loc = None
                    
                    child_end_loc = end_loc if next_start_loc is None else next_start_loc
                   
                    # for both true/false we want to check if the children are the immediate
                    # end, having determined if there is a next block above, and if they
                    # are, skip them.
                    temp_true_loc = children_locs[0]
                    temp_false_loc = children_locs[1]
                    true_loc = None
                    false_loc = None
                    
                    # print("block temp tflocs", hex(temp_true_loc), hex(temp_false_loc))
                    if temp_true_loc != child_end_loc:
                        if temp_true_loc not in loops:
                            true_end_loc = mbf.get_next_meta_block_loc(temp_true_loc, child_end_loc)
                            if (true_end_loc != child_end_loc and child_end_loc is not None) or\
                                    ((true_end_loc is None and end_loc is None) or\
                                    true_end_loc is not None):
                                if true_loc not in seen_locs:
                                    true_loc = temp_true_loc
                                    seen_locs[true_loc] = True
                                    meta_block_locs.append((true_loc, child_end_loc))
                                
                    if temp_false_loc != child_end_loc:
                        if temp_false_loc not in loops:
                            false_end_loc = mbf.get_next_meta_block_loc(temp_false_loc, child_end_loc)
                            if (false_end_loc != child_end_loc or child_end_loc is not None) or\
                                    ((false_end_loc is None and end_loc is None) or\
                                    false_end_loc is not None): ## there is no endpoint/subgraph
                                if false_loc not in seen_locs :
                                    false_loc = temp_false_loc
                                    seen_locs[false_loc] = True
                                    if (false_loc, false_end_loc) not in meta_block_locs:
                                        meta_block_locs.append((false_loc, child_end_loc))
                   
                    # print("true_loc, false_loc, next_start_loc", 
                            # hex(true_loc) if true_loc is not None else None,
                            # hex(false_loc) if false_loc is not None else None,
                            # hex(next_start_loc) if next_start_loc is not None else None)
                    if meta_block_loc in meta_block_index and meta_block_index[meta_block_loc]['type'] == 'while':
                        meta_block_index[meta_block_loc]['inner'] = {
                                'type' : 'if',
                                'loc'  : meta_block_loc,
                                'cond' : preface,
                                'flag' : [True],
                                'conj' : [],
                                'true' : true_loc,
                                'false': false_loc,
                                'next' : next_start_loc
                                }
                    else:
                        meta_block_index[meta_block_loc] = {
                                'type' : 'if',
                                'loc'  : meta_block_loc,
                                'cond' : preface,
                                'flag' : [True],
                                'conj' : [],
                                'true' : true_loc,
                                'false': false_loc,
                                'next' : next_start_loc
                                }
                else:
                    pass
        elif len(children) > 2:
            # print('making tbb node', hex(meta_block_loc))

            for c in children_locs:
                if (c, end_loc) not in meta_block_locs and c not in seen_locs:
                    meta_block_locs.append((c, end_loc))

            meta_block_index[meta_block_loc] = {
                    'type' : 'tbb',
                    'loc' : meta_block_loc,
                    'preface' : preface,
                    'cases': children_locs,
                    'next' : end_loc
                    }

        elif len(children) == 1:
            # print("making block node", hex(meta_block_loc))

            blocks = preface
            
            next_loc = children_locs[0]
            
            next_end = None
            # print('11')
            if next_loc != end_loc: # end_loc is not None and 
                # print('1i1')
                next_end = mbf.get_next_meta_block_loc(next_loc, end_loc)
                if (next_end is not None or (next_end is None and end_loc is None)) and next_end != next_loc:
                    # print('1i2')
                    if next_loc not in seen_locs:
                        # print('2i2')
                        seen_locs[next_loc] = True
                        if (next_loc,end_loc) not in meta_block_locs :
                            # print('2i3')
                            meta_block_locs.append((next_loc, end_loc))
                    # else:
                        # print('1o1')
                        # next_loc = None
                else:
                    # print('1o2')
                    if next_loc == mbf.get_loop_end(next_loc) or\
                            next_loc in seen_locs:
                        next_loc = None
                        # print('1o3')
                    # if next_loc in seen_locs and (next_loc,end_loc) not in meta_block_locs:
                        # print((hex(next_loc), hex(end_loc)))
                        # raise Exception

            # print('next_loc', hex(next_loc) if next_loc is not None else None)
            # print('next_end', hex(next_end) if next_end is not None else None)
            # print('end_loc', hex(end_loc) if end_loc is not None else None)

            if next_end is not None or (next_end is None and end_loc is None):
                meta_block_index[meta_block_loc] = {
                            'type' : 'block',
                            'loc' : meta_block_loc,
                            'blocks' : blocks,
                            'next' : next_loc
                        }

            else:
                # print('no next')
                meta_block_index[meta_block_loc] = {
                            'type' : 'block',
                            'loc' : meta_block_loc,
                            'blocks' : blocks,
                            'next' : None
                        }
            

        elif len(children) == 0:
           # print('making end_node')
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

def simplify_if(meta_block_graph):
    block_index = meta_block_graph['index']
    meta_index = meta_block_graph['meta_block_index']
    start = meta_block_graph['start_block']

    seen_loops = {} # prevent loops...

    start_node = meta_index[start]

    def simplify_base_node(node):
        out = b''
        ty = node['type']
        if ty == 'if':
            # print("if node")
            cond = node['cond']
            # true and false get switched when written
            true_loc = node['false']
            false_loc = node['true']
            # print("node tf_locs", hex(true_loc) if true_loc is not None else None,
                    # hex(false_loc) if false_loc is not None else None,
                    # hex(node['next']) if node['next'] is not None else None)
            
            # descend down the true side to track if true and false of the child
            # match up with the false loc of the parent (i.e., total of 2 unique locs not 3)
            # and simplify

            true_node = meta_index[true_loc] if true_loc is not None else None
            
            if true_node is not None and true_node['type'] == 'if':
                # print('checking if for simplification')
                child_true_loc = true_node['false']
                child_false_loc = true_node['true']
                child_next_loc = true_node['next']

               
                # print('child_true_loc', hex(child_true_loc) if child_true_loc is not None else None)
                # print('child_false_loc', hex(child_false_loc) if child_false_loc is not None else None)
                # print('child_next_loc', hex(child_next_loc) if child_next_loc is not None else None)

                # if it's a conjunction it would not have a next, only the parent can have a next
                if child_next_loc is None and child_true_loc == false_loc: 
                    # print('simplifying')
                    node['cond'] += true_node['cond']
                    node['false'] = child_false_loc
                    node['conj'] += [b' && '] + [b' && ' if c == b' || ' else b' || ' for c in true_node['conj']]
                    node['flag'] = node['flag'] + true_node['flag'].copy()
                    # repeat this until there are no simplifications
                    node_loc = node['loc']
                elif child_next_loc is None and child_false_loc == false_loc:
                    # print('simplifying')
                    node['cond'] += true_node['cond']
                    node['false'] = child_true_loc
                    node['conj'] += [b' && '] + true_node['conj']
                    node['flag'] = node['flag'] + true_node['flag'].copy()
                    
                    # repeat this until there are no simplifications
                    node_loc = node['loc']
                else:
                    if true_loc is not None:
                        simplify_node_loc(true_loc)
                    if false_loc is not None:
                        simplify_node_loc(false_loc)

                    node_loc = node['next']
            else:
                if true_loc is not None:
                    simplify_node_loc(true_loc)
                if false_loc is not None:
                    simplify_node_loc(false_loc)
                node_loc = node['next']


            # if node['next'] is not None:
                # # print("if node_next:", hex(node_loc))
            # else:
                # print("if end")

        elif ty == 'while':
            raise Exception # don't think we should come here, but otherwise pass
            pass

        elif ty == 'block':
            node_loc = node['next']
            # print('next node_loc', node_loc)

        elif ty == 'end':
            node_loc = None
        
        elif ty == 'tbb':
            for c in node['cases']:
                simplify_node_loc(c)

            node_loc = node['next']
        else:
            # print("node", node)
            # print(node['type'])
            raise Exception
        return node_loc

    def simplify_node(node):
        while node is not None:
            ty = node['type']
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if ty == 'while':
                node_loc = node['loc']
                seen_loops[node_loc] = True
                simplify_node(node['inner'])
                
                node_loc = node['next']
            else:
                node_loc = simplify_base_node(node)
            
            # if node_loc is not None:
                # # print("simplify node next", hex(node_loc))
            
            # else:
                # print("simplify node end")
            
            node = meta_index[node_loc] if node_loc is not None else None
        return None

    def simplify_node_loc(node_loc):
        # print("simplify node_loc", hex(node_loc))
        node = meta_index[node_loc]
        return simplify_node(node)

    # print('start simplify')

    simplify_node_loc(start)

    # print('done simplify')

    return meta_block_graph

def print_block(block):
    prefix = b'/*' + bytes(hex(block['loc']), 'utf-8') + b'\n'
    suffix = b'\n*/\n'

    insns = [list(filter(lambda a: isinstance(a, bytes), i)) for i in block['block']]

    body = b'\n'.join( [b' '.join(insn) for insn in insns] )

    return prefix + body + suffix

def print_if_cond(cond, conj, flags, block_index):

    cond_out = b''
    cond_exprs = []
    count = 0

    # print('cond', [hex(c) for c in cond])

    conds = cond.copy()
    conds.reverse()

    need_moar = False
    for c in conds:
        if not need_moar:
            block = block_index[c]
            block_out = print_block(block)
            insns = block['block'].copy()
            insns.reverse()
        else:
            need_moar = False
            block = block_index[c]
            block_out = print_block(block)
            new_insns = block['block'].copy()
            new_insns.reverse()

            insns = insns + new_insns


        # print(insns)
        # print(cond_out)

        comp_out = None
        for i in range(len(insns)):
            insn_0 = insns[i]
            if insn_0[3] in cond_block_end_zero:
                # this changes checks condition (sets NZCV)
                # and sets PC to the new loc
                comp_reg = insn_0[4].rstrip(b',')
                comp = False if insn_0[3] == b'cbz' else True
                if comp:
                    comp_out = comp_reg + b' == 0'
                else:
                    comp_out = comp_reg + b' != 0'
                
                comp_out = b'cond' + bytes(str(count), 'utf-8') + b' = ' + comp_out + b';'
                
                break

            elif insn_0[3] in cond_block_end:
                # we have the condition but not the operations
                # so search backwards for the cmp operation
                # which could either be normal or FP
                comp = None

                for j in range(i, len(insns)):
                    insn_1 = insns[j]
                    if insn_1[3] in compare + ncompare:
                        comp_reg1 = insn_1[4].rstrip(b',')
                        comp_reg2 = insn_1[5].lstrip(b'#').rstrip(b',')
                        comp = insn_0[3]
                        break
                    
                nzcv_set = None
                # try for floating point
                if comp is None:

                    for j in range(i, len(insns)):
                        insn_1 = insns[j]
                    
                        if insn_1[3] == b'vmrs' and insn_1[4] == b'APSR_nzcv,' and insn_1[5] == b'fpscr':
                            nzcv_set = True

                        if insn_1[3] in fp_compare and nzcv_set:
                            comp_reg1 = insn_1[4].rstrip(b',')
                            comp_reg2 = insn_1[5].lstrip(b'#').rstrip(b',')
                            comp = insn_0[3]
                    
                    if nzcv_set is None:
                        nzcv_set = False
                
                if not nzcv_set and nzcv_set is not None:
                    need_moar = True
                else:
                    if comp in beq:
                        comp_out = comp_reg1 + b' != ' + comp_reg2
                    elif comp in bne:
                        comp_out = comp_reg1 + b' == ' + comp_reg2
                    elif comp in blt:
                        comp_out = comp_reg1 + b' >= ' + comp_reg2
                    elif comp in ble:
                        comp_out = comp_reg1 + b' > ' + comp_reg2
                    elif comp in bgt:
                        comp_out = comp_reg1 + b' <= ' + comp_reg2
                    elif comp in bge:
                        comp_out = comp_reg1 + b' < ' + comp_reg2
                    else:
                        print(comp)
                        raise Exception

                    comp_out = b'cond' + bytes(str(count), 'utf-8') + b' = ' + comp_out + b';'

        if comp_out is not None:
            cond_out = block_out + comp_out + b'\n' + cond_out
            cond_exprs.append(b'cond' + bytes(str(count), 'utf-8'))
            count += 1
        else:
            cond_out += block_out

    cond_expr = b''
    if len(cond_exprs) - 1 != len(conj) or len(cond_exprs) != len(flags) or len(cond_exprs) == 0:
        print(cond)
        print(flags)
        print(cond_exprs)
        print(conj)
        raise Exception # something is off
    if len(cond_exprs) == 1:
        cond_expr = cond_exprs[0]
    else:
        for i in range(0, len(cond_exprs)-1):
            ce = cond_exprs[-1-i]
            if not flags[-1-i]:
                ce = b'~(' + ce + b')'
            cond_expr += ce + conj[-1-i]
        if flags[0]:
            cond_expr += b'~(' + cond_exprs[0] + b')'
        else:
            cond_expr += cond_exprs[0] 

    return cond_out, cond_expr

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
            # print("if node")
            cond = node['cond']
            conj = node['conj'] if 'conj' in node else []
            flags = node['flag'] if 'flag' in node else []

            cond_block_out, cond_expr = print_if_cond(cond, conj, flags, block_index)

            true_loc = node['false']
            false_loc = node['true']
            # print("node tf_locs", hex(true_loc) if true_loc is not None else None,
                    # hex(false_loc) if false_loc is not None else None,
                    # hex(node['next']) if node['next'] is not None else None)
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
            # if node['next'] is not None:
                # # print("if node_next:", hex(node_loc))
            # else:
                # print("if end")

        elif ty == 'while':
            raise Exception # don't think we should come here, but otherwise pass
            pass

        elif ty == 'block':
            block_out = b'\n'.join( [print_block(block_index[b]) for b in node['blocks']] )

            out += block_out
            node_loc = node['next']
            # print('next node_loc', node_loc)

        elif ty == 'end':
            end_out = b'\n'.join( [print_block(block_index[b]) for b in node['blocks']] )
            out += end_out
            node_loc = None
        elif ty == 'tbb':
            c_out = b''
            for (i,c) in enumerate(node['cases']):
                c_out += b'\ncase ' + bytes(str(i), 'utf-8') + b':\n' + print_node_loc(c)

            block_out = b'\n'.join([print_block(block_index[i]) for i in node['preface']])

            switch_insn = block_index[node['preface'][-1]]['block'][-1]
            switch_var = crs(switch_insn[5])


            out += block_out + b'\nswitch(' + switch_var + b') \n{\n' + c_out + b'\n}\n'
            node_loc = node['next']
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
                # print("while node")
                node_loc = node['loc']
                seen_loops[node_loc] = True
                inner = node['inner']
                cond = node['cond']
                while_out = print_node(inner)
                cond_out = print_block(block_index[cond]) # print_base_node(cond)
                while_out = b'while (1) \n{\n' + while_out + cond_out + b'\n}\n'
                out += while_out
                
                node_loc = node['next']
            else:
                # print("base node")
                node_loc, base_out = print_base_node(node)

                out += base_out

            # if node_loc is not None:
                # # print("node next", hex(node_loc))
            # else:
                # print("node end")
            
            node = meta_index[node_loc] if node_loc is not None else None
        return out

    def print_node_loc(node_loc):
        # print("node_loc", hex(node_loc))
        node = meta_index[node_loc]
        return print_node(node)

    return print_node_loc(start)

def generate_func_decl(block_graph):
    start = block_graph['start_block']['loc']


    fs = get_function_signature(block_graph)
    if fs[1][b'r3']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( int r0, int r1, int r2, int r3 )'
    elif fs[1][b'r2']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( int r0, int r1, int r2 )'
    elif fs[1][b'r1']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( int r0, int r1 )'
    elif fs[1][b'r0']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( int r0 )'
    elif fs[1][b's3']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( float s0, float s1, float s2, float s3 )'
    elif fs[1][b's2']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( float s0, float s1, float s2 )'
    elif fs[1][b's1']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b'  ( float s0, float s1 )'
    elif fs[1][b's0']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( float s0 )'
    elif fs[1][b'd1']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( double d0, double d1 )'
    elif fs[1][b'd0']:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ( double d0 )'
    else:
        args_type = b'func_' + bytes(hex(start), 'utf-8') + b' ()'

    if fs[0][b'r1']:
        return_type = b'long '
    elif fs[0][b'r0']:
        return_type = b'int '
    elif fs[0][b's0']:
        return_type = b'float '
    elif fs[0][b'd0']:
        return_type = b'double '
    else:
        return_type = b'void '

    return return_type + args_type

# default to the RESET location on ARM M4
def generate_func_cf_asm(binary, entry_point_loc=0x08020004):
    print('generate_func_cf_asm', hex(entry_point_loc))

    func_sigs = generate_func_sigs(binary, entry_point_loc)

    block_graph = generate_block_graph(binary, entry_point_loc)

    block_graph = add_function_sigs(block_graph, func_sigs)

    func_decl = generate_func_decl(block_graph)

    annotated_graph = annotate_graph(block_graph)

    annotated_graph = simplify_if(annotated_graph)
    
    cf = generate_func_cf_from_graph(annotated_graph)

    out = func_decl +b'{\n' + cf + b'\n}'

    return out

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")
    parser.add_argument('func_loc', metavar='f', type=str, help="location to decompile")


    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    binary = f.read()

    f.close()
    
    loc = int(args.func_loc, 0)

    output = generate_func_cf_asm( binary, loc )
    # output = generate_asm( binary, 0x08020000 + 0xa4f4 )

    g = open(args.output_file, 'wb')

    g.write(output)
