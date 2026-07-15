from __future__ import annotations

import re
import struct
import subprocess

from decomp.arch.base import DisassemblerConfig
from decomp.core.flow import FlowInfo, FlowKind
from decomp.core.image import FirmwareImage
from decomp.core.instruction import Instruction, Operand, OperandKind
from decomp.instructions import (
    cond_block_end,
    cond_block_end_zero,
    exchange_func_call,
    exchange_return,
    func_call,
    func_end,
    load,
    load_fp,
    load_s16,
    load_s8,
    load_u16,
    load_u32,
    load_u8,
    tbb,
    uncond_block_end,
)


class ArmThumbBackend:
    id = "arm-thumb"
    display_name = "ARM Thumb / Cortex-M"
    disassembler = DisassemblerConfig(
        tool="rasm2",
        architecture="arm.gnu",
        bits=16,
        extra_args=("-c", "m4"),
    )

    def disassemble_section(self, section_bytes: bytes) -> bytes:
        cmd = [
            self.disassembler.tool.encode("ascii"),
            b"-a",
            self.disassembler.architecture.encode("ascii"),
            b"-b",
            str(self.disassembler.bits).encode("ascii"),
            b"-d",
            section_bytes,
        ]
        analysis_cmd = [
            self.disassembler.tool.encode("ascii"),
            b"-a",
            self.disassembler.architecture.encode("ascii"),
            b"-b",
            str(self.disassembler.bits).encode("ascii"),
            b"-A",
            section_bytes,
        ]
        command_result = subprocess.run(cmd, capture_output=True)
        analysis_result = subprocess.run(analysis_cmd, capture_output=True)
        return normalize_rasm2_output(command_result.stdout, analysis_result.stdout)

    def decode_window(
        self,
        binary: bytes,
        address: int,
        *,
        base_address: int = 0x08020000,
        size: int = 4096,
    ) -> tuple[Instruction, ...]:
        return tuple(
            self.decode_legacy_tokens(tokens)
            for tokens in self.decode_window_as_legacy_tokens(
                binary,
                address,
                base_address=base_address,
                size=size,
            )
        )

    def decode_window_as_legacy_tokens(
        self,
        binary: bytes,
        address: int,
        *,
        base_address: int = 0x08020000,
        size: int = 4096,
    ) -> list[list[object]]:
        true_offset = address - base_address
        section_bytes = bytes(binary[true_offset:true_offset + size].hex(), "utf-8")
        disassembled = self.disassemble_section(section_bytes)
        lines = [line for line in disassembled.split(b"\n") if line]
        decoded = []

        for line in lines:
            tokens = list(filter(lambda part: part != b"", line.split(b" ")))
            tokens[0] = bytes(hex(address + int(tokens[0], 0)), "utf-8")
            tokens = self._normalize_legacy_tokens(tokens, binary, address, base_address)
            decoded.append(tokens)

        return decoded

    def decode_legacy_tokens(self, tokens: list[object]) -> Instruction:
        address = int(tokens[0], 0)
        size = int(tokens[1], 0)
        data = bytes.fromhex(tokens[2].decode("ascii"))
        mnemonic = tokens[3].decode("ascii")
        operands = tuple(self._decode_operand(token) for token in tokens[4:] if isinstance(token, bytes))
        provisional = Instruction(
            address=address,
            size=size,
            data=data,
            mnemonic=mnemonic,
            operands=operands,
            raw_tokens=tuple(token for token in tokens if isinstance(token, bytes)),
            source="legacy-rasm2",
        )
        return Instruction(
            address=provisional.address,
            size=provisional.size,
            data=provisional.data,
            mnemonic=provisional.mnemonic,
            operands=provisional.operands,
            flow=self._classify_legacy_flow(tokens, address, size),
            raw_tokens=provisional.raw_tokens,
            source=provisional.source,
        )

    def classify_flow(self, instruction: Instruction) -> FlowInfo:
        mnemonic = instruction.mnemonic.encode("ascii")
        tokens = instruction.raw_tokens
        fallthrough = instruction.address + instruction.size

        if mnemonic in cond_block_end and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.CONDITIONAL_BRANCH,
                targets=(int(tokens[4], 0),),
                fallthrough=fallthrough,
            )
        if mnemonic in cond_block_end_zero and len(tokens) >= 6:
            return FlowInfo(
                kind=FlowKind.CONDITIONAL_BRANCH,
                targets=(int(tokens[5], 0),),
                fallthrough=fallthrough,
            )
        if mnemonic in uncond_block_end and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.UNCONDITIONAL_BRANCH,
                targets=(int(tokens[4], 0),),
            )
        if mnemonic in func_call and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.CALL,
                targets=(int(tokens[4], 0) & ~1,),
                fallthrough=fallthrough,
            )
        if mnemonic in exchange_func_call:
            return FlowInfo(kind=FlowKind.INDIRECT_CALL, fallthrough=fallthrough)
        if mnemonic in tbb:
            table_targets = ()
            if tokens and isinstance(tokens[-1], list):
                table_targets = tuple(tokens[-1])
            return FlowInfo(kind=FlowKind.SWITCH, targets=table_targets)
        if mnemonic in exchange_return and len(tokens) >= 5 and tokens[4] == b"lr":
            return FlowInfo(kind=FlowKind.RETURN, is_function_exit=True)
        if mnemonic in func_end:
            return FlowInfo(kind=FlowKind.RETURN, is_function_exit=True)
        return FlowInfo(kind=FlowKind.FALLTHROUGH, fallthrough=fallthrough)

    def _classify_legacy_flow(self, tokens: list[object], address: int, size: int) -> FlowInfo:
        mnemonic = tokens[3]
        fallthrough = address + size

        if mnemonic in cond_block_end and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.CONDITIONAL_BRANCH,
                targets=(int(tokens[4], 0),),
                fallthrough=fallthrough,
            )
        if mnemonic in cond_block_end_zero and len(tokens) >= 6:
            return FlowInfo(
                kind=FlowKind.CONDITIONAL_BRANCH,
                targets=(int(tokens[5], 0),),
                fallthrough=fallthrough,
            )
        if mnemonic in uncond_block_end and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.UNCONDITIONAL_BRANCH,
                targets=(int(tokens[4], 0),),
            )
        if mnemonic in func_call and len(tokens) >= 5:
            return FlowInfo(
                kind=FlowKind.CALL,
                targets=(int(tokens[4], 0) & ~1,),
                fallthrough=fallthrough,
            )
        if mnemonic in exchange_func_call:
            return FlowInfo(kind=FlowKind.INDIRECT_CALL, fallthrough=fallthrough)
        if mnemonic in tbb:
            table_targets = ()
            if tokens and isinstance(tokens[-1], list):
                table_targets = tuple(tokens[-1])
            return FlowInfo(kind=FlowKind.SWITCH, targets=table_targets)
        if mnemonic in exchange_return and len(tokens) >= 5 and tokens[4] == b"lr":
            return FlowInfo(kind=FlowKind.RETURN, is_function_exit=True)
        if mnemonic in func_end:
            return FlowInfo(kind=FlowKind.RETURN, is_function_exit=True)
        return FlowInfo(kind=FlowKind.FALLTHROUGH, fallthrough=fallthrough)

    def is_probable_code_address(self, image: FirmwareImage, value: int) -> bool:
        try:
            image.segment_for(value & ~1)
        except ValueError:
            return False
        return True

    def read_data_at_loc(
        self,
        binary: bytes,
        address: int,
        length: int,
        *,
        base_address: int = 0x08020000,
        signed: bool = False,
        float_value: bool = False,
    ) -> bytes:
        data_offset = address - base_address
        data = binary[data_offset:data_offset + length]

        if length == 8 and float_value:
            data_value, = struct.unpack("<d", data)
            return bytes(str(data_value), "utf-8")
        if length == 4 and float_value:
            data_value, = struct.unpack("<f", data)
            return bytes(str(data_value), "utf-8")
        if length == 4:
            if signed:
                data_value, = struct.unpack("<i", data)
            else:
                data_value, = struct.unpack("<I", data)
            if is_probable_address_literal(data_value):
                return bytes(hex(data_value), "utf-8")
            return bytes(str(data_value), "utf-8")
        if length == 2:
            if signed:
                data_value, = struct.unpack("<h", data)
            else:
                data_value, = struct.unpack("<H", data)
            return bytes(str(data_value), "utf-8")
        if length == 1:
            if signed:
                data_value, = struct.unpack("<b", data)
            else:
                data_value, = struct.unpack("<B", data)
            return bytes(str(data_value), "utf-8")

        raise ValueError(f"unsupported literal read width: {length}")

    def _normalize_legacy_tokens(
        self,
        tokens: list[object],
        binary: bytes,
        window_address: int,
        base_address: int,
    ) -> list[object]:
        mnemonic = tokens[3]

        if mnemonic in cond_block_end + uncond_block_end + func_call:
            jump_offset = fix_jump_offset(tokens[4])
            tokens[4] = bytes(hex(window_address + jump_offset), "utf-8")
        elif mnemonic in cond_block_end_zero:
            jump_offset = fix_jump_offset(tokens[5])
            tokens[5] = bytes(hex(window_address + jump_offset), "utf-8")
        elif mnemonic in tbb:
            if mnemonic == b"tbb":
                tbb_loc = int(tokens[0], 0) + int(tokens[1])
                locs = []
                index = 0
                while True:
                    offset = int(
                        self.read_data_at_loc(
                            binary,
                            tbb_loc + index,
                            1,
                            base_address=base_address,
                        )
                    )
                    if offset == 0:
                        break
                    locs.append(tbb_loc + 2 * offset)
                    index += 1
                tokens.append(locs)
            else:
                raise ValueError(f"unsupported table branch mnemonic: {mnemonic!r}")
        elif mnemonic == b"vmov.f32":
            if len(tokens) > 6:
                tokens[5] = tokens[8]
            tokens = tokens[0:6]
        elif mnemonic in load:
            tokens = self._normalize_pc_relative_load(tokens, binary, base_address)

        return tokens

    def _normalize_pc_relative_load(
        self,
        tokens: list[object],
        binary: bytes,
        base_address: int,
    ) -> list[object]:
        if len(tokens) <= 6 or tokens[5] != b"[pc,":
            return tokens

        mnemonic = tokens[3]
        curr_loc = int(tokens[0], 0)
        data_offset = int(tokens[6].rstrip(b"]"), 0)
        if 0x7ffffff > data_offset > 1024:
            data_offset = 1024 - data_offset
        elif data_offset > 0x7fffffff or data_offset < -1024:
            data_offset = twos_complement(tokens[6].rstrip(b"]"))

        data_loc = curr_loc + 4 + data_offset
        data_loc -= data_loc % 4

        is_float = False
        if mnemonic in load_u32:
            data_val = self.read_data_at_loc(binary, data_loc, 4, base_address=base_address)
        elif mnemonic in load_u16:
            data_val = self.read_data_at_loc(binary, data_loc, 2, base_address=base_address)
        elif mnemonic in load_s16:
            data_val = self.read_data_at_loc(binary, data_loc, 2, base_address=base_address, signed=True)
        elif mnemonic in load_u8:
            data_val = self.read_data_at_loc(binary, data_loc, 1, base_address=base_address)
        elif mnemonic in load_s8:
            data_val = self.read_data_at_loc(binary, data_loc, 1, base_address=base_address, signed=True)
        elif mnemonic in load_fp:
            is_float = True
            if tokens[4].startswith(b"d"):
                data_val = self.read_data_at_loc(binary, data_loc, 8, base_address=base_address, float_value=True)
            elif tokens[4].startswith(b"s"):
                data_val = self.read_data_at_loc(binary, data_loc, 4, base_address=base_address, float_value=True)
            else:
                raise ValueError(f"unsupported floating-point destination: {tokens[4]!r}")
        else:
            raise ValueError(f"unsupported load mnemonic: {mnemonic!r}")

        tokens[3] = b"vmov" if is_float else b"mov"
        tokens[5] = data_val
        return tokens[0:6]

    def _decode_operand(self, token: bytes) -> Operand:
        text = token.decode("ascii", errors="replace")
        normalized = text.strip(",]")
        if normalized.startswith("0x"):
            return Operand(OperandKind.ADDRESS, text, int(normalized, 0))
        if normalized.lstrip("-").isdigit():
            return Operand(OperandKind.IMMEDIATE, text, int(normalized, 10))
        if text.startswith("["):
            return Operand(OperandKind.MEMORY, text)
        if text.startswith("{") or text.endswith("}"):
            return Operand(OperandKind.REGISTER_LIST, text)
        if normalized and normalized[0] in {"r", "s", "d"} and normalized[1:].isdigit():
            return Operand(OperandKind.REGISTER, text, normalized)
        if normalized in {"sp", "lr", "pc"}:
            return Operand(OperandKind.REGISTER, text, normalized)
        return Operand(OperandKind.RAW, text)


