import sys
def isnan32(x): return (x & 0x7f800000) == 0x7f800000 and (x & 0x7fffff) != 0
def isnan64(x): return (x & 0x7ff0000000000000) == 0x7ff0000000000000 and (x & 0xfffffffffffff) != 0
a = open(sys.argv[1]).read().split(); b = open(sys.argv[2]).read().split()
if len(a) != len(b): print(sys.argv[3], 'LAYOUT'); sys.exit()
kinds = set()
for x, y in zip(a, b):
    if x == y: continue
    try:
        vx = int(x.split('=')[1], 16); vy = int(y.split('=')[1], 16)
    except Exception:
        kinds.add('OTHER ' + x + ' ' + y); continue
    ok = True
    for sh in (0, 32):
        hx, hy = (vx >> sh) & 0xffffffff, (vy >> sh) & 0xffffffff
        if hx != hy and not (isnan32(hx) and isnan32(hy)): ok = False
    if ok or (isnan64(vx) and isnan64(vy)): kinds.add('nan'); continue
    kinds.add('OTHER ' + x + ' ' + y)
print(sys.argv[3], sorted(kinds)[:2])
