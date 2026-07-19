from __future__ import annotations

from collections.abc import Sequence
from dataclasses import dataclass

from .function_signatures import get_function_signature, render_function_declaration
from .instructions import (
    beq,
    bge,
    bgt,
    ble,
    blt,
    bne,
    compare,
    cond_block_end,
    cond_block_end_zero,
    crs,
    fp_compare,
    modifies_NCVZ,
    ncompare,
    tst,
)
from .legacy_instruction import mnemonic, operand_bytes
from .legacy_types import LegacyBlock, LegacyBlockGraph, LegacyInstruction
from .meta_blocks import EndBlock, IfBlock, LinearBlock, MetaBlock, MetaBlockGraph, SwitchBlock, WhileBlock


@dataclass(frozen=True)
class RenderedCondition:
    setup: bytes
    expression: bytes


@dataclass(frozen=True)
class RenderedNodeStep:
    next_address: int | None
    body: bytes


def print_block(block: LegacyBlock) -> bytes:
    prefix = b'/*' + bytes(hex(block.address), 'utf-8') + b'\n'
    suffix = b'\n*/\n'

    insns = [list(filter(lambda a: isinstance(a, bytes), i)) for i in block.instructions]

    body = b'\n'.join( [b' '.join(insn) for insn in insns] )

    return prefix + body + suffix


def render_condition(
    cond: Sequence[int],
    conj: Sequence[bytes],
    flags: Sequence[bool],
    meta_block_graph: MetaBlockGraph,
) -> RenderedCondition:

    cond_out = b''
    cond_exprs: list[bytes] = []
    count = 0

    # print('cond', [hex(c) for c in cond])

    conds = list(cond)
    conds.reverse()

    need_moar = False
    for c in conds:
        if not need_moar:
            block = meta_block_graph.source_block_at(c)
            block_out = print_block(block)
            insns = list(block.instructions)
            insns.reverse()
        else:
            need_moar = False
            block = meta_block_graph.source_block_at(c)
            block_out = print_block(block)
            new_insns = list(block.instructions)
            new_insns.reverse()

            insns = insns + new_insns


        # print(insns)
        # print(cond_out)

        comp_out = None
        for i in range(len(insns)):
            insn_0 = insns[i]
            insn_0_mnemonic = mnemonic(insn_0)
            if insn_0_mnemonic in cond_block_end_zero:
                # this changes checks condition (sets NZCV)
                # and sets PC to the new loc
                comp_reg = _operand_without_trailing_comma(insn_0, 0)
                comp = False if insn_0_mnemonic == b'cbz' else True
                if comp:
                    comp_out = comp_reg + b' == 0'
                else:
                    comp_out = comp_reg + b' != 0'
                
                comp_out = b'cond' + bytes(str(count), 'utf-8') + b' = ' + comp_out + b';'
                
                break

            elif insn_0_mnemonic in cond_block_end:
                # we have the condition but not the operations
                # so search backwards for the cmp operation
                # which could either be normal or FP
                comp = None

                for j in range(i, len(insns)):
                    insn_1 = insns[j]
                    insn_1_mnemonic = mnemonic(insn_1)
                    if insn_1_mnemonic in compare + ncompare + tst:
                        comp_reg1 = _operand_without_trailing_comma(insn_1, 0)
                        comp_reg2 = _condition_operand(insn_1, 1)
                        comp = insn_0_mnemonic
                        break
                    elif insn_1_mnemonic in modifies_NCVZ:
                        comp_reg1 = crs(operand_bytes(insn_1, 0))
                        comp_reg2 = b'0'
                        comp = insn_0_mnemonic
                        break
                    
                nzcv_set = None
                # try for floating point
                if comp is None:
                    print('try floating point')
                    for j in range(i, len(insns)):
                        insn_1 = insns[j]
                        print(insn_1)
                        insn_1_mnemonic = mnemonic(insn_1)
                    
                        if (
                            insn_1_mnemonic == b'vmrs' and
                            operand_bytes(insn_1, 0) == b'APSR_nzcv,' and
                            operand_bytes(insn_1, 1) == b'fpscr'
                        ):
                            nzcv_set = True

                        if insn_1_mnemonic in fp_compare and nzcv_set:
                            comp_reg1 = _operand_without_trailing_comma(insn_1, 0)
                            comp_reg2 = _condition_operand(insn_1, 1)
                            comp = insn_0_mnemonic
                    
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

    return RenderedCondition(setup=cond_out, expression=cond_expr)


