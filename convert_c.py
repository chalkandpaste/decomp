import pickle
import re
import argparse

import instructions as ns

def map_sections (sections):
    new_sections = []
    for section in sections:
        if section['type']:
            comments = section
            code = []
            for line in comments['section']:
                if line.lstrip().startswith(b'/*'):
                    pass
                elif line.lstrip().startswith(b'*/'):
                    pass
                else:
                    # try:
                    instruction = list(filter(lambda a: a != b'', line.lstrip().split(b' ')))[3:]
                    instruction = [i.lstrip(b'[#').rstrip(b',;]\n') for i in instruction]
                    # except:
                        # instruction = None

                    # if instruction:
                    output = convert_instruction(instruction)
                    if output != b'':
                        code.append(output + b';')
            section['code'] = code
        else:
            section['code'] = None
        
        new_sections.append(section)

    return new_sections

def convert_instruction(insn):
    if insn[0] in ns.moves:
        return mov(insn)
    if insn[0] in ns.n_moves:
        return n_mov(insn)
    if insn[0] in ns.load:
        return load(insn)
    if insn[0] in ns.load_d:
        return load_d(insn)
    if insn[0] in ns.store:
        return store(insn)
    if insn[0] in ns.store_d:
        return store_d(insn)
    elif insn[0] in ns.add:
        return add(insn)
    elif insn[0] in ns.sub:
        return sub(insn)
    elif insn[0] in ns.rsb:
        return rev_sub(insn)
    elif insn[0] in ns.mul:
        return mul(insn)
    elif insn[0] in ns.smull:
        return smull(insn)
    elif insn[0] in ns.vmlas:
        return vmlas(insn)
    elif insn[0] in ns.div:
        return div(insn)
    elif insn[0] in ns.aand:
        return aand(insn)
    elif insn[0] in ns.bic:
        return bic(insn)
    elif insn[0] in ns.orr:
        return orr(insn)
    elif insn[0] in ns.shift_left:
        return shift_left(insn)
    elif insn[0] in ns.shift_right:
        return shift_right(insn)
    elif insn[0] in ns.cast:
        return cast(insn)
    elif insn[0] in ns.sxtab:
        return sxtab(insn)
    elif insn[0] in ns.bits:
        return bits(insn)
    elif insn[0] in ns.func_call:
        return func_call(insn)
    elif insn[0] in ns.uncond_block_end:
        if len(insn) > 2:
            return func_call(insn)
        else:
            return b''
    elif insn[0] in ns.fucking_shit + ns.vpop + ns.cond_block_end + ns.cond_block_end_zero + ns.block_end_start + ns.func_end + ns.nop + ns.tbb + ns.func_start: ## ignore
        return empty()
    else:
        print(insn)
        raise Exception



def binop(sign, i):
    if len(i) == 3:
        return (i[1] + b' = ' + i[1] + sign + i[2])
    elif len(i) == 4 or (i[0] == b'add' and len(i) == 8): # special case for dumb comments
        return (i[1] + b' = ' + i[2] + sign + i[3])
    else:
        if i[4] == b'asr' or i[4] == b'lsr':
            shift = b' >> '
        elif i[4] == b'lsl' or i[4] == b'asl':
            shift = b' << '
        else:
            print(i)
            raise Exception
        return (i[1] + b' = ' + i[2] + sign + b'(' + i[3] + shift + i[5] + b')')

def empty ():
    return b''

def mov(i):
    return i[1] + b' = ' + i[2]

def n_mov(i):
    return i[1] + b' = ~' + i[2]

def aand(i):
    return binop(b' & ', i)

def bic(i):
    return binop(b' & ~', i)

def add(i):
    return binop(b' + ', i)

def sub(i):
    return binop(b' - ', i)

def rev_sub(i):
    return i[1] + b' = ' + i[-2] + b' - ' + i[-1]

def mul(i):
    return i[1] + b' = ' + i[-2] + b' * ' + i[-1]

