import pickle
import re
import argparse

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
                    try:
                        instruction = list(filter(lambda a: a != b'', line.lstrip().split(b' ')))[2:]
                        instruction = [i.lstrip(b'[#').rstrip(b',;]\n') for i in instruction]
                    except:
                        instruction = None

                    if instruction:
                        if instruction[0] not in c_map:
                            print(instruction[0])
                            raise Exception 
                        output = c_map[instruction[0]](instruction)
                        if output is not b'':
                            code.append(output + b';\n')
            section['code'] = code
        else:
            section['code'] = None
        
        new_sections.append(section)

    return new_sections


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

def binop(sign, i):
    if len(i) <= 4:
        return (i[1] + b' = ' + i[-2] + sign + i[-1])
    else:
        if i[4] == b'asr' or i[4] == b'lsr':
            shift = b' >> '
        elif i[4] == b'lsl' or i[4] == b'asl':
            shift = b' << '
        else:
            raise Exception
        return (i[1] + b' = ' + i[2] + sign + b'(' + i[3] + shift + i[5] + b')')


mov = (lambda i:  i[1] + b' = ' + i[2] )

add = (lambda i: binop(b' + ', i))
sub = (lambda i: binop(b' - ', i))

# add = (lambda i:  i[1] + b' = ' + (i[-2] + b' + ' + i[-1] if len(i) <= 4 else i[2] + b' + ' + i[3] + (b' >> ' if i[4] == b'asr' else b' << ')  + i[5]) )
# sub = (lambda i:  i[1] + b' = ' + (i[-2] + b' - ' + i[-1] if len(i) <= 4 else i[2] + b' - ' + i[3] + (b' >> ' if i[4] == b'asr' else b' << ') + i[5]) )
rs  = (lambda i:  i[1] + b' = ' + i[3] + b' - ' + i[2] )
div = (lambda i:  i[1] + b' = ' + i[-2] + b' / ' + i[-1] )

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

    return i[1] + b' = *( ' + addr + b')'


store = (lambda i:  b'*( ' + (i[2] if len(i) < 4 else (i[2] + b' + ' + i[3] if len(i) < 5 else i[2] + b' + ' + i[3] + b' << ' + i[5])) + b' ) = ' + i[1] )

def func_call (i):
    no_return = (i[2] == b'void' or i[3] == b'void')
    
    if not no_return:
        if i[2] == b'int' or i[3] == b'int' or i[4] == b'int':
            return_tag = b'r0 = '

        elif i[2] == b'float' or i[3] == b'float' or i[4] == b'float':
            return_tag = b's0 = ' 
    else:
        return_tag = b''


    if len(i) <= 6:
        args = b''
    elif len(i) <= 8:
        args = b'r0'
    elif len(i) <= 10:
        args = b'r0,r1'
    elif len(i) <= 12:
        args = b'r0,r1,r2'
    else:
        args = b'r0,r1,r2,r3'

    return return_tag + i[1] + b'(' + args + b')'

empty = (lambda i: b'')

