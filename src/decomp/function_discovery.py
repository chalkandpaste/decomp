from __future__ import annotations

from dataclasses import dataclass

from .block_graph import generate_block_graph
from .function_signatures import (
    RegisterSignature,
    collect_functions,
    get_function_signature,
    render_function_declaration,
    skip_functions,
)
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
    func_signatures: dict[int, RegisterSignature] = {}

    for f in discovery.called_functions():
        block_graph = discovery.block_graphs[f]
        func_signatures[f] = get_function_signature(block_graph)

    func_comments = {}

    for f in func_signatures:
        signature = func_signatures[f]
        func_comments[f] = render_function_declaration(signature, f).render_comment()

    return func_comments
