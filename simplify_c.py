from pycparser import parse_file, c_generator, c_ast, c_parser
import argparse

import sys


global var_counter

init_scope = {
    'r0' : None,
    'r1' : None,
    'r2' : None,
    'r3' : None,
    'r4' : None,
    'r5' : None,
    'r6' : None,
    'r7' : None,
    'r8' : None,
    'sl' : None,
    'sb' : None,
    'ip' : None,
    'fp' : None,
    's0' : None,
    's1' : None,
    's2' : None,
    's3' : None,
    's4' : None,
    's5' : None,
    's6' : None,
    's7' : None,
    's8' : None,
    's9' : None,
    's10' : None,
    's11' : None,
    's12' : None,
    's13' : None,
    's14' : None,
    's15' : None,
    's16' : None,
    's17' : None,
    's18' : None,
    's19' : None,
    's20' : None,
    's21' : None,
    's22' : None,
    's23' : None,
    's24' : None,
    's25' : None,
    's26' : None,
    's27' : None,
    's28' : None,
    'd1' : None,
    'd2' : None,
    'd3' : None,
    'd4' : None,
    'd5' : None,
    'd6' : None,
    'd7' : None,
    'd8' : None,
    'd9' : None,
    'd10' : None,
    'd11' : None,
    'd12' : None,
    'd13' : None,
    'd14' : None
    }

# init_scope = {
    # 'r0' : c_ast.ID('r0'),
    # 'r1' : c_ast.ID('r1'),
    # 'r2' : c_ast.ID('r2'),
    # 'r3' : c_ast.ID('r3'),
    # 'r4' : c_ast.ID('r4'),
    # 'r5' : c_ast.ID('r5'),
    # 'r6' : c_ast.ID('r6'),
    # 'r7' : c_ast.ID('r7'),
    # 'r8' : c_ast.ID('r8'),
    # 'sl' : c_ast.ID('sl'),
    # 'sb' : c_ast.ID('sb'),
    # 'ip' : c_ast.ID('ip'),
    # 'fp' : c_ast.ID('fp'),
    # 's0' : c_ast.ID('s0'),
    # 's1' : c_ast.ID('s1'),
    # 's2' : c_ast.ID('s2'),
    # 's3' : c_ast.ID('s3'),
    # 's4' : c_ast.ID('s4'),
    # 's5' : c_ast.ID('s5'),
    # 's6' : c_ast.ID('s6'),
    # 's7' : c_ast.ID('s7'),
    # 's8' : c_ast.ID('s8'),
    # 's9' : c_ast.ID('s9'),
    # 's10' : c_ast.ID('s10'),
    # 's11' : c_ast.ID('s11'),
    # 's12' : c_ast.ID('s12'),
    # 's13' : c_ast.ID('s13'),
    # 's14' : c_ast.ID('s14'),
    # 's15' : c_ast.ID('s15'),
    # 's16' : c_ast.ID('s16'),
    # 's17' : c_ast.ID('s17'),
    # 's18' : c_ast.ID('s18'),
    # 's19' : c_ast.ID('s19'),
    # 's20' : c_ast.ID('s20'),
    # 's21' : c_ast.ID('s21'),
    # 's22' : c_ast.ID('s22'),
    # 'd1' : c_ast.ID('d1'),
    # 'd2' : c_ast.ID('d2'),
    # 'd3' : c_ast.ID('d3'),
    # 'd4' : c_ast.ID('d4'),
    # 'd5' : c_ast.ID('d5'),
    # 'd6' : c_ast.ID('d6'),
    # 'd7' : c_ast.ID('d7'),
    # 'd8' : c_ast.ID('d8'),
    # 'd9' : c_ast.ID('d9'),
    # 'd10' : c_ast.ID('d10'),
    # 'd11' : c_ast.ID('d10')
    # }

def add_to_scope(scope, assign):
    global var_counter
    name = assign.lvalue.name
    val = assign.rvalue
    if name in scope:
        scope[name] = val
        if val == None:
            print(assign)
            print(scope)
            raise Exception
        if expr_depth(val, 6):
            substitution = c_ast.Assignment(op = "=", lvalue = c_ast.ID('var' + str(var_counter)), rvalue = scope[name]);
            scope[name] = c_ast.ID('var' + str(var_counter))
            var_counter += 1
            return substitution, name, scope
        return None, None, scope
    else:
        return None, None, scope

