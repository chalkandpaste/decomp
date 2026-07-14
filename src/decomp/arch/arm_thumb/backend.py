from __future__ import annotations

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
