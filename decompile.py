from convert_c import convert
from reduce_c import reduce_c
from liveness import liveness

if __name__ == "__main__":

    base_dir = 'scratch/'

    out_dir = 'out/'

    names = ['9498', '14d14', '1479c', 'd630']
    # names = ['14d14', '1479c', 'd630']

    for name in names:

        f = open(base_dir + name + '.c', 'rb')
        
        cf_assembly = f.read()
        try:
            converted = convert(cf_assembly)
            o = open(out_dir + name + '.c.c', 'wb')
            o.write(converted)
        except:
            continue


        try:
            if name == '9498':
                reduced = reduce_c(converted, True, True)
            else:
                reduced = reduce_c(converted)

            o = open(out_dir + name + '.s.c', 'wb')
            o.write(reduced)
        except:
            continue
       
        try:
            livened = liveness(reduced)
            o = open(out_dir + name + '.l.c', 'wb')
            o.write(livened)
        except:
            continue
    
    funcs = []

    for f in funcs:
        pass
