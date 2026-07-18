import argparse

from .instructions import *
from .function_signatures import generate_func_sigs, add_function_sigs, get_function_signature
from .block_graph import generate_block_graph
from .legacy_types import LegacyBlock, LegacyBlockGraph, LegacyBlockIndex
from .meta_blocks import EndBlock, IfBlock, LinearBlock, MetaBlock, MetaBlockGraph, SwitchBlock, WhileBlock
from .structure import annotate_graph, simplify_if


def print_block(block: LegacyBlock) -> bytes:
    prefix = b'/*' + bytes(hex(block.address), 'utf-8') + b'\n'
    suffix = b'\n*/\n'

    insns = [list(filter(lambda a: isinstance(a, bytes), i)) for i in block.instructions]

    body = b'\n'.join( [b' '.join(insn) for insn in insns] )

    return prefix + body + suffix

def print_if_cond(
    cond: list[int],
    conj: list[bytes],
    flags: list[bool],
    block_index: LegacyBlockIndex,
) -> tuple[bytes, bytes]:

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
            insns = list(block.instructions)
            insns.reverse()
        else:
            need_moar = False
            block = block_index[c]
            block_out = print_block(block)
            new_insns = list(block.instructions)
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
                    if insn_1[3] in compare + ncompare + tst:
                        comp_reg1 = insn_1[4].rstrip(b',')
                        comp_reg2 = insn_1[5].lstrip(b'#').rstrip(b',')
                        comp = insn_0[3]
                        break
                    elif insn_1[3] in modifies_NCVZ:
                        comp_reg1 = crs(insn_1[4])
                        comp_reg2 = b'0'
                        comp = insn_0[3]
                        break
                    
                nzcv_set = None
                # try for floating point
                if comp is None:
                    print('try floating point')
                    for j in range(i, len(insns)):
                        insn_1 = insns[j]
                        print(insn_1)
                    
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

def generate_func_cf_from_graph(meta_block_graph: MetaBlockGraph) -> bytes:
    block_index = meta_block_graph.block_index
    meta_index = meta_block_graph.meta_blocks
    start = meta_block_graph.entry_address

    seen_loops = {} # prevent loops...

    def print_base_node(node: MetaBlock) -> tuple[int | None, bytes]:
        out = b''
        if isinstance(node, IfBlock):
            # print("if node")
            cond = node.condition_blocks
            conj = node.conjunctions
            flags = node.flags

            cond_block_out, cond_expr = print_if_cond(cond, conj, flags, block_index)

            true_loc = node.false_address
            false_loc = node.true_address
            if true_loc is None or true_loc == node.next_address or true_loc in seen_loops:
                true_out = b'if ( ' + cond_expr + b' ) \n{\n\n}\n'
            else:
                true_out = b'if ( ' + cond_expr + b' ) \n{\n' + print_node_loc(true_loc) + b'\n}\n'

            if false_loc is None or false_loc == node.next_address or false_loc in seen_loops or false_loc is None:
                false_out = b''
            else:
                false_out = b'else\n{\n' + print_node_loc(false_loc) + b'\n}\n'


            out += (cond_block_out + true_out + false_out)
            node_loc = node.next_address

        elif isinstance(node, WhileBlock):
            raise Exception # don't think we should come here, but otherwise pass

        elif isinstance(node, LinearBlock):
            block_out = b'\n'.join( [print_block(block_index[b]) for b in node.block_addresses] )

            out += block_out
            node_loc = node.next_address
            # print('next node_loc', node_loc)

        elif isinstance(node, EndBlock):
            end_out = b'\n'.join( [print_block(block_index[b]) for b in node.block_addresses] )
            end_out += b'\nreturn;\n'
            out += end_out
            node_loc = None
        elif isinstance(node, SwitchBlock):
            c_out = b''
            for (i,c) in enumerate(node.cases):
                c_out += b'\ncase ' + bytes(str(i), 'utf-8') + b':\n' + print_node_loc(c)

            block_out = b'\n'.join([print_block(block_index[i]) for i in node.preface])

            switch_insn = block_index[node.preface[-1]].instructions[-1]
            switch_var = crs(switch_insn[5])


            out += block_out + b'\nswitch(' + switch_var + b') \n{\n' + c_out + b'\n}\n'
            node_loc = node.next_address
        else:
            print("node", node)
            raise Exception
        return node_loc, out

    def print_node(node: MetaBlock | None) -> bytes:
        out = b''
        while node is not None:
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if isinstance(node, WhileBlock):
                # print("while node")
                node_loc = node.address
                seen_loops[node_loc] = True
                inner = node.inner
                cond = node.condition_address
                while_out = print_node(inner)
                cond_out,cond_expr = print_if_cond([cond], [], [True], block_index)
                while_out = b'while (1) \n{\n' + while_out + cond_out +\
                        b'if ( ' + cond_expr + b' ) {\n break;\n }\n' +\
                        b'\n}\n'
                out += while_out
                
                node_loc = node.next_address
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

    def print_node_loc(node_loc: int) -> bytes:
        # print("node_loc", hex(node_loc))
        node = meta_index[node_loc]
        return print_node(node)

    return print_node_loc(start)

def generate_func_decl(block_graph: LegacyBlockGraph) -> bytes:
    start = block_graph.start_block.address


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
def generate_func_cf_asm(binary: bytes, entry_point_loc: int = 0x08020004) -> bytes:
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
