newSlice
OP_setupCall 0 0 // setup call 0 with programm one (the adder)

newSlice // bind the values for the Call
OP_bindValue 0 P_Bind_MEMYTYPE_M 0 P_Bind_Both 0 P_Bind_Read
OP_bindValue 0 P_Bind_MEMYTYPE_M 1 P_Bind_Both 0 P_Bind_Read
OP_bindValue 0 P_Bind_MEMYTYPE_M 2 P_Bind_Both 1 P_Bind_Read

newSlice
OP_makeCall 0

