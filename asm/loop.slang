newSlice                                // start ne Computation Slice
OP_sampleVektor 0 1 10 10 0 1
OP_sampleVektor 0 2 11 11 0 2
OP_sampleVektor 0 3 12 12 0 3
OP_sampleVektor 0 4 13 13 0 4
OP_sampleVektor 0 5 14 14 0 5
OP_sampleVektor 0 6 15 15 0 6
OP_sampleVektor 0 7 16 16 0 7
OP_sampleVektor 0 8 17 17 0 8
OP_sampleVektor 0 9 18 18 0 9

newSlice

OP_mulConstVar 1 1 19      // scale al waves individuali
OP_mulConstVar 2 2 20
OP_mulConstVar 3 3 21
OP_mulConstVar 4 4 22
OP_mulConstVar 5 5 23
OP_mulConstVar 6 6 24
OP_mulConstVar 7 7 25
OP_mulConstVar 8 8 26
OP_mulConstVar 9 9 27

newSlice                  // Summ up all scaled waves in 4 slices 
OP_addVektors 1 1 9
OP_addVektors 2 2 8
OP_addVektors 3 3 7
OP_addVektors 4 4 6

newSlice
OP_addVektors 1 1 4
OP_addVektors 2 2 3

newSlice
OP_addVektors 1 1 2

newSlice
OP_addVektors 1 1 5

newSlice
OP_mulConstVar 1 1 28      // slace final wave Skalieren 

