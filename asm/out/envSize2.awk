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


$1=="varWriteI"                     { if( !( $2 in varWriteI_list) ){
                                        varWriteI_Count++; 
                                        varWriteI_list[varWriteI_Count] = $2;
                                    }}
$1=="varReadI"                      { if( !( $2 in varReadI_list) ){
                                        varReadI_Cont++; 
                                        varReadI_list[varReadI_Count] = $2;
                                    }}

$1=="varWriteD"                     { if( !( $2 in varWriteD_list) ){
                                        varWriteD_Count++; 
                                        varWriteD_list[varWriteD_Count] = $2;
                                    }}
$1=="varReadD"                      { if( !( $2 in varReadD_list) ){
                                        varReadD_Cont++; 
                                        varReadD_list[varReadD_Count] = $2;
                                    }}

$1=="varWriteU"                     { if( !( $2 in varWriteU_list) ){
                                        varWriteU_Count++; 
                                        varWriteU_list[varWriteU_Count] = $2;
                                    }}

$1=="varReadU"                      { if( !( $2 in varReadU_list) ){
                                        varReadU_Count++; 
                                        varReadU_list[varReadU_Count] = $2;
                                    }}



$1=="memAlloc"                     { if( !( $2 in memAlloc_list) ){
                                        memAlloc_Count++; 
                                        memAlloc_list[memAlloc_Count] = $2;
                                    }}

$1=="memDealloc"                    { if( !( $2 in memDeAlloc_list) ){
                                        memDeAlloc_Count++; 
                                        memDeAlloc_list[memDeAlloc_Count] = $2;
                                    }}

$1=="memWrite"                      { if( !( $2 in memWrite_list) ){
                                        memWrite_Count++; 
                                        memWrite_list[memWrite_Count] = $2;
                                    }}
$1=="memRead"                       { if( !( $2 in memRead_list) ){
                                        memRead_Count++; 
                                        memRead_list[memRead_Count] = $2;
                                    }}


END {
  
  print("len " varWriteI_Count " VarWriteI")
  for( i = 1 ; i< varWriteI_Count+1 ; i++){
    print("varWriteI " varWriteI_list[i])
  }
  print("len " varWriteU_Count  " VarWriteU")
  for( i = 1 ; i< varWriteU_Count+1 ; i++){
    print("varWriteU " varWriteU_list[i])
  }
  print("len " varWriteD_Count  " VarWriteD")
  for( i = 1 ; i< varWriteD_Count+1 ; i++){
    print("varWriteD " varWriteD_list[i])
  }
  print("len " varReadI_Count  " VarReadI")
  for( i = 1 ; i< varReadI_Count+1 ; i++){
    print("varReadI " varReadI_list[i])
  }
  print("len " varReadU_Count  " VarReadU")
  for( i = 1 ; i< varReadU_Count+1 ; i++){
    print("varReadU " varReadU_list[i])
  }
  print("len " varReadD_Count  " VarReadD")
  for( i = 1 ; i< varReadD_Count+1 ; i++){
    print("varReadD " varReadD_list[i])
  }
  print("len " memAlloc_Count  " memAlloc")
  for( i = 1 ; i< memAlloc_Count+1 ; i++){
    print("MemAlloc " memAlloc_list[i])
  }
  print("len " memDeAlloc_Count  " memDealloc")
  for( i = 1 ; i< memDeAlloc_Count+1 ; i++){
    print("MemDeAlloc " memDeAlloc_list[i])
  }  
  print("len " memWrite_Count  " memAlloc")
  for( i = 1 ; i< memWrite_Count+1 ; i++){
    print("MemAlloc " memWrite_list[i])
  }
  print("len " memRead_Count  " memDealloc")
  for( i = 1 ; i< memRead_Count+1 ; i++){
    print("MemDeAlloc " memRead_list[i])
  }  
}