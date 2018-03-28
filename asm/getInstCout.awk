BEGIN { slice = 0; instCount=0; }

$1 ~ /^ *OP_/ {  instCount++; } 

$1=="newSlice" {
  if(slice != 0) {
    printf("u64_%u\n",instCount);
  }
  instCount=0;
  slice++;
}
END {
  if(slice != 0) {
    printf("u64_%u\n",instCount);
  }
  instCount=0;
  slice++;
}
