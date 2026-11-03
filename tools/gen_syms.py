"""Build an N64Recomp symbol file for South Park (USA) from spimdisasm function info.

Usage: python3 -I gen_syms.py <rom.z64> <finfo_main.csv> <finfo_block2.csv> <out.toml> [names.json]

names.json (tools/libultra_names.json) maps vram -> [name, evidence] for identified
functions; everything else is named func_XXXXXXXX.

Fixes applied on top of spimdisasm's function list:
  * Call targets that land 4 bytes into a function become function starts. The 4-byte
    piece before them is an extra entry point that falls through into the function.
  * Functions that fall through (no return/jump at the end) or branch past their end are
    extended to cover the code they run into. N64Recomp allows overlapping functions, so
    every entry point keeps working.
  * 4-byte "functions" that are really constants embedded in the code are dropped.
  * Code addresses the game builds as pointers (lui/addiu pairs in code, words in the
    data sections) become function starts when they look like one (a stack-frame
    setup, or right after an unconditional jump/return). Thread entries and callbacks
    are only reached through LOOKUP_FUNC, so every one of them must be a function.
    Addresses built with lui/addiu (not ori, which builds constants) are also accepted
    when they sit in the delay slot of a jump (hand-written code that shares one
    instruction between a `jr $ra` and the next routine, e.g. 0x0027D7F0) or when a
    stack frame is set up within their first few instructions (e.g. 0x00288970, which
    follows a stray word). A shared delay slot stays in the function before it too.
"""
import csv
import re
import struct
import sys

import json

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


CODE_RANGES = [(0x00200528, 0x002A72D8), (0x00400000, 0x00414AA0)]
DATA_ROM_RANGES = [(0xA7ED8, 0xC2C00), (0xD8AA0, 0xDAF10)]   # main data, block 2 data


def in_code(v):
    return any(a <= v < b for a, b in CODE_RANGES)


def pointer_targets(rom, sections):
    """Code addresses referenced as data. Returns (built in code, stored in data, built
    with addiu): data words include jump-table entries (case labels), so they need
    stricter checks; addiu-built ones are real addresses (%lo), not ori constants."""
    found = set()
    data_found = set()
    addiu_found = set()
    for s in sections:
        regs = {}
        for vram in range(s.sec["vram"], s.sec["vram"] + s.sec["size"], 4):
            ins = s.insn(vram)
            n = ins.uniqueId.name
            if n == "cpu_lui":
                regs[ins.rt.name] = (s.word(vram) & 0xFFFF) << 16
            elif n in ("cpu_addiu", "cpu_ori") and ins.rs.name in regs:
                imm = s.word(vram) & 0xFFFF
                if n == "cpu_addiu" and imm & 0x8000:
                    imm -= 0x10000
                t = (regs[ins.rs.name] + imm) & 0xFFFFFFFF
                if in_code(t) and t % 4 == 0:
                    found.add(t)
                    if n == "cpu_addiu":
                        addiu_found.add(t)
            if ins.isJump() or ins.isBranch():
                regs = {}
    for a, b in DATA_ROM_RANGES:
        for o in range(a, b, 4):
            w = struct.unpack_from(">I", rom, o)[0]
            if in_code(w) and w % 4 == 0:
                data_found.add(w)
    return found, data_found, addiu_found


def is_shared_delay_slot(s, v):
    """v is the delay slot of an unconditional jump/return (and so may be entered)."""
    if v - 4 < s.sec["vram"]:
        return False
    prev = s.insn(v - 4)
    return (prev.isJump() and not prev.doesLink()) or prev.isUnconditionalBranch()


def sets_up_frame_soon(s, v, window=3):
    """addiu sp, sp, -N within the first `window` instructions, before any control flow."""
    for i in range(window):
        a = v + 4 * i
        if not s.contains(a):
            return False
        if (s.word(a) & 0xFFFF8000) == 0x27BD8000:
            return True
        ins = s.insn(a)
        if ins.isJump() or ins.isBranch():
            return False
    return False


