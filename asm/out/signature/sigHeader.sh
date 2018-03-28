#!/bin/bash
cat "$1" | awk -f envSize.awk | awk -f envSize2.awk | awk -f envSize3.awk >> "$2"