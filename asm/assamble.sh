#!/bin/bash
rm $1.*

cat "$1"    | awk -f envSize.awk  > "$1.e1"
cat "$1.e1" | awk -f envSize2.awk > "$1.e2"
cat "$1.e2" | awk -f envSize3.awk > "$1.raw"

cat "$1" | awk -f sliceCoun.awk             >> "$1.raw"
cat "$1" | awk -f getInstCout.awk           >> "$1.raw"
cat "$1" | awk -f asm.awk                   >> "$1.raw"

./tran "$1.raw" "$1.prog"