import argparse

from .function_signatures import generate_func_sigs, add_function_sigs
from .block_graph import generate_block_graph
from .render_c import generate_func_cf_from_graph, generate_func_decl
from .structure import annotate_graph, simplify_if


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
