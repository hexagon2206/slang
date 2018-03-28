#!/bin/bash
cat "$1" | awk -f sliceCoun.awk    > "$2"
cat "$1" | awk -f getInstCout.awk >> "$2"
cat "$1" | awk -f asm.awk         >> "$2"

./tran "$2" "$3"