BEGIN{
  varWriteI_Count = 0;
  varWriteU_Count = 0;
  varWriteD_Count = 0;
  varReadI_Count = 0;
  varReadU_Count = 0;
  varReadD_Count = 0;
  memAlloc_Count = 0;
  memDeAlloc_Count = 0;
  memWrite_Count = 0;
  memRead_Count = 0;
}

$1=="varWriteI"                     { if( !( $2 in varWriteI_checklist) ){ 
                                        varWriteI_list[varWriteI_Count] = $2;
                                        varWriteI_Count++;
                                        varWriteI_checklist[$2]=1;
                                    }}
$1=="varReadI"                      { if( !( $2 in varReadI_checklist) ){ 
                                        varReadI_list[varReadI_Count] = $2;
                                        varReadI_Count++;
                                        varReadI_checklist[$2]=1;
                                    }}

$1=="varWriteD"                     { if( !( $2 in varWriteD_checklist) ){ 
                                        varWriteD_list[varWriteD_Count] = $2;
                                        varWriteD_Count++;
                                        varWriteD_checklist[$2]=1;
                                    }}
$1=="varReadD"                      { if( !( $2 in varReadD_checklist) ){ 
                                        varReadD_list[varReadD_Count] = $2;
                                        varReadD_Count++;
                                        varReadD_checklist[$2]=1;
                                    }}

$1=="varWriteU"                     { if( !( $2 in varWriteU_checklist) ){ 
                                        varWriteU_list[varWriteU_Count] = $2;
                                        varWriteU_Count++;
                                        varWriteU_checklist[$2]=1;
                                    }}

$1=="varReadU"                      { if( !( $2 in varReadU_checklist) ){ 
                                        varReadU_list[varReadU_Count] = $2;
                                        varReadU_Count++;
                                        varReadU_checklist[$2]=1;
                                    }}



$1=="memAlloc"                     { if( !( $2 in memAlloc_checklist) ){ 
                                        memAlloc_list[memAlloc_Count] = $2;
                                        memAlloc_Count++;
                                        memAlloc_checklist[$2]=1;
                                    }}

$1=="memDealloc"                    { if( !( $2 in memDeAlloc_checklist) ){ 
                                        memDeAlloc_list[memDeAlloc_Count] = $2;
                                        memDeAlloc_Count++;
                                        memDeAlloc_checklist[$2]=1;
                                    }}

$1=="memWrite"                      { if( !( $2 in memWrite_checklist) ){ 
                                        memWrite_list[memWrite_Count] = $2;
                                        memWrite_Count++;
                                        memWrite_checklist[$2]=1;
                                    }}
$1=="memRead"                       { if( !( $2 in memRead_checklist) ){ 
                                        memRead_list[memRead_Count] = $2;
                                        memRead_Count++;
                                        memRead_checklist[$2]=1;
                                    }}


END {
  
  print("len " varWriteI_Count " VarWriteI")
  for( i = 0 ; i<varWriteI_Count ; i++){
    print("varWriteI " varWriteI_list[i])
  }
  print("len " varWriteU_Count  " VarWriteU")
  for( i = 0 ; i<varWriteU_Count ; i++){
    print("varWriteU " varWriteU_list[i])
  }
  print("len " varWriteD_Count  " VarWriteD")
  for( i = 0 ; i<varWriteD_Count ; i++){
    print("varWriteD " varWriteD_list[i])
  }
  print("len " varReadI_Count  " VarReadI")
  for( i = 0 ; i<varReadI_Count ; i++){
    print("varReadI " varReadI_list[i])
  }
  print("len " varReadU_Count  " VarReadU")
  for( i = 0 ; i<varReadU_Count ; i++){
    print("varReadU " varReadU_list[i])
  }
  print("len " varReadD_Count  " VarReadD")
  for( i = 0 ; i<varReadD_Count ; i++){
    print("varReadD " varReadD_list[i])
  }
  print("len " memAlloc_Count  " MemAlloc")
  for( i = 0 ; i<memAlloc_Count ; i++){
    print("MemAlloc " memAlloc_list[i])
  }
  print("len " memDeAlloc_Count  " MemDealloc")
  for( i = 0 ; i<memDeAlloc_Count ; i++){
    print("MemDeAlloc " memDeAlloc_list[i])
  }  
  print("len " memWrite_Count  " MemWrite")
  for( i = 0 ; i<memWrite_Count ; i++){
    print("MemWrite " memWrite_list[i])
  }
  print("len " memRead_Count  " MemRead")
  for( i = 0 ; i<memRead_Count ; i++){
    print("MemRead " memRead_list[i])
  }  
}