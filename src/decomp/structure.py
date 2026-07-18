from __future__ import annotations

from .loop_tracker import LoopTracker
from .legacy_types import LegacyBlockGraph, LegacyBlockIndex
from .meta_blocks import (
    EndBlock,
    IfBlock,
    LinearBlock,
    MetaBlock,
    MetaBlockGraph,
    SwitchBlock,
    WhileBlock,
)


class MetaBlockFinder(LoopTracker):

    def __init__(self, block_index: LegacyBlockIndex) -> None:
        self.block_index = block_index
        self.loc_to_loop_end = {}
        self.loc_to_loop_start = {}
        self.loc_to_loop_locs = {}
        self.not_loop_loc = {} # locs which are not in a loop


    def all_seen_are_reachable(self, reachable: list[int], end_loc: int | None) -> bool:
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
                children = [self.block_index[i] for i in block.successors]

                tally[block.address] = True
                visited.append(block.address)
                
                if block.address not in reachable and (not len(children) == 0 or not self.branch_intersects(reachable, block.address)):
                    # print("non-reachable", hex(block['loc']))
                    return False

                for c in children:
                    if c.address not in tally and c not in retrace_nodes and c.address != end_loc:
                        retrace_nodes.append(c) # push

            # print("visited", [hex(v) for v in visited])

        return True


    ## look forward until you find a block through which every other block passes
    ## Q: why can't another location reach this area?
    ## A: Because of where we start (namely, the beginning) and the assumption that 
    ##       this is structured like C code
    def get_next_meta_block_loc(self, start_loc: int, end_loc: int | None = None) -> int | None:
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
                c_locs = self.block_index[loc].successors


                if self.is_loop_start(loc) and loc not in seen_loops:
                    seen_loops[loc] = True

                for c in c_locs:
                    if c not in seen_loops: 
                        paths_index[c] = list(set( paths_index[loc] + [loc] +\
                            (paths_index[c] if c in paths_index else []) ));
                    
                        # if self.is_loop_start(c):
                            # seen_loops[c] = True
                        
                        if loc != end_loc and not (self.is_loop_start(c) and c in seen_loops) and c not in retrace_nodes:
                            retrace_nodes.append(c) # push

                count += 1
                if count > 1024:
                    break
            
            retrace_nodes2 = [start_loc]
            seen_loops2 = {}
            try:
                while len(retrace_nodes2) > 0:
                    loc = retrace_nodes2.pop(0)
                    c_locs = self.block_index[loc].successors
                    
                    # print("checking", hex(loc))
                    # print([hex(v) for v in paths_index[loc]])
                    
                    if not self.is_loop_start(loc) and\
                            not self.is_loop_end(loc) and\
                            self.all_seen_are_reachable(paths_index[loc], loc) and\
                            not (self.get_loop_start(loc) in seen_loops2 and self.can_loop(loc)):
                        if not (len(c_locs) == 1 and len(self.block_index[c_locs[0]].predecessors) == 1):
                            intersection = loc
                            break
                
                    if loc in seen_loops and loc not in seen_loops2:
                        # promote to a seen loop for this cycle
                        seen_loops2[loc] = True

                    if loc != end_loc: # end_loc is not None and 
                        for c in c_locs:
                            if c not in retrace_nodes2 and\
                                not (c in seen_loops2 and self.is_loop_start(c)):
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