def smull(i):
    return i[2] + b' = ' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF00000000 >> 32;\n' + i[1] + b' = (unsigned int) (' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF )'

def vmlas(i):
    return i[1] + b' =  (' + i[1] + b' + ' + i[2] + b' * ' + i[3] + b' )'

def div(i):
    return i[1] + b' = ' + i[-2] + b' / ' + i[-1]

def orr(i):
    return binop(b' | ', i)

def bits(i):
    if i[0] == b'ubfx':
        lsb = int(i[3])
        width = int(i[4])
        val = 0
        for j in range(lsb, width + lsb):
            val += 2**j
        return i[1] + b' = ' + i[2] + b' & ' + bytes(hex(val), 'utf-8')
    elif i[0] == b'bfc':
        lsb = int(i[2])
        width = int(i[3])
        val = 0
        for j in range(lsb, width + lsb):
            val += 2**j
        return i[1] + b' = ' + i[1] + b' & ~ ' + bytes(hex(val), 'utf-8')

def sxtab(i):
    return i[1] + b' = ' + i[2] + b' + (int) (char) ' + i[3]

def shift_left(i):
    if len(i) == 4:
        return i[1] + b' = ' + i[-2] + b' << ' + i[-1] 
    else:
        print(i)
        raise Exception

def shift_right(i):
    if len(i) == 4:
        return i[1] + b' = ' + i[-2] + b' >> ' + i[-1]
    else:
        print(i)
        raise Exception

def cast(i):
    if i[0] in ns.cast_to_float:
        return i[1] + b' = (float) ' + i[2]
    elif i[0] in ns.cast_to_int:
        return i[1] + b' = (int) ' + i[2]
    elif i[0] in ns.cast_to_uint:
        return i[1] + b' = (unsigned int) ' + i[2] 
    else:
        print(i)
        raise Exception

def load(i):

    if len(i) < 4:
        addr = i[2]
    elif len(i) < 5:
        if i[3].startswith(b'"'):
            addr = i[2]
        else:
            addr = i[2] + b' + ' + i[3]
    else:
        addr = i[2] + b' + ' + i[3] + b' << ' + i[5]

    return i[1] + b' = *( ' + addr + b' )'

def load_d(i):

    if len(i) == 4:
        addr = i[3]
    elif len(i) == 5:
        if i[3].startswith(b'"'):
            addr = i[3]
        else:
            addr = i[3] + b' + ' + i[4]
    elif len(i) == 7:
        addr = i[3] + b' + ' + i[4] + b' << ' + i[6]
    else:
        print(i)
        raise Exception
    
    return i[1] + b' = *( ' + addr + b' );\n' + i[2] + b' = *( ' + addr + b' + 4 )'

def store(i):
    if len(i) == 3:
        return b'*( ' + i[2] + b' ) = ' + i[1]
    elif len(i) == 4:
        return b'*( ' + i[2] + b' + ' + i[3] + b' ) = ' + i[1]
    elif len(i) == 6 and i[4] == b'lsl':
        return b'*( ' + i[2] + b' + ' + i[3] + b' << ' + i[4] + b' ) = ' + i[1]
    else:
        print(i)
        raise Exception

def store_d(i):
    if len(i) == 4:
        out1 = b'*( ' + i[3] + b') = ' + i[1]
        out2 = b'*( ' + i[3] + b' + 4) = ' + i[2]
    if len(i) == 5:
        out1 = b'*( ' + i[3] + b' + ' + i[4] + b' ) = ' + i[1]
        out2 = b'*( ' + i[3] + b' + ' + i[4] + b' + 4 ) = ' + i[2]
    else:
        print(i)
        raise Exception

    return out1 + b';\n' + out2
# store = (lambda i:  b'*( ' + (i[2] if len(i) < 4 else (i[2] + b' + ' + i[3] if len(i) < 5 else i[2] + b' + ' + i[3] + b' << ' + i[5])) + b' ) = ' + i[1] )

def func_call (i):
    if len(i) == 2:
        return b'func_'+i[1]+b'();'

    if i[3] == b'int':
        return_tag = b'r0 = '
    elif i[3] == b'long':
        return_tag = b'r0 = '
    elif i[3] == b'float':
        return_tag = b's0 = '
    elif i[3] == b'double':
        return_tag = b'd0 = '
    elif i[3] == b'void':
        return_tag = b''
    else:
        raise Exception


    if len(i) <= 6:
        args = b''
    elif len(i) == 9:
        args = i[7]
    elif len(i) == 11:
        args = b','.join([i[7], i[9]])
    elif len(i) == 13:
        args = b','.join([i[7], i[9], i[11]])
    else:
        args = b','.join([i[7], i[9], i[11], i[13]])

    output = return_tag + i[4] + b'(' + args + b')'

    return output

def preprocess_input(raw):

    lines = raw.split(b'\n')

    sections = []

    comment_switch = False

    section = []
    for line in lines:
        stripped = line.lstrip()
        if stripped.startswith(b'/*'):
            sections.append({'type' : comment_switch, 'section': section})
            section = []
            section.append(line)
            comment_switch = True
        elif stripped.startswith(b'*/'):
            section.append(line)
            sections.append({'type' : comment_switch, 'section': section})
            section = []
            comment_switch = False
        else:
            section.append(line)

    sections.append({'type' : comment_switch, 'section' : section}) ## write the last section
    return sections

def convert_output(sections):
    out = []
    for section in sections:
        if section['type']:
            for line in section['section']:
                out.append(line)
            for line in section['code']:
                out.append(line)
        else:
            for line in section['section']:
                out.append(line)

    return b'\n'.join(out)

def convert(raw):
    
    sections = preprocess_input(raw)

    mapped_sections = map_sections(sections)
    
    return convert_output(mapped_sections)
    

if __name__ == "__main__":

    parser = argparse.ArgumentParser('Provide input and output locations')
    parser.add_argument('input_file', metavar='i', type=str, help="input file")
    parser.add_argument('output_file', metavar='o', type=str, help="output file")

    args = parser.parse_args()

    f = open(args.input_file, 'rb')

    raw = f.read()

    output = convert(raw)
  
    out_file = open(args.output_file, 'wb')

    out_file.write(output)


