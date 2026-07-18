from collections.abc import Mapping
from dataclasses import dataclass
from types import MappingProxyType

from .analysis import collect_function_addresses
from .arch.arm_thumb.register_effects import RegisterEffect, register_effect
from .core.cfg import ControlFlowGraph
from .core.instruction import Instruction
from .legacy_adapter import legacy_block_graph_to_cfg
from .legacy_instruction import mnemonic, operand_int, with_appended_token
from .legacy_types import LegacyBlockGraph, LegacyRegisterScope

from .loop_tracker import LoopTracker
from .instructions import func_call, uncond_block_end
    
skip_functions = [ 134469972, 134471256, 134469472, 134471424, 134472782, 134455624, 134470750, 134472518,
            0x8020298, 0x80205d6, 0x802fe84, 0x8020ccc, 0x8020334, 0x8020f24, 0x8020c40, 0x8021470, 0x8021340,
            0x8021008, 0x803e2a4, 0x803e3ea, 0x803d870, 0x8020c38, 0x8020694, 0x8020c30, 0x803c29c,
            0x802f708, 0x802054c, 0x803dd04, 0x803df6c, 0x803e2f0, 0x803d778, 0x803e11c, 0x803a178,
            0x8020748, 0x803c6ea, 0x8022610 
            ] 
            # 0x8020f24, 0x8020d4c, 0x8020c38, 0x803df84, 0x8020334, 0x8020c30, 0x8020ccc, 0x8020748, 0x802fe84,
            # 0x803c29c, 0x803adc8, 0x803d7dc, 0x803af48, 0x803af28, 0x8020688, 0x803c222, 0x803d440, 0x803aec0,
            # 0x8020244, 0x803af68, 0x8030144, 0x802ff6c, 0x802fd58, 0x803c23c,  ]

FORWARD_REGISTERS = (b'r0', b'r1', b's0', b'd0')
BACKWARD_REGISTERS = (
    b'r0',
    b'r1',
    b'r2',
    b'r3',
    b's0',
    b's1',
    b's2',
    b's3',
    b'd0',
    b'd1',
    b'd2',
    b'd3',
)


@dataclass(frozen=True)
class RegisterSignature:
    return_scope: Mapping[bytes, bool]
    argument_scope: Mapping[bytes, bool]

    def __post_init__(self) -> None:
        object.__setattr__(self, "return_scope", MappingProxyType(dict(self.return_scope)))
        object.__setattr__(self, "argument_scope", MappingProxyType(dict(self.argument_scope)))


@dataclass(frozen=True)
class FunctionDeclaration:
    return_type: bytes
    prototype: bytes

    def render(self) -> bytes:
        return self.return_type + self.prototype

    def render_comment(self) -> bytes:
        return b'; ' + self.render()


def add_function_sigs(block_graph: LegacyBlockGraph, function_sigs: dict[int, bytes]) -> LegacyBlockGraph:
    for loc in block_graph.reachable_order(direction=False):
        block = block_graph.block_at(loc)
        insns = block.instructions

        new_insns = []

        for i in range(len(insns)):
            insn = insns[i]
            insn_mnemonic = mnemonic(insn)
            if insn_mnemonic in func_call or insn_mnemonic in uncond_block_end:
                func_loc = operand_int(insn, 0)
                if func_loc in function_sigs:
                    fs = function_sigs[func_loc]
                    insn = with_appended_token(insn, fs)

            new_insns.append(insn)
        block_graph = block_graph.with_block(block.with_instructions(tuple(new_insns)))

    return block_graph

def collect_functions(block_graph: LegacyBlockGraph) -> list[int]:
    cfg = legacy_block_graph_to_cfg(block_graph)
    return collect_function_addresses(cfg)

def get_function_signature(block_graph: LegacyBlockGraph) -> RegisterSignature:
    entry_address = block_graph.entry_address
    print('get_function_signature', hex(entry_address))

    cfg = legacy_block_graph_to_cfg(block_graph)
    loop_tracker = LoopTracker(cfg)
    return _get_function_signature_from_cfg(cfg, loop_tracker)