def annotate_graph(block_graph: LegacyBlockGraph) -> MetaBlockGraph:
    print('annotate_graph', hex(block_graph.start_block.address))

    start_loc = block_graph.start_block.address
    block_index = block_graph.blocks

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
    seen_locs = {}
    loops = { }

    while len(meta_block_locs) > 0:
        # print("meta_block_locs", [(hex(s),(hex(e) if e is not None else None)) for (s,e) in meta_block_locs])
        start_loc, end_loc = meta_block_locs.pop(-1)
    
        print("annotate loop", hex(start_loc))

        meta_block_loc = start_loc

        seen_locs[start_loc] = True


        # proceed the start block forward to the first condition, and fold into `preface`
        # which we'll either switch into another variable if we thing
        # this is something other than an if, if/then, switch (i.e., while or function endings)
        preface = []

        children_locs = block_index[start_loc].successors
        children = [block_index[c] for c in children_locs]

        # print("pre-eating", hex(start_loc))
        while len(children) == 1 and len(children[0].predecessors) == 1 and children_locs[0] != end_loc:
            preface.append(start_loc)
            start_loc = children_locs[0]
            # print("eating", hex(start_loc))
            seen_locs[start_loc] = True
            children_locs = block_index[start_loc].successors
            children = [block_index[c] for c in children_locs]

        preface.append(start_loc)
        seen_locs[start_loc] = True

        # print("loop block", start_block)

        if len(children) == 2:
            have_not_made_meta_block = meta_block_loc not in meta_block_index
            # print('have not made', have_not_made_meta_block)
            is_loop = mbf.is_loop_start(meta_block_loc)
            # print('is_loop', is_loop)
            have_seen_children = (children_locs[0] in seen_locs or children_locs[1] in seen_locs) and\
                    (meta_block_loc != children_locs[1] and meta_block_loc != children_locs[0]) # loop of 1 block
            # print('have_seen_children', have_seen_children)
            if have_not_made_meta_block and is_loop and not have_seen_children: # children_locs[0] in seen_locs and 
                print('making while', hex(meta_block_loc))
                loop_end_loc = mbf.get_loop_end(meta_block_loc)
                seen_locs[loop_end_loc] = True
                print('loop_end_loc', hex(loop_end_loc))
                next_start_loc = mbf.get_next_meta_block_loc(loop_end_loc, end_loc)
                if next_start_loc is not None:
                    if not (next_start_loc, end_loc) in meta_block_locs and next_start_loc not in seen_locs:
                        meta_block_locs.append((next_start_loc, end_loc))
                    elif next_start_loc in seen_locs:
                        next_start_loc = None
                print('next_start_loc', hex(next_start_loc) if next_start_loc is not None else None)

                meta_block_index[meta_block_loc] = WhileBlock(
                            address=meta_block_loc,
                            inner=None,
                            condition_address=loop_end_loc,
                            next_address=next_start_loc,
                        )
                loops[meta_block_loc] = True
                meta_block_locs.append((meta_block_loc, loop_end_loc))
            else: # elif children_locs[0] not in seen_locs or children_locs[1] not in seen_locs:
                # [true, false] == c[0], c[1]
                
                if meta_block_loc != mbf.get_loop_end(meta_block_loc):
                    print("making if", hex(meta_block_loc))
                    
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
                    
                    print("block temp tflocs", hex(temp_true_loc), hex(temp_false_loc))
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
                   
                    print("true_loc, false_loc, next_start_loc", 
                            hex(true_loc) if true_loc is not None else None,
                            hex(false_loc) if false_loc is not None else None,
                            hex(next_start_loc) if next_start_loc is not None else None)
                    if meta_block_loc in meta_block_index and isinstance(meta_block_index[meta_block_loc], WhileBlock):
                        meta_block_index[meta_block_loc].inner = IfBlock(
                                address=meta_block_loc,
                                condition_blocks=preface,
                                flags=[True],
                                conjunctions=[],
                                true_address=true_loc,
                                false_address=false_loc,
                                next_address=next_start_loc,
                                )
                    else:
                        meta_block_index[meta_block_loc] = IfBlock(
                                address=meta_block_loc,
                                condition_blocks=preface,
                                flags=[True],
                                conjunctions=[],
                                true_address=true_loc,
                                false_address=false_loc,
                                next_address=next_start_loc,
                                )
                else:
                    pass
        elif len(children) > 2:
            # print('making tbb node', hex(meta_block_loc))

            for c in children_locs:
                if (c, end_loc) not in meta_block_locs and c not in seen_locs:
                    meta_block_locs.append((c, end_loc))

            meta_block_index[meta_block_loc] = SwitchBlock(
                    address=meta_block_loc,
                    preface=preface,
                    cases=tuple(children_locs),
                    next_address=end_loc,
                    )

        elif len(children) == 1:
            print("making block node", hex(meta_block_loc))

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

            print('next_loc', hex(next_loc) if next_loc is not None else None)
            print('next_end', hex(next_end) if next_end is not None else None)
            print('end_loc', hex(end_loc) if end_loc is not None else None)

            if next_end is not None or (next_end is None and end_loc is None):
                meta_block_index[meta_block_loc] = LinearBlock(
                            address=meta_block_loc,
                            block_addresses=blocks,
                            next_address=next_loc,
                        )

            else:
                # print('no next')
                meta_block_index[meta_block_loc] = LinearBlock(
                            address=meta_block_loc,
                            block_addresses=blocks,
                            next_address=None,
                        )
            

        elif len(children) == 0:
           # print('making end_node')
            meta_block_index[meta_block_loc] = EndBlock(
                        address=meta_block_loc,
                        block_addresses=preface,
                    )
        else:
            raise Exception

    return MetaBlockGraph(
            block_index=block_index,
            meta_blocks=meta_block_index,
            entry_address=meta_block_start,
            )

