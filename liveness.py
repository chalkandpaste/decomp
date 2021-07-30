from pycparser import parse_file, c_generator, c_ast, c_parser
import argparse

parser = c_parser.CParser()

init_liveness = {
    'r0' : False,
    'r1' : False,
    'r2' : False,
    'r3' : False,
    'r4' : False,
    'r5' : False,
    'r6' : False,
    'r7' : False,
    'r8' : False,
    'sl' : False,
    'sb' : False,
    'ip' : False,
    'fp' : False,
    's0' : False,
    's1' : False,
    's2' : False,
    's3' : False,
    's4' : False,
    's5' : False,
    's6' : False,
    's7' : False,
    's8' : False,
    's9' : False,
    's10' : False,
    's11' : False,
    's12' : False,
    's13' : False,
    's14' : False,
    's15' : False,
    's16' : False,
    's17' : False,
    's18' : False,
    's19' : False,
    's20' : False,
    's21' : False,
    's22' : False,
    's23' : False,
    's24' : False,
    's25' : False,
    's26' : False,
    's27' : False,
    's28' : False,
    'd1' : False,
    'd2' : False,
    'd3' : False,
    'd4' : False,
    'd5' : False,
    'd6' : False,
    'd7' : False,
    'd8' : False,
    'd9' : False,
    'd10' : False,
    'd11' : False,
    'd12' : False,
    'd13' : False,
    'd14' : False
    }



def expr_depth(ex, limit = 3):
    
    def e_dep(e, d, l):
        if d < l:
            if isinstance(e, c_ast.BinaryOp):
                return e_dep(e.left, d + 1, l) + e_dep(e.right, d + 1, l)
            elif isinstance(e, c_ast.UnaryOp) and e.op == "*":
                return e_dep(e.expr, d, l)
            elif isinstance(e, c_ast.UnaryOp) and e.op != "*":
                return e_dep(e.expr, d + 1, l)
            elif isinstance(e, c_ast.ID):
                return d
            elif isinstance(e, c_ast.Constant):
                return d
            elif isinstance(e, c_ast.FuncCall):
                return l/2 + 1
            elif isinstance(e, c_ast.Cast):
                return e_dep(e.expr, d + 1, l)
            else:
                print(e)
                raise Exception

        return d

    return e_dep(ex, 0, limit) >= limit

def liveness_expr(e, liveness):

    if isinstance(e, c_ast.BinaryOp):
        liveness = liveness_expr(e.left, liveness)
        liveness = liveness_expr(e.right, liveness)
    elif isinstance(e, c_ast.UnaryOp):
        liveness = liveness_expr(e.expr, liveness)
    elif isinstance(e, c_ast.ID):
        if e.name in liveness:
            liveness[e.name] = True
    elif isinstance(e, c_ast.Constant):
        pass
    elif isinstance(e, c_ast.FuncCall):
        liveness = liveness_func(e, liveness)
    elif isinstance(e, c_ast.Cast):
        liveness = liveness_expr(e.expr, liveness)
    elif isinstance(e, c_ast.Return):
        liveness = liveness_expr(e.expr, liveness)
    elif e is None:
        pass
    else:
        print(e.show())
        raise Exception

    return liveness

def liveness_if (i, liveness):

    if i.iffalse and i.iffalse.block_items:
        i.iffalse.block_items, false_liveness = liveness_body(i.iffalse.block_items, liveness.copy())
    else:
        false_liveness = liveness


    if i.iftrue and i.iftrue.block_items:
        i.iftrue.block_items, true_liveness = liveness_body(i.iftrue.block_items, liveness.copy())
    else:
        true_liveness = liveness
   
    for k in false_liveness:
        if false_liveness[k] or true_liveness[k]:
            liveness[k] = True

    liveness = liveness_expr(i.cond, liveness)
    
    return i, liveness

def liveness_while (w, liveness):

    w.stmt.block_items, liveness = liveness_body(w.stmt.block_items, liveness.copy())

    return w, liveness

def liveness_switch (s, liveness):

    s.stmt.block_items, liveness = liveness_body(s.stmt.block_items, liveness.copy())

    liveness = liveness_expr(s.cond, liveness)

    return s, liveness

def liveness_func (f, liveness):
    if f.args:
        for e in f.args.exprs:
            liveness = liveness_expr(e, liveness.copy())

    return liveness

def liveness_body (body, liveness):
   
    if body is None:
        return body, liveness

    new_block_items = []

    body.reverse()

    for b in body:
        if isinstance(b, c_ast.Assignment):
            if isinstance(b.lvalue, c_ast.ID):
                if b.lvalue.name in liveness:
                    if liveness[b.lvalue.name]:
                        liveness[b.lvalue.name] = False # assignment reached, kill it
                        liveness = liveness_expr(b.rvalue, liveness) # resurrect any assignments
                        new_block_items.append(b)
                    else:
                        # already false, although we shoudln't be here.
                        liveness = liveness_expr(b.rvalue, liveness) # resurrect any assignments

                else: 
                    new_block_items.append(b)

            elif isinstance(b.lvalue, c_ast.BinaryOp) and b.lvalue.op == '*':
                liveness = liveness_expr(b.lvalue, liveness)
                liveness = liveness_expr(b.rvalue, liveness)
                new_block_items.append(b)
            
            elif isinstance(b.lvalue, c_ast.UnaryOp) and b.lvalue.op == '*':
                liveness = liveness_expr(b.lvalue.expr, liveness)
                liveness = liveness_expr(b.rvalue,liveness)
                new_block_items.append(b)
            else:
                print(body.show())
                raise Exception

        
        elif isinstance(b, c_ast.If):
            i, liveness = liveness_if(b, liveness.copy())
            new_block_items.append(i)

        elif isinstance(b, c_ast.While):
            w, liveness = liveness_while(b, liveness.copy())
            new_block_items.append(w)

        elif isinstance(b, c_ast.Switch):
            s, liveness = liveness_switch(b, liveness.copy())
            new_block_items.append(s)

        elif isinstance(b, c_ast.Case):
            b.stmts, liveness = liveness_body(b.stmts, liveness.copy())
            new_block_items.append(b)

        elif isinstance(b, c_ast.Default):
            b.stmts, liveness = liveness_body(b.stmts, liveness.copy())
            new_block_items.append(b)
        
        elif isinstance(b, c_ast.FuncCall):
            liveness = liveness_func(b, liveness)
            new_block_items.append(b)

        elif isinstance(b, c_ast.Break):
            new_block_items.append(b)
        
        elif isinstance(b, c_ast.Return):
            liveness_expr(b, liveness)
            new_block_items.append(b)

        elif isinstance(b, c_ast.EmptyStatement):
            new_block_items.append(b)

        else:
            print(b)
            raise Exception

    # body.block_items =  
    new_block_items.reverse()

    return new_block_items, liveness 

def liveness(raw):
    
    f = open('scratch/temp.c', 'wb')
    f.write(raw)
    f.close()
    
    ast = parse_file('scratch/temp.c', use_cpp=True)
   
    body = ast.ext[0].body

    ast.ext[0].body.block_items, liveness = liveness_body(body.block_items, init_liveness)

    gen = c_generator.CGenerator()

    return bytes(gen.visit(ast), 'utf-8')

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    raw = f.read()

    output = liveness(raw)

    out = open(args.output_file, 'wb')

    out.write(output)

    
