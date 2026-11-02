"""Build an N64Recomp symbol file for South Park (USA) from spimdisasm function info.

Usage: python3 -I gen_syms.py <rom.z64> <finfo_main.csv> <finfo_block2.csv> <out.toml>

Fixes applied on top of spimdisasm's function list:
  * Call targets that land 4 bytes into a function become function starts. The 4-byte
    piece before them is an extra entry point that falls through into the function.
  * Functions that fall through (no return/jump at the end) or branch past their end are
    extended to cover the code they run into. N64Recomp allows overlapping functions, so
    every entry point keeps working.
  * 4-byte "functions" that are really constants embedded in the code are dropped.
"""
import csv
import re
import struct
import sys

import rabbitizer

MAIN = dict(name="main", rom=0x1128, vram=0x00200528, size=0xA6DB0)
BLOCK2 = dict(name="block2", rom=0xC4000, vram=0x00400000, size=0x14AA0)
BOOT = dict(name="boot", rom=0x1000, vram=0x80000400, size=0x128)
BOOT_FUNCS = [("entrypoint_stub", 0x80000400, 0xB0), ("boot_map_tlb", 0x800004B0, 0x78)]

KNOWN_NAMES = {
    0x0022BCE8: "game_boot",   # copies 1MB from ROM, clears BSS, starts the game
    0x00291198: "map_tlb",     # writes one TLB entry (osMapTLB-like)
}


class Section:
    def __init__(self, rom, sec):
        self.sec = sec
        self.rom = rom

    def word(self, vram):
        off = vram - self.sec["vram"] + self.sec["rom"]
        return struct.unpack(">I", self.rom[off:off + 4])[0]

    def insn(self, vram):
        return rabbitizer.Instruction(self.word(vram), vram)

    def contains(self, vram):
        return self.sec["vram"] <= vram < self.sec["vram"] + self.sec["size"]


def load_csv(path):
    rows = list(csv.DictReader(open(path)))
    funcs = {int(r["address"], 16): int(r["length"], 16) for r in rows}
    refs = set()
    for r in rows:
        text = r["functions called by this function"] + r["referenced functions"]
        refs.update(int(n, 16) for n in re.findall(r"func_([0-9A-F]{8})", text))
    return funcs, refs


def split_mid_starts(funcs, targets):
    count = 0
    for t in sorted(targets):
        if t in funcs or (t - 4) not in funcs:
            continue
        size = funcs[t - 4]
        funcs[t - 4] = 4
        funcs[t] = size - 4
        count += 1
    return count


def is_embedded_constant(s, vram):
    ins = s.insn(vram)
    if not ins.isValid():
        return True
    w = s.word(vram)
    if w == 0:
        return False
    # A real instruction would not write to $zero.
    for getter, check in (("modifiesRd", "rd"), ("modifiesRt", "rt")):
        if getattr(ins, getter)() and getattr(ins, check) == rabbitizer.RegGprO32.zero:
            return True
    return False


def ends_cleanly(s, start, size):
    """True if control can't fall off the end of [start, start+size)."""
    if size < 8:
        return False
    ins = s.insn(start + size - 8)
    if ins.isJump() and not ins.doesLink():          # j / jr
        return True
    if ins.isUnconditionalBranch():                 # b
        return True
    last = s.insn(start + size - 4)
    if last.uniqueId == rabbitizer.InstrId.cpu_break:
        return True
    return False


def branch_reach(s, start, size):
    """Highest address reached by a branch or local j inside the function."""
    reach = start + size
    for vram in range(start, start + size, 4):
        ins = s.insn(vram)
        if ins.isBranch():
            reach = max(reach, ins.getBranchVramGeneric() + 4)
    return reach


def extend(s, funcs):
    addrs = sorted(funcs)
    end_of_sec = s.sec["vram"] + s.sec["size"]
    changed = 0
    for a in addrs:
        size = funcs[a]
        while True:
            new_size = size
            if not ends_cleanly(s, a, new_size):
                nxt = min((b for b in addrs if b >= a + new_size), default=None)
                if nxt is not None and nxt == a + new_size:
                    new_size += funcs[nxt]
            reach = branch_reach(s, a, new_size)
            while reach > a + new_size:
                nxt = min((b for b in addrs if b >= a + new_size), default=None)
                if nxt is None or nxt != a + new_size:
                    break
                new_size += funcs[nxt]
            new_size = min(new_size, end_of_sec - a)
            if new_size == size:
                break
            size = new_size
        if size != funcs[a]:
            funcs[a] = size
            changed += 1
    return changed


def build(s, funcs):
    # Drop constants first so they don't get merged into neighbors.
    dropped = [a for a, l in funcs.items() if l == 4 and is_embedded_constant(s, a)]
    for a in dropped:
        del funcs[a]
    changed = extend(s, funcs)
    return dropped, changed


def emit_section(out, sec, funcs):
    out += ["[[section]]", f'name = "{sec["name"]}"', f'rom = 0x{sec["rom"]:08X}',
            f'vram = 0x{sec["vram"]:08X}', f'size = 0x{sec["size"]:X}', "functions = ["]
    for name, vram, size in funcs:
        out.append(f'    {{ name = "{name}", vram = 0x{vram:08X}, size = 0x{size:X} }},')
    out += ["]", ""]


def main():
    rom = open(sys.argv[1], "rb").read()
    main_funcs, main_refs = load_csv(sys.argv[2])
    b2_funcs, b2_refs = load_csv(sys.argv[3])
    targets = main_refs | b2_refs

    out = ["# N64Recomp symbol file: South Park (USA), sha1 42d7350d1f9040c5546f481c4d650b99a23aadbc", ""]
    emit_section(out, BOOT, BOOT_FUNCS)
    for funcs, sec in ((main_funcs, MAIN), (b2_funcs, BLOCK2)):
        s = Section(rom, sec)
        n_split = split_mid_starts(funcs, targets)
        dropped, changed = build(s, funcs)
        named = [(KNOWN_NAMES.get(a, f"func_{a:08X}"), a, funcs[a]) for a in sorted(funcs)]
        emit_section(out, sec, named)
        print(f'{sec["name"]}: {len(funcs)} functions, {n_split} mid-function entry points split, '
              f'{changed} extended, {len(dropped)} embedded constants dropped '
              f'({", ".join(f"{a:08X}" for a in dropped)})')
    open(sys.argv[4], "w").write("\n".join(out))


if __name__ == "__main__":
    main()