def simplify_if(meta_block_graph: MetaBlockGraph) -> MetaBlockGraph:
    meta_index = meta_block_graph.meta_blocks
    start = meta_block_graph.entry_address

    seen_loops = {} # prevent loops...

    def simplify_base_node(node: MetaBlock) -> int | None:
        if isinstance(node, IfBlock):
            # print("if node")
            cond = node.condition_blocks
            # true and false get switched when written
            true_loc = node.false_address
            false_loc = node.true_address
            # descend down the true side to track if true and false of the child
            # match up with the false loc of the parent (i.e., total of 2 unique locs not 3)
            # and simplify

            true_node = meta_index[true_loc] if true_loc is not None else None
            
            if isinstance(true_node, IfBlock):
                # print('checking if for simplification')
                child_true_loc = true_node.false_address
                child_false_loc = true_node.true_address
                child_next_loc = true_node.next_address

               
                # print('child_true_loc', hex(child_true_loc) if child_true_loc is not None else None)
                # print('child_false_loc', hex(child_false_loc) if child_false_loc is not None else None)
                # print('child_next_loc', hex(child_next_loc) if child_next_loc is not None else None)

                # if it's a conjunction it would not have a next, only the parent can have a next
                if child_next_loc is None and child_true_loc == false_loc: 
                    # print('simplifying')
                    node.condition_blocks += true_node.condition_blocks
                    node.false_address = child_false_loc
                    node.conjunctions += [b' && '] + [b' && ' if c == b' || ' else b' || ' for c in true_node.conjunctions]
                    node.flags = node.flags + true_node.flags.copy()
                    # repeat this until there are no simplifications
                    node_loc = node.address
                elif child_next_loc is None and child_false_loc == false_loc:
                    # print('simplifying')
                    node.condition_blocks += true_node.condition_blocks
                    node.false_address = child_true_loc
                    node.conjunctions += [b' && '] + true_node.conjunctions
                    node.flags = node.flags + true_node.flags.copy()
                    
                    # repeat this until there are no simplifications
                    node_loc = node.address
                else:
                    if true_loc is not None:
                        simplify_node_loc(true_loc)
                    if false_loc is not None:
                        simplify_node_loc(false_loc)

                    node_loc = node.next_address
            else:
                if true_loc is not None:
                    simplify_node_loc(true_loc)
                if false_loc is not None:
                    simplify_node_loc(false_loc)
                node_loc = node.next_address


        elif isinstance(node, WhileBlock):
            raise Exception # don't think we should come here, but otherwise pass

        elif isinstance(node, LinearBlock):
            node_loc = node.next_address
            # print('next node_loc', node_loc)

        elif isinstance(node, EndBlock):
            node_loc = None
        
        elif isinstance(node, SwitchBlock):
            for c in node.cases:
                simplify_node_loc(c)

            node_loc = node.next_address
        else:
            raise Exception
        return node_loc

    def simplify_node(node: MetaBlock | None) -> None:
        while node is not None:
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if isinstance(node, WhileBlock):
                node_loc = node.address
                seen_loops[node_loc] = True
                simplify_node(node.inner)
                
                node_loc = node.next_address
            else:
                node_loc = simplify_base_node(node)
            
            # if node_loc is not None:
                # # print("simplify node next", hex(node_loc))
            
            # else:
                # print("simplify node end")
            
            node = meta_index[node_loc] if node_loc is not None else None
        return None

    def simplify_node_loc(node_loc: int) -> None:
        # print("simplify node_loc", hex(node_loc))
        node = meta_index[node_loc]
        return simplify_node(node)

    # print('start simplify')

    simplify_node_loc(start)

    # print('done simplify')

    return meta_block_graph
