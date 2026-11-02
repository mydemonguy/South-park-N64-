#!/bin/sh
# Differential test: run loop-free leaf functions on x86-64 and ARM64 (via qemu-user)
# with identical inputs and compare. Needs: gcc, aarch64-linux-gnu-gcc, qemu-aarch64,
# python3 + rabbitizer. Usage: tools/difftest/run.sh path/to/southpark.us.z64
set -e
ROM=$1; D=$(dirname "$0"); P=$D/../..; B=${BUILD:-/tmp/sp-difftest}; mkdir -p $B/x86 $B/arm
python3 -I $D/pick_leaf.py $ROM $P/southpark.us.syms.toml $P/southpark.us.toml > $B/leaf.txt
{ echo '#include "funcs.h"'; echo '#define LEAF_FUNCS(X) \'; sed 's/.*/    X(&) \\/' $B/leaf.txt; echo; } > $B/leaf_list.h
INC="-I$RECOMP_INCLUDE -I$P/include -I$P/RecompiledFuncs -I$B"
for f in $P/RecompiledFuncs/*.c; do
  gcc -c -O2 -DNDEBUG -ffp-contract=off -w $INC $f -o $B/x86/$(basename $f .c).o
  aarch64-linux-gnu-gcc -c -O2 -DNDEBUG -ffp-contract=off -w $INC $f -o $B/arm/$(basename $f .c).o
done
gcc -O2 -DNDEBUG -w $INC $D/harness.c $B/x86/*.o -lm -o $B/h-x86
aarch64-linux-gnu-gcc -O2 -DNDEBUG -ffp-contract=off -w $INC $D/harness.c $B/arm/*.o -lm -static -o $B/h-arm
$B/h-x86 $ROM 16 clean > $B/x86.txt; qemu-aarch64 $B/h-arm $ROM 16 clean > $B/arm.txt
echo "$(wc -l < $B/x86.txt) functions tested, $(diff $B/x86.txt $B/arm.txt | grep -c '^<') differ"