c_map = {
    b'movs'     : mov,
    b'vmov.f32' : mov,
    b'movw'     : mov,
    b'mov'      : mov,
    b'vmov'     : mov,
    b'mov.w'    : mov,
    
    b'vsub.f32'  : sub,
    b'sub'       : sub,
    b'sub.w'     : sub,
    b'subs'      : sub,
    b'rsb.w'     : rs,
    b'rsbs'      : rs,
    
    b'and.w'  : (lambda i:  i[1] + b' = ' + (i[-2] + b' & ' + i[-1] if len(i) <= 4 else i[2] + b' & ' + i[3] + (b' >> ' if i[4] == b'asr' else b' << ') + i[5]) ),
    
    b'add'    : add,
    b'add.w'  : add,
    b'adds'   : add,
    b'vadd.f32'  : (lambda i:  i[1] + b' = ' + i[-2] + b' + ' + i[-1] ),
    
    b'sdiv'      : div,
    b'vdiv.f32'  : div, 
    
    b'muls'      : (lambda i:  i[1] + b' = ' + i[-2] + b' * ' + i[-1] ),
    b'smull'     : (lambda i:  i[2] + b' = ' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF00000000 >> 32;\n' + i[1] + b' = (unsigned int) (' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF )' ),
    b'vmul.f32'  : (lambda i:  i[1] + b' = ' + i[-2] + b' * ' + i[-1] ),
    
    b'vmla.f32'   : (lambda i:  i[1] + b' =  (' + i[1] + b' + ' + i[2] + b' * ' + i[3] + b' )' ),
    b'vmls.f32'   : (lambda i:  i[1] + b' =  (' + i[1] + b' - ' + i[2] + b' * ' + i[3] + b' )' ),
    b'vnmls.f32'  : (lambda i:  i[1] + b' = -(' + i[1] + b' - ' + i[2] + b' * ' + i[3] + b' )' ),
    
    b'and'  : (lambda i: binop(b' & ', i) ), 
    b'bic'  : (lambda i:  binop(b' & ~', i) ),
    b'lsrs'  : (lambda i:  i[1] + b' = ' + i[-2] + b' >> ' + i[-1] ),
    b'lsls'  : (lambda i:  i[1] + b' = ' + i[-2] + b' << ' + i[-1] ),
    b'asrs'  : (lambda i:  i[1] + b' = ' + i[-2] + b' >> ' + i[-1] ),
    
    
    b'vcvt.f32.s32'  : (lambda i:  i[1] + b' = (float) ' + i[2] ),
    b'vcvt.f32.u32'  : (lambda i:  i[1] + b' = (float) ' + i[2] ),
    b'vcvt.u32.f32'  : (lambda i:  i[1] + b' = (unsigned int) ' + i[2] ),
    b'vcvt.s32.f32'  : (lambda i:  i[1] + b' = (int) ' + i[2] ),
    b'uxth'          : (lambda i:  i[1] + b' = (unsigned int) ' + i[2] ),
    b'ubfx'          : (lambda i:  i[1] + b' = (unsigned int) ' + i[2] ),
    b'sxth'          : (lambda i:  i[1] + b' = (int) ' + i[2] ),
    b'sxtb'          : (lambda i:  i[1] + b' = (int) ' + i[2] ),
    b'sxth.w'        : (lambda i:  i[1] + b' = (int) ' + i[2] ),
    b'uxtb'          : (lambda i:  i[1] + b' = (unsigned int) ' + i[2] ),
   
    b'sxtab'         : (lambda i: i[1] + b' = ' + i[2] + b' + (int) (char) ' + i[3]),

    b'strb.w'  : store,
    b'strb'    : store,
    b'strh.w'  : store,
    b'vstr'    : store,
    b'str'     : store,
    b'str.w'   : store,
    b'strh'    : store,
    
    b'ldrsh.w' : load,
    b'ldrb.w'  : load,
    b'ldr.w'   : load,
    b'vldr'    : load,
    b'ldr'     : load,
    b'ldrh'  : load,
    b'ldrh.w'  : load,
    b'ldrb'    : load,



    b'push.w'  : empty, 
    b'vpush'  : empty,
    b'bl'  : func_call,
    b'bls.w'  : empty,
    b'cbz'  : empty,
    b'b'  : empty,
    b'cmp'  : empty,
    b'beq'  : empty,
    b'bne'  : empty,
    b'bne.w'  : empty,
    b'blt'  : empty,
    b'blo'  : empty,
    b''     : empty,
    b'bhs'  : empty,
    b'bhs.w'  : empty,
    b'ble'  : empty,
    b'bge'  : empty,
    b'bge.w'  : empty,
    b'bls'  : empty,
    b'cbnz'  : empty,
    b'bhi'  : empty,
    b'bhi.w'  : empty,
    b'vcmpe.f32'  : empty,
    b'tbb'  : empty,
    b'vmrs'  : empty,
    b'beq.w'  : empty,
    b'vpop'  : empty,
    b'pop.w'  : empty,
    b'b.w'  : empty,
    b'blt.w'  : empty,
    b'cmp.w'  : empty,
    b'[' : empty,
}

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


