import argparse
from typing import TypeAlias

from . import instructions as ns
from .legacy_types import LegacyConvertedSection, LegacyLineSection

InstructionTokens: TypeAlias = list[bytes]


def instruction_mnemonic(instruction: InstructionTokens) -> bytes:
    return instruction[0]


def instruction_operand(instruction: InstructionTokens, index: int) -> bytes:
    return instruction[index + 1]


def last_instruction_operands(instruction: InstructionTokens, count: int) -> tuple[bytes, ...]:
    return tuple(instruction[-count:])


def map_sections(sections: list[LegacyLineSection]) -> list[LegacyConvertedSection]:
    new_sections = []
    for section in sections:
        if section.type:
            comments = section
            code = []
            for line in comments.section:
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
                        try:
                            code.append(output + b';')
                        except:
                            print(instruction)
                            raise Exception
            new_section = LegacyConvertedSection(type=section.type, section=section.section, code=tuple(code))
        else:
            new_section = LegacyConvertedSection(type=section.type, section=section.section, code=None)
        
        new_sections.append(new_section)

    return new_sections

def convert_instruction(insn: InstructionTokens) -> bytes:
    mnemonic = instruction_mnemonic(insn)
    if mnemonic in ns.moves:
        return mov(insn)
    if mnemonic in ns.n_moves:
        return n_mov(insn)
    if mnemonic in ns.load:
        return load(insn)
    if mnemonic in ns.load_d:
        return load_d(insn)
    if mnemonic in ns.store:
        return store(insn)
    if mnemonic in ns.store_d:
        return store_d(insn)
    elif mnemonic in ns.add:
        return add(insn)
    elif mnemonic in ns.sub:
        return sub(insn)
    elif mnemonic in ns.rsb:
        return rev_sub(insn)
    elif mnemonic in ns.mul:
        return mul(insn)
    elif mnemonic in ns.smull:
        return smull(insn)
    elif mnemonic in ns.vmlas:
        return vmlas(insn)
    elif mnemonic in ns.div:
        return div(insn)
    elif mnemonic in ns.aand:
        return aand(insn)
    elif mnemonic in ns.bic:
        return bic(insn)
    elif mnemonic in ns.orr:
        return orr(insn)
    elif mnemonic in ns.shift_left:
        return shift_left(insn)
    elif mnemonic in ns.shift_right:
        return shift_right(insn)
    elif mnemonic in ns.cast:
        return cast(insn)
    elif mnemonic in ns.sxtab:
        return sxtab(insn)
    elif mnemonic in ns.bits:
        return bits(insn)
    elif mnemonic in ns.func_call:
        return func_call(insn)
    elif mnemonic in ns.uncond_block_end:
        if len(insn) > 2:
            return func_call(insn)
        else:
            return b''
    elif mnemonic in ns.exchange_return + ns.exchange_func_call + ns.vpop + ns.cond_block_end + ns.cond_block_end_zero + ns.block_end_start + ns.func_end + ns.nop + ns.tbb + ns.func_start: ## ignore
        return empty()
    else:
        print(insn)
        raise Exception



def binop(sign: bytes, i: InstructionTokens) -> bytes:
    mnemonic = instruction_mnemonic(i)
    destination = instruction_operand(i, 0)
    if len(i) == 3:
        return (destination + b' = ' + destination + sign + instruction_operand(i, 1))
    elif len(i) == 4 or (mnemonic == b'add' and len(i) == 8): # special case for dumb comments
        return (destination + b' = ' + instruction_operand(i, 1) + sign + instruction_operand(i, 2))
    else:
        shift_kind = instruction_operand(i, 3)
        if shift_kind == b'asr' or shift_kind == b'lsr':
            shift = b' >> '
        elif shift_kind == b'lsl' or shift_kind == b'asl':
            shift = b' << '
        else:
            print(i)
            raise Exception
        return (
            destination +
            b' = ' +
            instruction_operand(i, 1) +
            sign +
            b'(' +
            instruction_operand(i, 2) +
            shift +
            instruction_operand(i, 4) +
            b')'
        )

def empty() -> bytes:
    return b''

def mov(i: InstructionTokens) -> bytes:
    return instruction_operand(i, 0) + b' = ' + instruction_operand(i, 1)

def n_mov(i: InstructionTokens) -> bytes:
    return instruction_operand(i, 0) + b' = ~' + instruction_operand(i, 1)

def aand(i: InstructionTokens) -> bytes:
    return binop(b' & ', i)

def bic(i: InstructionTokens) -> bytes:
    return binop(b' & ~', i)

def add(i: InstructionTokens) -> bytes:
    return binop(b' + ', i)

def sub(i: InstructionTokens) -> bytes:
    return binop(b' - ', i)

def rev_sub(i: InstructionTokens) -> bytes:
    left, right = last_instruction_operands(i, 2)
    return instruction_operand(i, 0) + b' = ' + left + b' - ' + right

def mul(i: InstructionTokens) -> bytes:
    left, right = last_instruction_operands(i, 2)
    return instruction_operand(i, 0) + b' = ' + left + b' * ' + right

def smull(i: InstructionTokens) -> bytes:
    return i[2] + b' = ' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF00000000 >> 32;\n' + i[1] + b' = (unsigned int) (' + i[3] + b' * ' + i[4] + b' & 0xFFFFFFFF )'

