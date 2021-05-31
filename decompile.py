from convert_c import convert
from simplify_c import simplify
from liveness import liveness

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")

    args = parser.parse_args()

    assembly = open(args.input_file, 'rb')

    converted = convert(assembly)
    simplified = simplify(converted)
    reduced = liveness

