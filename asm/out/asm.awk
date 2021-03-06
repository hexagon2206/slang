BEGIN {
  instLen=10;

  OP_direktWriteInt     = 1;
  OP_direktWriteUInt    = 2;
  OP_direktWriteDtype   = 3;
  OP_vektorMemoryAllocDirect   = 4;
  OP_vektorMemoryAllocVariable = 5;
  OP_MemoryDealloc      = 6;
  OP_generateSinLookup  = 7;
  OP_sampleVektorDirect = 8;
  OP_sampleVektor       = 9;
  OP_addConstDirect     = 10;
  OP_addConstVar        = 11;
  OP_addVektors         = 12;
  OP_subConstDirekt     = 13;
  OP_subConstVar        = 14;
  OP_subVektors         = 15;
  OP_mulConst           = 16;
  OP_mulConstVar        = 17;
  OP_mulVektors         = 18;
  OP_divConst           = 19;
  OP_divConstVar        = 20;
  OP_divVektors         = 21;
}

$1=="OP_direktWriteInt" {
  printf("u64_%u u64_%s i64_%s",OP_direktWriteInt , $2 , $3);
  for(i = 3 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");  
}
$1=="OP_direktWriteUInt" {
  printf("u64_%u u64_%s u64_%s",OP_direktWriteUInt , $2 , $3);
  for(i = 3 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_direktWriteDtype" {
  printf("u64_%u u64_%s d64_%s",OP_direktWriteDtype , $2 , $3);
  for(i = 3 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}

$1=="OP_vektorMemoryAllocDirect" {
  printf("u64_%u u64_%s u64_%s",OP_vektorMemoryAllocDirect , $2 , $3);
  for(i = 3 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_vektorMemoryAllocVariable" {
  printf("u64_%u u64_%s u64_%s",OP_vektorMemoryAllocVariable , $2 , $3);
  for(i = 3 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_MemoryDealloc" {
  printf("u64_%u u64_%s",OP_MemoryDealloc,$2);
  for(i = 2 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_generateSinLookup" {
  printf("u64_%u u64_%s",OP_generateSinLookup,$2);
  for(i = 2 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_sampleVektorDirect" {
  printf("u64_%u u64_%s u64_%s u64_%s u64_%s d64_%s d64_%s",OP_sampleVektorDirect, $2 , $3, $4 , $5, $6 , $7);
  for(i = 7 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_sampleVektor" {
  printf("u64_%u u64_%s u64_%s u64_%s u64_%s u64_%s u64_%s",OP_sampleVektor, $2 , $3, $4 , $5, $6 , $7);
  for(i = 7 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}

$1=="OP_addConstDirect" {
  printf("u64_%u u64_%s u64_%s d64_%s",OP_addConstDirect, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_addConstVar" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_addConstVar, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_addVektors" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_addVektors, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_subConstDirekt" {
  printf("u64_%u u64_%s u64_%s d64_%s",OP_subConstDirekt, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_subConstVar" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_subConstVar, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_subVektors" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_subVektors, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_mulConst" {
  printf("u64_%u u64_%s u64_%s d64_%s",OP_mulConst, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_mulConstVar" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_mulConstVar, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_mulVektors" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_mulVektors, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_divConst" {
  printf("u64_%u u64_%s u64_%s d64_%s",OP_divConst, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_divConstVar" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_divConstVar, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}
$1=="OP_divVektors" {
  printf("u64_%u u64_%s u64_%s u64_%s",OP_divVektors, $2 , $3, $4 );
  for(i = 4 ; i < instLen ; i++) {
    printf(" FILL");
  }
  printf("\n");
}