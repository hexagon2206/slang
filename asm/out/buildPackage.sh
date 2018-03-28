#!/bin/bash
rm -r out
mkdir out
cp *.sh out/
cp *.awk out/
cp -r signature out/signature
chmod +x out/*