def vmlas(i: InstructionTokens) -> bytes:
    destination = instruction_operand(i, 0)
    left = instruction_operand(i, 1)
    right = instruction_operand(i, 2)
    return destination + b' =  (' + destination + b' + ' + left + b' * ' + right + b' )'

def div(i: InstructionTokens) -> bytes:
    left, right = last_instruction_operands(i, 2)
    return instruction_operand(i, 0) + b' = ' + left + b' / ' + right

def orr(i: InstructionTokens) -> bytes:
    return binop(b' | ', i)

def bits(i: InstructionTokens) -> bytes:
    if i[0] == b'ubfx':
        lsb = int(i[3])
        width = int(i[4])
        val = 0
        for j in range(lsb, width + lsb):
            val += 2**j
        return i[1] + b' = ' + i[2] + b' & ' + bytes(hex(val), 'utf-8')
    elif i[0] == b'bfc' and len(i) == 4:
        lsb = int(i[2])
        width = int(i[3])
        val = 0
        for j in range(lsb, width + lsb):
            val += 2**j
        return i[1] + b' = ' + i[1] + b' & ~ ' + bytes(hex(val), 'utf-8')
    elif i[0] == b'bfi' and len(i) == 5:
        reg = i[2]
        lsb = int(i[3])
        width = int(i[4])
        val = 0
        for j in range(lsb, width + lsb):
            val += 2**j
        return i[1] + b' = ' + i[2] + b' | ' + bytes(hex(val), 'utf-8')
    else:
        print(i)
        raise Exception


def sxtab(i: InstructionTokens) -> bytes:
    destination = instruction_operand(i, 0)
    addend = instruction_operand(i, 1)
    extended = instruction_operand(i, 2)
    return destination + b' = ' + addend + b' + (int) (char) ' + extended

def shift_left(i: InstructionTokens) -> bytes:
    if len(i) == 3:
        return i[1] + b' = ' + i[1] + b' << ' + i[2]
    elif len(i) == 4:
        return i[1] + b' = ' + i[-2] + b' << ' + i[-1] 
    else:
        print(i)
        raise Exception

def shift_right(i: InstructionTokens) -> bytes:
    if len(i) == 3:
        return i[1] + b' = ' + i[1] + b' >> ' + i[2]
    elif len(i) == 4:
        return i[1] + b' = ' + i[2] + b' >> ' + i[3]
    else:
        print(i)
        raise Exception

def cast(i: InstructionTokens) -> bytes:
    if i[0] in ns.cast_to_float:
        return i[1] + b' = (float) ' + i[2]
    elif i[0] in ns.cast_to_int:
        return i[1] + b' = (int) ' + i[2]
    elif i[0] in ns.cast_to_uint:
        return i[1] + b' = (unsigned int) ' + i[2] 
    else:
        print(i)
        raise Exception

def load(i: InstructionTokens) -> bytes:

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

def load_d(i: InstructionTokens) -> bytes:

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

def store(i: InstructionTokens) -> bytes:
    if len(i) == 3:
        return b'*( ' + i[2] + b' ) = ' + i[1]
    elif len(i) == 4:
        return b'*( ' + i[2] + b' + ' + i[3] + b' ) = ' + i[1]
    elif len(i) == 6 and i[4] == b'lsl':
        return b'*( ' + i[2] + b' + ' + i[3] + b' << ' + i[4] + b' ) = ' + i[1]
    else:
        print(i)
        raise Exception

def store_d(i: InstructionTokens) -> bytes:
    if len(i) == 4:
        out1 = b'*( ' + i[3] + b') = ' + i[1]
        out2 = b'*( ' + i[3] + b' + 4) = ' + i[2]
    elif len(i) == 5:
        out1 = b'*( ' + i[3] + b' + ' + i[4] + b' ) = ' + i[1]
        out2 = b'*( ' + i[3] + b' + ' + i[4] + b' + 4 ) = ' + i[2]
    else:
        print(i)
        raise Exception

    return out1 + b';\n' + out2
# store = (lambda i:  b'*( ' + (i[2] if len(i) < 4 else (i[2] + b' + ' + i[3] if len(i) < 5 else i[2] + b' + ' + i[3] + b' << ' + i[5])) + b' ) = ' + i[1] )

def func_call(i: InstructionTokens) -> bytes:
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

def preprocess_input(raw: bytes) -> list[LegacyLineSection]:

    lines = raw.split(b'\n')

    sections = []

    comment_switch = False

    section = []
    for line in lines:
        stripped = line.lstrip()
        if stripped.startswith(b'/*'):
            sections.append(LegacyLineSection(type=comment_switch, section=tuple(section)))
            section = []
            section.append(line)
            comment_switch = True
        elif stripped.startswith(b'*/'):
            section.append(line)
            sections.append(LegacyLineSection(type=comment_switch, section=tuple(section)))
            section = []
            comment_switch = False
        else:
            section.append(line)

    sections.append(LegacyLineSection(type=comment_switch, section=tuple(section))) ## write the last section
    return sections

def convert_output(sections: list[LegacyConvertedSection]) -> bytes:
    out = []
    for section in sections:
        if section.type:
            for line in section.section:
                out.append(line)
            for line in section.code or ():
                out.append(line)
        else:
            for line in section.section:
                out.append(line)

    return b'\n'.join(out)

def convert(raw: bytes) -> bytes:
    
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
