BEGIN { slice=0; }
$1=="newSlice" { slice++; }
END { printf("u64_%u\n",slice); }