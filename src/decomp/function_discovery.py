from __future__ import annotations

from dataclasses import dataclass

from .block_graph import generate_block_graph
from .function_signatures import collect_functions, get_function_signature, skip_functions
from .legacy_types import LegacyBlockGraph


@dataclass(frozen=True)
class FunctionDiscovery:
    entry_address: int
    call_graph: dict[int, tuple[int, ...]]
    block_graphs: dict[int, LegacyBlockGraph]

    def called_functions(self) -> tuple[int, ...]:
        funcs = []
        for calls in self.call_graph.values():
            for address in calls:
                if address not in funcs and address not in skip_functions:
                    funcs.append(address)
        return tuple(funcs)


def discover_functions(binary: bytes, entry_point_loc: int) -> FunctionDiscovery:
    search_locs = [entry_point_loc]
    func_call_graph: dict[int, tuple[int, ...]] = {}
    func_block_graph: dict[int, LegacyBlockGraph] = {}

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block_graph = generate_block_graph(binary, loc)
        func_block_graph[loc] = block_graph
        functions = tuple(collect_functions(block_graph))
        func_call_graph[loc] = functions
        for f in functions:
            if f not in func_call_graph and f not in search_locs and f not in skip_functions:
                search_locs.append(f)

    return FunctionDiscovery(
        entry_address=entry_point_loc,
        call_graph=func_call_graph,
        block_graphs=func_block_graph,
    )


def generate_set_of_funcs(binary: bytes, entry_point_loc: int) -> list[int]:
    discovery = discover_functions(binary, entry_point_loc)
    return list(set(discovery.called_functions()))


def generate_func_sigs(binary: bytes, entry_point_loc: int) -> dict[int, bytes]:
    discovery = discover_functions(binary, entry_point_loc)
    func_signatures = {}

    for f in discovery.called_functions():
        block_graph = discovery.block_graphs[f]
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