def generate_func_cf_from_graph(meta_block_graph: MetaBlockGraph) -> bytes:
    start = meta_block_graph.entry_address

    seen_loops: set[int] = set()

    def print_base_node(node: MetaBlock) -> RenderedNodeStep:
        out = b''
        if isinstance(node, IfBlock):
            # print("if node")
            cond = node.condition_blocks
            conj = node.conjunctions
            flags = node.flags

            rendered_condition = render_condition(cond, conj, flags, meta_block_graph)

            true_loc = node.false_address
            false_loc = node.true_address
            if true_loc is None or true_loc == node.next_address or true_loc in seen_loops:
                true_out = b'if ( ' + rendered_condition.expression + b' ) \n{\n\n}\n'
            else:
                true_out = b'if ( ' + rendered_condition.expression + b' ) \n{\n' + print_node_loc(true_loc) + b'\n}\n'

            if false_loc is None or false_loc == node.next_address or false_loc in seen_loops or false_loc is None:
                false_out = b''
            else:
                false_out = b'else\n{\n' + print_node_loc(false_loc) + b'\n}\n'


            out += (rendered_condition.setup + true_out + false_out)
            node_loc = node.next_address

        elif isinstance(node, WhileBlock):
            raise Exception # don't think we should come here, but otherwise pass

        elif isinstance(node, LinearBlock):
            block_out = b'\n'.join( [print_block(block) for block in meta_block_graph.source_blocks_at(node.block_addresses)] )

            out += block_out
            node_loc = node.next_address
            # print('next node_loc', node_loc)

        elif isinstance(node, EndBlock):
            end_out = b'\n'.join( [print_block(block) for block in meta_block_graph.source_blocks_at(node.block_addresses)] )
            end_out += b'\nreturn;\n'
            out += end_out
            node_loc = None
        elif isinstance(node, SwitchBlock):
            c_out = b''
            for (i,c) in enumerate(node.cases):
                c_out += b'\ncase ' + bytes(str(i), 'utf-8') + b':\n' + print_node_loc(c)

            block_out = b'\n'.join([print_block(block) for block in meta_block_graph.source_blocks_at(node.preface)])

            switch_insn = meta_block_graph.source_block_at(node.preface[-1]).last_instruction()
            switch_var = crs(operand_bytes(switch_insn, 1))


            out += block_out + b'\nswitch(' + switch_var + b') \n{\n' + c_out + b'\n}\n'
            node_loc = node.next_address
        else:
            print("node", node)
            raise Exception
        return RenderedNodeStep(next_address=node_loc, body=out)

    def print_node(node: MetaBlock | None) -> bytes:
        out = b''
        while node is not None:
            # manually unwrap and progress while, because it uses `inner` which is a meta_block, not loc
            if isinstance(node, WhileBlock):
                # print("while node")
                node_loc = node.address
                seen_loops.add(node_loc)
                inner = node.inner
                cond = node.condition_address
                while_out = print_node(inner)
                rendered_condition = render_condition([cond], [], [True], meta_block_graph)
                while_out = b'while (1) \n{\n' + while_out + rendered_condition.setup +\
                        b'if ( ' + rendered_condition.expression + b' ) {\n break;\n }\n' +\
                        b'\n}\n'
                out += while_out
                
                node_loc = node.next_address
            else:
                # print("base node")
                rendered_step = print_base_node(node)

                node_loc = rendered_step.next_address
                out += rendered_step.body

            # if node_loc is not None:
                # # print("node next", hex(node_loc))
            # else:
                # print("node end")
            
            node = meta_block_graph.block_at(node_loc) if node_loc is not None else None
        return out

    def print_node_loc(node_loc: int) -> bytes:
        # print("node_loc", hex(node_loc))
        node = meta_block_graph.block_at(node_loc)
        return print_node(node)

    return print_node_loc(start)


def generate_func_decl(block_graph: LegacyBlockGraph) -> bytes:
    start = block_graph.entry_address


    signature = get_function_signature(block_graph)
    return render_function_declaration(signature, start).render()


def _operand_without_trailing_comma(instruction: LegacyInstruction, index: int) -> bytes:
    return operand_bytes(instruction, index).rstrip(b',')


def _condition_operand(instruction: LegacyInstruction, index: int) -> bytes:
    return operand_bytes(instruction, index).lstrip(b'#').rstrip(b',')
