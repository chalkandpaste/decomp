from block_graph import generate_asm
from function_signatures import generate_set_of_funcs

import argparse

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    # parser.add_argument('func_loc', metavar='f', type=int, help="location to decompile")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    binary = f.read()

    f.close()

    functions = generate_set_of_funcs( binary, 0x08020000 + 0xa4f4 )

    for f in functions:
        asm = generate_asm(binary, f)
        g = open('asm/'+hex(f)+'.s', 'wb')
        g.write(asm)
