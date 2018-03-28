

$1=="OP_direktWriteInt"             { print("varWriteI " $2); }

$1=="OP_direktWriteUInt"            { print("varWriteU " $2); }

$1=="OP_direktWriteDtype"           { print("varWriteD " $2); }

$1=="OP_vektorMemoryAllocDirect"    { print("memAlloc " $2);  }

$1=="OP_vektorMemoryAllocVariable"  { print("memAlloc " $2);
                                      print("varReadU " $3);  }

$1=="OP_vektorMemoryAllocDirect"    { print("memAlloc " $2);  }

$1=="OP_MemoryDealloc"              { print("memDealloc " $2); }

$1=="OP_generateSinLookup"          { print("memWrite " $2);  }

$1=="OP_sampleVektor"               { print("memRead " $2);
                                      print("memWrite " $3);
                                      print("varReadU " $4);
                                      print("varWriteU " $5);
                                      print("varReadU " $6);
                                      print("varReadU " $7);  }

$1=="OP_addConstDirect"             { print("memWrite " $2);
                                      print("memRead "  $3); }

$1=="OP_addConstVar"                { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("varReadU " $4); }

$1=="OP_addVektors"                 { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("memRead " $4); }

$1=="OP_subConstDirekt"             { print("memWrite " $2);
                                      print("memRead "  $3); }

$1=="OP_subConstVar"                { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("varReadU " $4); }

$1=="OP_subVektors"                 { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("memRead " $4); }

$1=="OP_mulConst"                   { print("memWrite " $2);
                                      print("memRead "  $3); }

$1=="OP_mulConstVar"                { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("varReadU " $4); }

$1=="OP_mulVektors"                 { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("memRead " $4); }

$1=="OP_divConst"                   { print("memWrite " $2);
                                      print("memRead "  $3); }

$1=="OP_divConstVar"                { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("varReadU " $4); }

$1=="OP_divVektors"                 { print("memWrite " $2);
                                      print("memRead "  $3);
                                      print("memRead " $4); }