def looks_like_start(s, v, strict=False, addiu_built=False):
    w = s.word(v)
    if (w & 0xFFFF8000) == 0x27BD8000:          # addiu sp, sp, -N
        return True
    if strict:
        return False
    if v - 8 >= s.sec["vram"]:
        prev = s.insn(v - 8)
        if (prev.isJump() and not prev.doesLink()) or prev.isUnconditionalBranch():
            return True
    if addiu_built and (is_shared_delay_slot(s, v) or sets_up_frame_soon(s, v)):
        return True
    return False


def add_pointer_starts(s, funcs, targets):
    """Split functions at pointer targets that look like function starts."""
    code_ptrs, data_ptrs, addiu_ptrs = targets
    added = 0
    for t in sorted(code_ptrs | data_ptrs):
        if not s.contains(t) or t in funcs:
            continue
        if not looks_like_start(s, t, strict=t not in code_ptrs, addiu_built=t in addiu_ptrs):
            continue
        host = max((a for a in funcs if a < t), default=None)
        if host is None or host + funcs[host] <= t:
            continue
        end = host + funcs[host]
        # A shared delay slot also belongs to the jump before it.
        funcs[host] = t - host + (4 if is_shared_delay_slot(s, t) else 0)
        funcs[t] = end - t
        added += 1
    return added


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


def after_return_starts(s, funcs):
    """Code right after a `jr $ra` and its delay slot that nothing in its function branches
    to can only be entered from outside: small functions that live in a callback table
    (e.g. 0x004050C0 and 0x004050CC after func_00405040's return, or the ~20 option
    getters/setters packed into func_00405788) that spimdisasm merged into the function
    before them. Make each one a function start (overlapping the rest of its host), unless
    its body branches back to before its start (then it is a loop of the host)."""
    added = 0
    for a, size in sorted(funcs.items()):
        end = a + size
        targets = set()
        for v in range(a, end, 4):
            ins = s.insn(v)
            if ins.isBranch() or ins.isJumpWithAddress():
                targets.add(ins.getBranchVramGeneric())
        for v in range(a + 8, end, 4):
            if v in funcs or v in targets or s.word(v) == 0 or not s.insn(v - 8).isJrRa():
                continue
            loops_back = False
            for w in range(v, end, 4):
                ins = s.insn(w)
                if (ins.isBranch() or ins.isJumpWithAddress()) and ins.getBranchVramGeneric() < v:
                    loops_back = True
                    break
                if ins.isJrRa():
                    break
            if not loops_back:
                funcs[v] = end - v
                added += 1
    return added


def build(s, funcs):
    # Drop constants first so they don't get merged into neighbors.
    dropped = [a for a, l in funcs.items() if l == 4 and is_embedded_constant(s, a)]
    for a in dropped:
        del funcs[a]
    changed = extend(s, funcs)
    after_return = after_return_starts(s, funcs)
    if after_return:
        print(f'{s.sec["name"]}: {after_return} functions split after a return')
    return dropped, changed


def emit_section(out, sec, funcs):
    out += ["[[section]]", f'name = "{sec["name"]}"', f'rom = 0x{sec["rom"]:08X}',
            f'vram = 0x{sec["vram"]:08X}', f'size = 0x{sec["size"]:X}', "functions = ["]
    for name, vram, size in funcs:
        out.append(f'    {{ name = "{name}", vram = 0x{vram:08X}, size = 0x{size:X} }},')
    out += ["]", ""]


def main():
    if len(sys.argv) > 5:
        for k, v in json.load(open(sys.argv[5]))["names"].items():
            KNOWN_NAMES[int(k, 16)] = v[0]
    rom = open(sys.argv[1], "rb").read()
    main_funcs, main_refs = load_csv(sys.argv[2])
    b2_funcs, b2_refs = load_csv(sys.argv[3])
    targets = main_refs | b2_refs

    sections = [Section(rom, MAIN), Section(rom, BLOCK2)]
    ptrs = pointer_targets(rom, sections)
    for funcs, sec in ((main_funcs, MAIN), (b2_funcs, BLOCK2)):
        n_ptr = add_pointer_starts(Section(rom, sec), funcs, ptrs)
        print(f'{sec["name"]}: {n_ptr} functions split at pointer targets')

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
