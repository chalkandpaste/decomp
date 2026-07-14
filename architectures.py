from dataclasses import dataclass


@dataclass(frozen=True)
class ArchitectureSpec:
    id: str
    display_name: str
    status: str
    rasm2_arch: str | None
    rasm2_bits: int | None
    notes: tuple[str, ...]
    work_needed: tuple[str, ...]


ARCHITECTURES = {
    "arm-thumb": ArchitectureSpec(
        id="arm-thumb",
        display_name="ARM Thumb / Cortex-M",
        status="supported",
        rasm2_arch="arm.gnu",
        rasm2_bits=16,
        notes=(
            "Current implementation target.",
            "Assumes GCC-shaped Cortex-M firmware and ARM AAPCS register conventions.",
        ),
        work_needed=(
            "Move ARM-specific instruction tables behind an architecture interface.",
            "Add vector-table parsing and Cortex-M peripheral symbol packs.",
        ),
    ),
    "m6800-6303": ArchitectureSpec(
        id="m6800-6303",
        display_name="Hitachi 63B03 / Motorola 6800 family",
        status="prospective",
        rasm2_arch="m680x",
        rasm2_bits=8,
        notes=(
            "radare2 exposes an m680x backend, but the exact 6303 dialect needs validation.",
            "Likely useful for older synth firmware with small address spaces and hand-written assembly.",
        ),
        work_needed=(
            "Confirm opcode coverage for HD6303/compatible 6800-family binaries.",
            "Define reset/vector parsing and bank/ROM mapping conventions.",
            "Implement 8-bit accumulator/index-register data-flow rules.",
        ),
    ),
    "m6809e": ArchitectureSpec(
        id="m6809e",
        display_name="Motorola 68B09E / 6809 family",
        status="prospective",
        rasm2_arch="m680x",
        rasm2_bits=8,
        notes=(
            "radare2 m680x is the most promising local disassembly starting point.",
            "6809 calling conventions are often project/toolchain-specific.",
        ),
        work_needed=(
            "Validate direct/indexed/extended addressing modes against known firmware.",
            "Model A/B/D, X/Y, U/S, DP, and condition-code effects.",
            "Add stack-frame and interrupt/vector heuristics.",
        ),
    ),
    "sh3-dsp": ArchitectureSpec(
        id="sh3-dsp",
        display_name="Renesas SH7727 / SH-3-DSP",
        status="prospective",
        rasm2_arch="sh",
        rasm2_bits=32,
        notes=(
            "radare2 exposes sh and sh.cs backends locally, but labels the main backend as SH-4.",
            "SH-3-DSP needs explicit validation for DSP instructions, delay slots, and endian mode.",
        ),
        work_needed=(
            "Pick a disassembler backend that covers SH-3-DSP accurately.",
            "Represent delay slots in block construction.",
            "Define ABI/calling-convention profiles for target firmware.",
        ),
    ),
    "xcore-xs1": ArchitectureSpec(
        id="xcore-xs1",
        display_name="XMOS XS1-family xCORE",
        status="prospective",
        rasm2_arch="xcore",
        rasm2_bits=32,
        notes=(
            "radare2 exposes an xcore backend through Capstone locally.",
            "xCORE firmware needs a different concurrency/channel-aware analysis model.",
        ),
        work_needed=(
            "Validate XS1 opcode coverage and firmware container format.",
            "Model threads, channel endpoints, and resource-oriented side effects.",
            "Add xCORE-specific ABI and startup discovery.",
        ),
    ),
}


def get_architecture(arch_id):
    try:
        return ARCHITECTURES[arch_id]
    except KeyError as exc:
        known = ", ".join(sorted(ARCHITECTURES))
        raise ValueError(f"unknown architecture {arch_id!r}; known: {known}") from exc


def list_architectures():
    return [ARCHITECTURES[key] for key in sorted(ARCHITECTURES)]
