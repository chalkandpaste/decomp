import argparse
from pathlib import Path
from collections.abc import Sequence

def main(argv: Sequence[str] | None = None) -> None:

    parser = argparse.ArgumentParser(
        prog='decomp',
        description='decompile firmware from an entry point',
    )

    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('entry_point_loc', metavar='e', type=str, help="entry point location")
    parser.add_argument(
        '--output-dir',
        default='.',
        help='directory where asm/, cf/, and c/ outputs will be written',
    )
    parser.add_argument(
        '--max-functions',
        type=int,
        default=None,
        help='limit recursive discovery/output to the first N functions',
    )
    
    args = parser.parse_args(argv)

    from .block_graph import generate_block_graph, generate_asm
    from .convert_c import convert
    from .disassemble import generate_func_cf_asm
    from .function_signatures import collect_functions, skip_functions
    from .liveness import liveness
    from .reduce_c import reduce_c
    
    output_dir = Path(args.output_dir)
    cf_dir = output_dir / 'cf'
    asm_dir = output_dir / 'asm'
    c_dir = output_dir / 'c'
    for out_dir in (cf_dir, asm_dir, c_dir):
        out_dir.mkdir(parents=True, exist_ok=True)
    
    binary = Path(args.input_file).read_bytes()

    main_func = int(args.entry_point_loc, 0)
    
    search_locs = [main_func]
    funcs = [main_func]

    cf_misses = []
    stage_misses = []

    while len(search_locs) > 0 and (args.max_functions is None or len(funcs) < args.max_functions):
        loc = search_locs.pop(0)
        block_graph = generate_block_graph(binary, loc)
        fs = collect_functions(block_graph)
        for f in fs:
            if args.max_functions is not None and len(funcs) >= args.max_functions:
                break
            if f not in search_locs and f not in skip_functions and f not in funcs:
                search_locs.append(f)
            if f not in funcs:
                funcs.append(f)

    for f in funcs[:args.max_functions]:
        print('doing', hex(f))
        asm_output = generate_asm(binary, f)
        (asm_dir / (hex(f) + '.s')).write_bytes(asm_output)
        
        try:
            cf_output = generate_func_cf_asm( binary, f )
            (cf_dir / (hex(f) + '_cf.c')).write_bytes(cf_output)
        except Exception as exc:
            print('failed control-flow recovery for', hex(f), repr(exc))
            cf_misses.append(f)
            continue 
        
        try:
            c_output = convert(cf_output)
            (c_dir / (hex(f) + '_d.c')).write_bytes(c_output)
        except Exception as exc:
            print('failed C lowering for', hex(f), repr(exc))
            stage_misses.append((f, 'convert'))
            continue
        
        try:
            rc_output = reduce_c(c_output)
            (c_dir / (hex(f) + '_r.c')).write_bytes(rc_output)
        except Exception as exc:
            print('failed C reduction for', hex(f), repr(exc))
            stage_misses.append((f, 'reduce'))
            continue
        
        try:
            fin_c_output = liveness(rc_output)
            (c_dir / (hex(f) + '.c')).write_bytes(fin_c_output)
        except Exception as exc:
            print('failed liveness cleanup for', hex(f), repr(exc))
            stage_misses.append((f, 'liveness'))
            continue

    for f in cf_misses:
        print("missed:", hex(f))
    for f, stage in stage_misses:
        print("missed", stage + ":", hex(f))

if __name__ == "__main__":
    main()