def update_scope(scope, new_scopes):
    for ns in new_scopes:
        for k in scope:
            if scope[k] is not ns[k]:
                scope[k] = None
    
    return scope

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

def simplify_expr(e, scope):

    if isinstance(e, c_ast.BinaryOp):
        e.left = simplify_expr(e.left, scope)
        e.right = simplify_expr(e.right, scope)
    elif isinstance(e, c_ast.UnaryOp):
        e.expr = simplify_expr(e.expr, scope)
    elif isinstance(e, c_ast.ID):
        if e.name in scope and scope[e.name] is not None:
            e = scope[e.name]
    elif isinstance(e, c_ast.Constant):
        pass
    elif isinstance(e, c_ast.FuncCall):
        global func_killer
        if func_killer:
            pass
        else:
            e = simplify_func(e, scope)
    elif isinstance(e, c_ast.Cast):
        e.expr = simplify_expr(e.expr, scope)
    elif isinstance(e, c_ast.Return):
        pass
    else:
        print(e)
        raise Exception
    return e

# def simplify_expr_non_recursive(e, scope):

    # arg_stack = []
    # op_stack = []

    # while not stack.empty():
        # curr = 
        # if isinstance(e, c_ast.BinaryOp):
            # op_stack.push(e)
            # arg_stack.push(e.left)
            # arg_stack.push(e.right)
        # elif isinstance(e, c_ast.UnaryOp):
            # op_stack.push(e)
            # arg_stack.push(e.expr)
        # elif isinstance(e, c_ast.ID):
            # if e.name in scope and scope[e.name] is not None:
                # e = scope[e.name]
        # elif isinstance(e, c_ast.Constant):
            # pass
        # elif isinstance(e, c_ast.FuncCall):
            # e = simplify_func(e, scope)
        # elif isinstance(e, c_ast.Cast):
            # e.expr = simplify_expr(e.expr, scope)
        # elif isinstance(e, c_ast.Return):
            # pass
        # else:
            # print(e)
            # raise Exception
    
    # return e


def simplify_if (i, scope):
    i.cond = simplify_expr(i.cond, scope)

    if i.iftrue:
        if isinstance(i.iftrue, c_ast.ExprList):
            i.iftrue, true_scope = simplify_body(i.iftrue.exprs, scope.copy())
            new_block_items.append(el)
        elif i.iftrue.block_items:
            i.iftrue.block_items, true_scope = simplify_body(i.iftrue.block_items, scope)
        else:
            true_scope = scope

    else:
        true_scope = scope

    if i.iffalse:
        if isinstance(i.iffalse, c_ast.ExprList):
            i.iffalse, false_scope = simplify_body(i.iffalse.exprs, scope.copy())
            new_block_items.append(el)
        elif i.iffalse.block_items:
            i.iffalse.block_items, false_scope = simplify_body(i.iffalse.block_items, scope)
        else:
            false_scope = scope
    else:
        false_scope = scope

    scope = update_scope(scope, [true_scope, false_scope])
    return i, scope

def merge_while_scope(scope, w_scope):
    for k in w_scope:
        if w_scope[k] is not None:
            w_scope[k] = True # get rid of it
        else: # if w_scope[k] is None:
            w_scope[k] = False # it wasn't used, retain it

    for k in w_scope:
        if w_scope[k]:
            scope[k] = None
   
    return scope

def simplify_while (w, scope):

    # simplify first within the while using unassigned scope
    w.stmt.block_items, w_scope = simplify_body(w.stmt.block_items, init_scope.copy())
    
    # take out any variables that were used from the current scope
    scope = merge_while_scope(scope.copy(), w_scope) 

    # simplify further with any scope
    w.stmt.block_items, _= simplify_body(w.stmt.block_items, scope.copy())
    
    return w, scope