def normalize_rasm2_output(disassembly: bytes, analysis: bytes) -> bytes:
    instructions = [
        line.strip()
        for line in disassembly.split(b"\n")
        if line.strip()
    ]
    byte_strings = re.findall(br"^bytes:\s+([0-9a-fA-F]+)$", analysis, re.MULTILINE)

    if len(instructions) != len(byte_strings):
        return disassembly

    loc = 0
    normalized = []
    for insn, byte_string in zip(instructions, byte_strings):
        size = len(byte_string) // 2
        normalized.append(
            b" ".join([
                bytes(hex(loc), "utf-8"),
                bytes(str(size), "utf-8"),
                byte_string,
                insn,
            ])
        )
        loc += size

    return b"\n".join(normalized) + b"\n"


def fix_jump_offset(jump_offset: bytes) -> int:
    if int(jump_offset, 0) > 0x7FFFFFF:
        return twos_complement(jump_offset)
    return int(jump_offset, 0)


def twos_complement(hexstr: bytes) -> int:
    bits = len(hexstr[2:]) * 4
    value = int(hexstr, 0)
    if value & (1 << (bits - 1)):
        value -= 1 << bits
    return value


def is_probable_address_literal(value: int) -> bool:
    return (
        0x08020000 <= value < 0x08040000 or
        0x20000000 <= value < 0x60000000 or
        0xE0000000 <= value < 0xE0100000
    )
