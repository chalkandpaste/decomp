from function_signatures import collect_functions, skip_functions
from block_graph import generate_block_graph, generate_asm
from disassemble import generate_func_cf_asm
from convert_c import convert
from reduce_c import reduce_c
from liveness import liveness

import argparse

if __name__ == "__main__":

    parser = argparse.ArgumentParser('decompile from entry point location')

    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('entry_point_loc', metavar='e', type=str, help="entry point location")
    
    args = parser.parse_args()
    
    cf_dir = 'cf/'
    asm_dir = 'asm/'
    c_dir = 'c/'
    
    binary = open(args.input_file, 'rb').read()

    main_func = int(args.entry_point_loc, 0)
    
    search_locs = [main_func]
    funcs = [main_func]

    while len(search_locs) > 0:
        loc = search_locs.pop(0)
        block_graph = generate_block_graph(binary, loc)
        fs = collect_functions(block_graph)
        for f in fs:
            if f not in search_locs and f not in skip_functions and f not in funcs:
                search_locs.append(f)
            if f not in funcs:
                funcs.append(f)

    for f in funcs:
        print('doing', hex(f))
        asm_output = generate_asm(binary, f)
        asm_out_file = open(asm_dir + hex(f) + '.s', 'wb')
        asm_out_file.write(asm_output)
        
        try:
            cf_output = generate_func_cf_asm( binary, f )
            cf_out_file = open(cf_dir + hex(f) + '_cf.c', 'wb')
            cf_out_file.write(cf_output)
        except:
            print('fucked up in cf', hex(f))
            continue 
        
        c_output = convert(cf_output)
        print('c_output')
        print(c_output)
        c_out_file = open(c_dir + hex(f) + '_d.c', 'wb')
        c_out_file.write(c_output)
        
        rc_output = reduce_c(c_output)
        rc_out_file = open(c_dir + hex(f) + '_r.c', 'wb')
        rc_out_file.write(rc_output)
        
        fin_c_output = liveness(rc_output)
        fin_out_file = open(c_dir + hex(f) + '.c', 'wb')
        fin_out_file.write(fin_c_output)

        