def simplify_switch (s, scope):

    s.cond = simplify_expr(s.cond, scope)

    case_scopes = []
    new_block_items = []
    for bi in s.stmt.block_items:
        if isinstance(bi, c_ast.Case) or isinstance(bi, c_ast.Default):
            bi.stmts, c_scope = simplify_body(bi.stmts, scope.copy())
            case_scopes.append(c_scope)
            new_block_items.append(bi)
        else:
            print(bi)
            raise Exception
        new_block_items.append(bi)

    s.stmt.block_items = new_block_items

    scope  = update_scope(scope, case_scopes)

    return s, scope

def simplify_func (f, scope):
    # global debug_counter

    # func_count = 39

    # if debug_counter >= func_count:
        # print(scope)
        # raise Exception
    # else:
        # debug_counter += 1

    if f.args is not None:
        new_args_exprs = []
        for e in f.args.exprs:
            if isinstance(e, c_ast.ID):
                if e.name in scope:
                    e = scope[e.name]
            
            new_args_exprs.append(e)
        
        f.args.exprs = new_args_exprs

    return f

def simplify_body (body, scope):
    
    new_block_items = []
    kill_list = []
    clean_new_block_items = []

    for b in body:
        if isinstance(b, c_ast.Assignment):
            if isinstance(b.lvalue, c_ast.ID):
                b.rvalue = simplify_expr(b.rvalue, scope)
                substitution,name,scope = add_to_scope(scope, b)
                if substitution:
                    new_block_items.append(substitution)
                    kill_list.append(name)
                else:
                    new_block_items.append(b)
            elif isinstance(b.lvalue, c_ast.BinaryOp) and b.lvalue.op == '*':
                b.lvalue = simplify_expr(b.lvalue,scope)
                b.rvalue = simplify_expr(b.rvalue, scope)
                new_block_items.append(b)
            elif isinstance(b.lvalue, c_ast.UnaryOp) and b.lvalue.op == '*':
                b.lvalue.expr = simplify_expr(b.lvalue.expr, scope)
                b.rvalue = simplify_expr(b.rvalue,scope)
                new_block_items.append(b)
            else:
                print(body.show())
                raise Exception

        
        elif isinstance(b, c_ast.If):
            i, scope = simplify_if(b, scope.copy())
            new_block_items.append(i)

        elif isinstance(b, c_ast.While):
            w, scope = simplify_while(b, scope.copy())
            new_block_items.append(w)
            # new_block_items.append(b)

        elif isinstance(b, c_ast.FuncCall):
            global func_killer
            if func_killer:
                new_block_items.append(b)
            else:
                f = simplify_func(b, scope)
                new_block_items.append(f)

        elif isinstance(b, c_ast.Switch):
            s, scope = simplify_switch(b, scope.copy())
            new_block_items.append(s)

        elif isinstance(b, c_ast.Case) or isinstance(b, c_ast.Default):
            b.stmts, c_scope = simplify_body(b.stmts, scope.copy())
            scope  = update_scope(scope, c_scope)
            new_block_items.append(b)
        
        elif isinstance(b, c_ast.Break):
            new_block_items.append(b)

        elif isinstance(b, c_ast.Return):
            b = simplify_expr(b, scope)
            new_block_items.append(b)

        else:
            print(b)
            raise Exception

    for nb in new_block_items:
        if isinstance(b, c_ast.Assignment) and isinstance(b.lvalue, c_ast.ID) and b.lvalue.name in kill_list:
            pass
        else:
            clean_new_block_items.append(nb)

    # body.block_items =  

    return new_block_items, scope 

if __name__ == "__main__":
   
    # debug recursion
    global func_killer
    global when_killer
    global debug_counter
    debug_counter = 0

    #Mooh pawa bah-bee!
    sys.setrecursionlimit(9001)

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")
    parser.add_argument('-f', type=bool, default=False, help="don't simplify non-return function calls")
    parser.add_argument('-w', type=bool, default=False, help="don't simplify non-return function calls")

    args = parser.parse_args()
  
    func_killer = args.f
    when_killer = args.w

    var_counter = 0

    ast = parse_file(args.input_file, use_cpp=True)
    body = ast.ext[0].body

    ast.ext[0].body.block_items, scope = simplify_body(body.block_items, init_scope.copy())

    gen = c_generator.CGenerator()

    out = open(args.output_file, 'w')

    out.write(gen.visit(ast))

