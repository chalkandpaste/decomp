import subprocess
import struct

from instructions import *

def disassemble_section(section_bytes):
    cmd = [ b'rasm2',
            b'-a', b'arm.gnu', ## only disassembly that works
            b'-b', b'16', ## bit == thumb
            b'-c', b'm4', ## cpu set
            b'-d',        ## disassemble
            b'-D',        ## give me location information and stuff
            section_bytes
            ]
    command_result = subprocess.run(cmd, capture_output=True)
    return command_result.stdout

def fix_jump_offset(jump_offset):
    if int(jump_offset, 0) > 0x7FFFFFF:
        jump_offset = twos_complement(jump_offset)
    else:
        jump_offset = int(jump_offset, 0)

    return jump_offset

def twos_complement(hexstr):
    bits = len(hexstr[2:]) * 4
    value = int(hexstr, 0)
    if value & (1 << (bits-1)):
        value -= 1 << bits
    return value

class InstructionsBuffer:

    def __init__(self, binary, entry_point_loc = 0x08020004, binary_offset_loc=0x08020000, n_bytes=4096):
        # bin_obj
        self.binary = binary
        self.binary_offset_loc = binary_offset_loc

        # insns_buffer
        self.buff_len_bytes = n_bytes
        self.update_loc(entry_point_loc)

    # type
    # { 'offset' : 0x08020000, 'binary' : binary }

    def read_instructions_binary(self, loc):
        true_loc = loc - self.binary_offset_loc
        n_bytes = self.buff_len_bytes
        by = bytes(self.binary[true_loc:true_loc+n_bytes].hex(), 'utf-8')
        insns = disassemble_section(by)
        insns1 = []
        insns = [i for i in filter(lambda i: i is not b'', insns.split(b'\n'))]
        for j in range(len(insns) - 1):
            i = insns[j]
            insn = list(filter(lambda p: p is not b'', i.split(b' ')))

            insn[0] = bytes(hex((loc + int(insn[0], 0))), 'utf-8')
            
            if insn[3] in cond_block_end + uncond_block_end + func_call:
                jump_offset = fix_jump_offset(insn[4])
                insn[4] = bytes(hex(loc + jump_offset), 'utf-8')
            
            elif insn[3] in cond_block_end_zero:
                jump_offset = fix_jump_offset(insn[5])
                insn[5] = bytes(hex(loc + jump_offset), 'utf-8')
           
            elif insn[3] in tbb:
                if insn[3] == b'tbb':
                    tbb_loc = int(insn[0], 0) + int(insn[1])

                    locs = []
                    
                    end = False
                    index = 0
                    while not end:
                        offset = int(self.read_data_at_loc(tbb_loc + index, 1))
                        if offset == 0:
                            end = True
                        else:
                            locs.append(tbb_loc + 2*offset)
                            index += 1

                    insn.append(locs)

                else:
                    print(insn)
                    raise Exception

            elif insn[3] == b'vmov.f32':
                if len(insn) > 6:
                    insn[5] = insn[8]
                insn = insn[0:6]

            elif insn[3] in load:
                f = False
                if insn[5] == b'[pc,':
                    curr_loc = int(insn[0], 0)
                    insn_len = int(insn[1])
                    next_insn_line = insns[j+1]
                    next_insn = list(filter(lambda p: p is not b'', next_insn_line.split(b' ')))
                    next_insn_len = int(next_insn[1])
                    data_offset = int(insn[6].rstrip(b']'), 0)
                    if 0x7ffffff > data_offset > 1024:
                        data_offset = 1024 - data_offset
                    elif data_offset > 0x7fffffff or data_offset < -1024:
                        data_offset = twos_complement(insn[6].rstrip(b']'))
                    
                    data_loc = curr_loc + 4 + data_offset
                    off_word = data_loc % 4

                    data_loc -= off_word
                    
                    if insn[3] in load_u32:
                        data_val = self.read_data_at_loc(data_loc, 4)
                    elif insn[3] in load_u16:
                        data_val = self.read_data_at_loc(data_loc, 2)
                    elif insn[3] in load_s16:
                        data_val = self.read_data_at_loc(data_loc, 2, signed=True)
                    elif insn[3] in load_u8:
                        data_val = self.read_data_at_loc(data_loc, 1)
                    elif insn[3] in load_s8:
                        data_val = self.read_data_at_loc(data_loc, 1, signed=True)
                    elif insn[3] in load_fp:
                        f = True
                        if insn[4].startswith(b'd'):
                            data_val = self.read_data_at_loc(data_loc, 8, f = True)
                        if insn[4].startswith(b's'):
                            data_val = self.read_data_at_loc(data_loc, 4, f = True)
                    else:
                        raise Exception

                    insn[3] = b'mov' if not f else b'vmov'
                    insn[5] = data_val
                    insn = insn[0:6]
           
            insns1.append(insn)

        return insns1

    def update_loc(self, new_loc):
        self.curr_offset_loc = new_loc
        self.insns_buff = self.read_instructions_binary(self.curr_offset_loc)
        self.insns_buff_index = { int(v[0],0) : i for (i,v) in enumerate(self.insns_buff) }

    def read_data_at_loc(self, loc, length, signed = False, f = False):
        data_loc = loc - self.binary_offset_loc
        data = self.binary[data_loc:data_loc + length]

        if length == 8 and f:
            # data = data[4:8] + data[0:4]
            data_val, = struct.unpack('<d', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 4 and f:
            data_val, = struct.unpack('<f', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 4:
            if signed:
                data_val, = struct.unpack('<i', data)
            else:
                data_val, = struct.unpack('<I', data)
            # pre-emptively exclude things which might be in 
            # program mem (0x0802...) or stack (0x2..) or periphs (0x3... 0x4... 0x5...)
            # write it as an address, little endian rotation
            if 0x8020000 < data_val or data_val < 0x8040000 or\
                    0x20000000 < data_val or data_val < 0x50000000:
                data_val = bytes(hex(data_val), 'utf-8')
            else:
                data_val = bytes(str(data_val), 'utf-8')
        elif length == 2:
            if signed:
                data_val, = struct.unpack('<h', data)
            else:
                data_val, = struct.unpack('<H', data)
            data_val = bytes(str(data_val), 'utf-8')
        elif length == 1:
            if signed:
                data_val, = struct.unpack('<b', data)
            else:
                data_val, = struct.unpack('<B', data)
            data_val = bytes(str(data_val), 'utf-8')
        else:
            raise Exception

        return data_val



    def read_insns_at_loc(self, loc):
        if loc in self.insns_buff_index:
            idx = self.insns_buff_index[loc]
        else:
            self.update_loc(loc)
            idx = self.insns_buff_index[loc]

        return self.insns_buff[idx:]
