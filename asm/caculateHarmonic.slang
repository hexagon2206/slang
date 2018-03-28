// generate the sin waves
newSlice
OP_sampleVektor 0 1   100 100   0 200
OP_sampleVektor 0 2   101 101   0 201
OP_sampleVektor 0 3   102 102   0 202
OP_sampleVektor 0 4   103 103   0 203
OP_sampleVektor 0 5   104 104   0 204
OP_sampleVektor 0 6   105 105   0 205
OP_sampleVektor 0 7   106 106   0 206
OP_sampleVektor 0 8   107 107   0 207
OP_sampleVektor 0 9   108 108   0 208
OP_sampleVektor 0 10  109 109   0 209
OP_sampleVektor 0 11  110 110   0 210


// apply the scaling
newSlice
OP_mulConstVar  1  1  300
OP_mulConstVar  2  2  301
OP_mulConstVar  3  3  302
OP_mulConstVar  4  4  303
OP_mulConstVar  5  5  304
OP_mulConstVar  6  6  305
OP_mulConstVar  7  7  306
OP_mulConstVar  8  8  307
OP_mulConstVar  9  9  308
OP_mulConstVar 10 10  309
OP_mulConstVar 11 11  310

newSlice
OP_addVektors 1 1 11
OP_addVektors 2 2 10
OP_addVektors 3 3 9
OP_addVektors 4 4 8
OP_addVektors 5 5 7

newSlice
OP_addVektors 1 1 5
OP_addVektors 2 2 4
OP_addVektors 3 3 6

newSlice
OP_addVektors 1 1 3

newSlice
OP_addVektors 1 1 2