"""Pick recompiled functions that call nothing and contain no loops."""
import re, struct, sys, rabbitizer
rom = open(sys.argv[1], 'rb').read()
syms = open(sys.argv[2]).read()
stubs = set(re.findall(r'"(func_\w+|\w+)"', open(sys.argv[3]).read().split('[[patches.instruction]]')[0].split('stubs')[1]))
out = []
for name, rbase, vbase, body in re.findall(r'name = "(\w+)"\nrom = (0x\w+)\nvram = (0x\w+)\nsize = 0x\w+\nfunctions = \[(.*?)\n\]', syms, re.S):
    if name == 'boot': continue
    rbase, vbase = int(rbase, 16), int(vbase, 16)
    for fn, v, sz in re.findall(r'name = "(\w+)", vram = (0x\w+), size = (0x\w+)', body):
        v, sz = int(v, 16), int(sz, 16)
        if fn in stubs or sz < 16: continue
        ok = True
        for a in range(v, v + sz, 4):
            o = a - vbase + rbase
            i = rabbitizer.Instruction(struct.unpack('>I', rom[o:o+4])[0], a)
            if i.doesLink() or (i.isJump() and not i.isJrRa()):   # calls, jump tables, tail calls
                ok = False; break
            if i.isBranch() and i.getBranchVramGeneric() <= a:     # loops
                ok = False; break
            if i.isUnconditionalBranch() and i.getBranchVramGeneric() <= a:
                ok = False; break
            if i.uniqueId.name.startswith(('cpu_mfc0', 'cpu_mtc0', 'cpu_cache', 'cpu_break', 'cpu_syscall')):
                ok = False; break
        if ok: out.append(fn)
print('\n'.join(out))