def render_function_declaration(signature: RegisterSignature, address: int) -> FunctionDeclaration:
    function_name = b'func_' + bytes(hex(address), 'utf-8')

    if signature.argument_scope[b'r3']:
        prototype = function_name + b' ( int r0, int r1, int r2, int r3 )'
    elif signature.argument_scope[b'r2']:
        prototype = function_name + b' ( int r0, int r1, int r2 )'
    elif signature.argument_scope[b'r1']:
        prototype = function_name + b' ( int r0, int r1 )'
    elif signature.argument_scope[b'r0']:
        prototype = function_name + b' ( int r0 )'
    elif signature.argument_scope[b's3']:
        prototype = function_name + b' ( float s0, float s1, float s2, float s3 )'
    elif signature.argument_scope[b's2']:
        prototype = function_name + b' ( float s0, float s1, float s2 )'
    elif signature.argument_scope[b's1']:
        prototype = function_name + b'  ( float s0, float s1 )'
    elif signature.argument_scope[b's0']:
        prototype = function_name + b' ( float s0 )'
    elif signature.argument_scope[b'd1']:
        prototype = function_name + b' ( double d0, double d1 )'
    elif signature.argument_scope[b'd0']:
        prototype = function_name + b' ( double d0 )'
    else:
        prototype = function_name + b' ()'

    if signature.return_scope[b'r1']:
        return_type = b'long '
    elif signature.return_scope[b'r0']:
        return_type = b'int '
    elif signature.return_scope[b's0']:
        return_type = b'float '
    elif signature.return_scope[b'd0']:
        return_type = b'double '
    else:
        return_type = b'void '

    return FunctionDeclaration(return_type=return_type, prototype=prototype)


def _get_function_signature_from_cfg(
    cfg: ControlFlowGraph,
    loop_tracker: LoopTracker,
) -> RegisterSignature:
    entry_address = cfg.entry
    loops = {}

    search_locs = [entry_address]

    init_forward_scope = _initial_forward_scope()
    
    # mapping from loc to scope, to be updated
    loc_scope = {search_locs[0] : init_forward_scope.copy()}
    
    ends = []

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block = cfg.block_at(loc)

        if loc not in loops:
            if loop_tracker.can_loop(loc):
                loops[loc] = True
            else:
                loops[loc] = False

        scope = loc_scope[loc]

        insns = block.instructions
        for i in insns:
            effect = _register_effect_for_instruction(i)
            if effect is not None:
                _apply_forward_register_effect(scope, effect)

        loc_scope[loc] = scope

        c_locs = cfg.successors(loc)
        
        if len(c_locs) == 0:
            if loc not in ends:
                ends.append(loc)
        else:
            for c in c_locs:
                # merge_scope(c, loc_scope)
                if c not in loc_scope:
                    loc_scope[c] = scope.copy()
                else:
                    loc_scope[c] = _merge_register_scopes(loc_scope[c], scope, FORWARD_REGISTERS)
                        
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

    init_backward_scope = _initial_backward_scope()
    
    # mapping from loc to scope, to be updated
    loc_scope = {loc: init_backward_scope.copy() for loc in search_locs}
    
    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block = cfg.block_at(loc)

        if loc not in loops:
            if loop_tracker.can_loop(loc):
                loops[loc] = True
            else:
                loops[loc] = False

        scope = loc_scope[loc]

        insns = list(block.instructions)
        insns.reverse()

        for i in insns:
            effect = _register_effect_for_instruction(i)
            if effect is not None:
                _apply_backward_register_effect(scope, effect)

        loc_scope[loc] = scope

        p_locs = cfg.predecessors(loc)
        
        for p in p_locs:
            if p not in loc_scope:
                loc_scope[p] = scope.copy()
            else:
                loc_scope[p] = _merge_register_scopes(loc_scope[p], scope, BACKWARD_REGISTERS)
                    
            if p not in loops:
                search_locs.append(p)
        

    arg_scope = loc_scope[entry_address]

    if return_scope is None:
        return_scope = _initial_forward_scope()

    return RegisterSignature(return_scope=return_scope, argument_scope=arg_scope)


def _register_effect_for_instruction(instruction: Instruction) -> RegisterEffect | None:
    return register_effect(instruction)


def _initial_forward_scope() -> LegacyRegisterScope:
    return {register: False for register in FORWARD_REGISTERS}


def _initial_backward_scope() -> LegacyRegisterScope:
    return {register: False for register in BACKWARD_REGISTERS}


def _merge_register_scopes(
    previous_scope: LegacyRegisterScope,
    current_scope: LegacyRegisterScope,
    registers: tuple[bytes, ...],
) -> LegacyRegisterScope:
    merged = current_scope.copy()
    for register in registers:
        if previous_scope[register] or current_scope[register]:
            merged[register] = True
    return merged


def _apply_forward_register_effect(scope: LegacyRegisterScope, effect: RegisterEffect) -> None:
    for register in effect.reads:
        _set_scope_register(scope, register, False)
    for register in effect.writes:
        _set_scope_register(scope, register, True)


def _apply_backward_register_effect(scope: LegacyRegisterScope, effect: RegisterEffect) -> None:
    for register in effect.writes:
        _set_scope_register(scope, register, False)
    for register in effect.reads:
        _set_scope_register(scope, register, True)


def _set_scope_register(scope: LegacyRegisterScope, register: bytes, value: bool) -> None:
    if register in scope:
        scope[register] = value
