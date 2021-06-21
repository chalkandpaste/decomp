
def crs(reg_string): # clean reg string
    reg_string_clean = reg_string.lstrip(b'[').rstrip(b'],')
    return reg_string_clean 


load_fp = [ b'vldr' ]
load_u32 = [ b'ldr', b'ldr.w' ]
load_u16 = [ b'ldrh', b'ldrh.w' ]
load_s16 = [ b'ldrsh', b'ldrsh.w' ]
load_u8 = [ b'ldrb', b'ldrb.w' ]
load_s8 = [ b'ldrsb', b'ldrsb.w' ]

load = load_fp + load_u32 + load_u16 + load_s16 + load_u8 + load_s8

load_d = [ b'ldrd', b'ldrd.n', b'ldrd.w' ]

store = [ b'strb.w', b'strb', b'strh.w', b'vstr', b'str', b'strh', b'str.w' ]

store_d = [ b'strd', b'strd.n', b'strd.w' ]

func_call = [b'bl', b'bl.w', b'bl.n']

func_start = [b'stmdb', b'stmdb.w', b'stmia', b'stmia.w',  b'push.w', b'push', b'vpush', b'vpush.n', b'vpush.w' ]

# b'vpop', but we always do a pop
func_end = [ b'pop.w', b'pop.n', b'pop', b'ldmia', b'ldmia.w', b'ldmia.n' ]
vpop = [b'vpop'] # treated differently

compare = [ b'cmp',   b'cmp.w' ]
ncompare = [ b'cmn', b'cmn.w', b'cmn.n' ]
fp_compare = [ b'vcmpe.f32' ]

compares = compare + ncompare + fp_compare

block_end_start = compare + fp_compare

cond_block_end_zero = [ b'cbnz', b'cbz' ]

nop = [ b'nop', b'nop.w', b'nop.n' ]
# b'vmrs',

beq = [ b'beq', b'beq.n', b'beq.w' ]
bne = [ b'bne', b'bne.w', b'bne.n' ]
ble = [ b'bls', b'bls.w', b'bls.n', b'ble', b'ble.w', b'ble.n' ] 
blt = [ b'blt', b'blt.n', b'blt.w' , b'blo', b'blo.n', b'blo.w', b'bcc', b'bcc.n', b'bcc.w', b'bmi', b'bmi.w', b'bmi.n']
bge = [ b'bhs', b'bhs.w', b'bhs.n', b'bcs', b'bcs.w', b'bcs.n', b'bge', b'bge.w', b'bge.n' ]
bgt = [ b'bhi', b'bhi.w', b'bhi.n', b'bpl.n', b'bpl.w', b'bgt', b'bgt.n' ] 

cond_block_end = beq + bne + ble + blt + bge + bgt

fucking_shit = [ b'blx', b'bx' ]

uncond_block_end = [ b'b', b'b.n',b'b.w' ]

tbb = [b'tbb', b'tbb.n', b'tbb.w', b'tbh', b'tbh.n', 'tbh.w']

branch = cond_block_end + uncond_block_end + cond_block_end_zero + tbb

block_end = cond_block_end + cond_block_end_zero + uncond_block_end + tbb

add = [ b'add', b'add.w', b'adds', b'adds.w', b'vadd.f32', b'addw' ]
sub = [ b'sub', b'sub.w', b'subs', b'subs.w', b'vsub.f32' ]
rsb = [ b'rsb', b'rsb.w', b'rsbs', b'negs' ]
aand = [ b'and', b'and.w', b'ands.w', b'ands', b'ands.n' ]
orr = [ b'orr', b'orr.w', b'orrs', b'orrs.w' ]
bic = [ b'bic', b'bic.w', b'bics', ]
shift_right = [ b'lsrs', b'asrs', b'lsr.w', b'lsr' ]
shift_left = [ b'lsls' ]
base_arith = add + sub + rsb + aand + orr + bic + shift_right + shift_left

mul = [ b'vmul.f32', b'muls', b'smulbb', b'smulbt', b'smultt', b'smultb', b'mul.w' ]

smull = [ b'smull', b'umull' ]

div = [ b'sdiv', b'udiv', b'vdiv.f32' ]

vmlas = [ b'vmla.f32', b'vmls.f32', b'vnmls.f32', b'mla', b'mla.n', b'mla.w', b'mls', b'mls.w', b'mls.n', b'smlal' ]

cast_to_float = [ b'vcvt.f32.s32', b'vcvt.f32.u32' ]
cast_to_int = [ b'vcvt.s32.f32', b'sxth', b'sxtb', b'sxth.w', ]
cast_to_uint = [ b'vcvt.u32.f32', b'uxth', b'uxth.w', b'uxtb',  ]

cast = cast_to_float + cast_to_int + cast_to_uint

bits = [ b'ubfx', b'bfc' ]

sxtab = [ b'sxtab', b'sxtah' ]


moves = [ b'mov', b'movw', b'movs', b'movs.w',  b'vmov.f32', b'mov.w', b'vmov', b'vmrs'] 
n_moves = [ b'mvn', b'mvn.w' ]
move = moves + n_moves

cond_branch = cond_block_end + cond_block_end_zero + tbb

tst = [ b'tst', b'tst.w', b'tst.n' ]
