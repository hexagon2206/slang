#include "interpeter.hpp"

#include <iostream>
const core::dtype pi = std::acos((core::dtype)-1);



void sizeMissMatch(){

}


core::programm *core::loadProgramm(std::ifstream *in){
    core::programm *p = new core::programm;

    in->read((char *)&(p->sig.VarWriteI_count),sizeof(p->sig.VarWriteI_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarWriteI_count = " << p->sig.VarWriteI_count << std::endl;
    p->sig.VarWriteI_where = new uint64_t[p->sig.VarWriteI_count];
    for(uint64_t i=0 ; i < p->sig.VarWriteI_count ; i++){
        in->read((char *)(p->sig.VarWriteI_where+i),sizeof(p->sig.VarWriteI_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarWriteI_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.VarWriteU_count),sizeof(p->sig.VarWriteU_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarWriteU_count = " << p->sig.VarWriteU_count << std::endl;
    p->sig.VarWriteU_where = new uint64_t[p->sig.VarWriteU_count];
    for(uint64_t i=0 ; i < p->sig.VarWriteU_count ; i++){
        in->read((char *)(p->sig.VarWriteU_where+i),sizeof(p->sig.VarWriteU_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarWriteU_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.VarWriteD_count),sizeof(p->sig.VarWriteD_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarWriteD_count = " << p->sig.VarWriteD_count << std::endl;
    p->sig.VarWriteD_where = new uint64_t[p->sig.VarWriteD_count];
    for(uint64_t i=0 ; i < p->sig.VarWriteD_count ; i++){
        in->read((char *)(p->sig.VarWriteD_where+i),sizeof(p->sig.VarWriteD_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarWriteD_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.VarReadI_count),sizeof(p->sig.VarReadI_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarReadI_count = " << p->sig.VarReadI_count << std::endl;
    p->sig.VarReadI_where = new uint64_t[p->sig.VarReadI_count];
    for(uint64_t i=0 ; i < p->sig.VarReadI_count ; i++){
        in->read((char *)(p->sig.VarReadI_where+i),sizeof(p->sig.VarReadI_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarReadI_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.VarReadU_count),sizeof(p->sig.VarReadU_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarReadU_count = " << p->sig.VarReadU_count << std::endl;
    p->sig.VarReadU_where = new uint64_t[p->sig.VarReadU_count];
    for(uint64_t i=0 ; i < p->sig.VarReadU_count ; i++ ){
        in->read((char *)(p->sig.VarReadU_where + i ),sizeof(p->sig.VarReadU_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarReadU_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.VarReadD_count),sizeof(p->sig.VarReadD_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.VarReadD_count = " << p->sig.VarReadD_count << std::endl;
    p->sig.VarReadD_where = new uint64_t[p->sig.VarReadD_count];
    for(uint64_t i=0 ; i < p->sig.VarReadD_count ; i++ ){
        in->read((char *)(p->sig.VarReadD_where + i ),sizeof(p->sig.VarReadD_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.VarReadD_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.memAlloc_count),sizeof(p->sig.memAlloc_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.memAlloc_count = " << p->sig.memAlloc_count << std::endl;
    p->sig.memAlloc_where = new uint64_t[p->sig.memAlloc_count];
    for(uint64_t i=0 ; i < p->sig.memAlloc_count ; i++ ){
        in->read((char *)(p->sig.memAlloc_where + i ),sizeof(p->sig.memAlloc_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.memAlloc_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.memDealloc_count),sizeof(p->sig.memDealloc_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.memDealloc_count = " << p->sig.memDealloc_count << std::endl;
    p->sig.memDealloc_where = new uint64_t[p->sig.memDealloc_count];
    for(uint64_t i=0 ; i < p->sig.memDealloc_count ; i++ ){
        in->read((char *)(p->sig.memDealloc_where + i ),sizeof(p->sig.memDealloc_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.memDealloc_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.memWrite_count),sizeof(p->sig.memWrite_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.memWrite_count = " << p->sig.memWrite_count << std::endl;
    p->sig.memWrite_where = new uint64_t[p->sig.memWrite_count];
    for(uint64_t i=0 ; i < p->sig.memWrite_count ; i++ ){
        in->read((char *)(p->sig.memWrite_where + i ),sizeof(p->sig.memWrite_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.memWrite_where[i] << std::endl;
    }

    in->read((char *)&(p->sig.memRead_count),sizeof(p->sig.memRead_count));
    /*DEBUG_COUT*/ std::cout << "p->sig.memRead_count = " << p->sig.memRead_count << std::endl;
    p->sig.memRead_where = new uint64_t[p->sig.memRead_count];
    for(uint64_t i=0 ; i < p->sig.memRead_count ; i++ ){
        in->read((char *)(p->sig.memRead_where + i ),sizeof(p->sig.memRead_where[0]));
        /*DEBUG_COUT*/ std::cout << "at:" << p->sig.memRead_where[i] << std::endl;
    }


    in->read((char *)&(p->sliceCount),sizeof(p->sliceCount));
    /*DEBUG_COUT*/ std::cout << "p->sliceCount = " << p->sliceCount << std::endl;
    p->slices = new core::slice[p->sliceCount];

    for(uint64_t i=0 ; i<p->sliceCount ; i++ ){
        in->read((char *)&(p->slices[i].instructionCount),sizeof(p->slices[i].instructionCount));
        /*DEBUG_COUT*/ std::cout << "p->slices[" << i << "].instructionCount = " << p->slices[i].instructionCount << std::endl;
        p->slices[i].instructions = new core::instruction[p->slices[i].instructionCount];
    }
    for(uint64_t i=0 ; i<p->sliceCount ; i++ ){
        core::instruction *insts = p->slices[i].instructions;
        uint64_t instCount = p->slices[i].instructionCount;
        for( uint64_t i=0 ; i< instCount ; i++){
            in->read((char *)(&insts[i].instruction),sizeof(insts[i].instruction));
            for( uint64_t j=0 ; j<INST_LEN ; j++){
                in->read((char *)(insts[i].data+j),sizeof(insts[i].data[j]));
            }
        }
    }

    return p;
}


void core::executeInstruction(core::instruction *inst,core::runtimeEnvironment *re){
    switch(inst->instruction){
    case OP_direktWriteInt:{

        uint64_t variable =             inst->data[0];
        int64_t value     = (int64_t)   inst->data[1];

        core::operations::direktWriteInt(re,variable,value);

        break;
    }
    case OP_direktWriteUInt:{

        uint64_t variable =             inst->data[0];
        uint64_t value    =             inst->data[1];

        core::operations::direktWriteUInt(re,variable,value);

        break;
    }
    case OP_direktWriteDtype:{

        uint64_t variable =             inst->data[0];
        dtype value       = *((core::dtype *)(inst->data+1));

        core::operations::direktWriteDtype(re,variable,value);

        break;
    }
    case OP_vektorMemoryAllocDirect:{
        uint64_t vektorID =             inst->data[0];
        uint64_t size     =             inst->data[1];
        core::operations::vektorMemoryAllocDirect(re,vektorID,size);

        break;
    }
    case OP_vektorMemoryAllocVariable:{
        uint64_t vektorID =             inst->data[0];
        uint64_t variableUInt =         inst->data[1];
        core::operations::vektorMemoryAllocVariable(re,vektorID,variableUInt);

        break;
    }

    case OP_MemoryDealloc:{
        uint64_t vektorID =             inst->data[0];
        core::operations::MemoryDealloc(re,vektorID);

        break;
    }
    case OP_sampleVektor:{
        uint64_t src_VDT                = inst->data[0];
        uint64_t dst_VDT                = inst->data[1];
        uint64_t startOffset_SDT        = inst->data[2];
        uint64_t endOffset_SDT          = inst->data[3];
        uint64_t stepwith            = inst->data[4];
        uint64_t stepwithMultiplayer = inst->data[5];
        core::operations::sampleVektor(re,src_VDT,dst_VDT,startOffset_SDT,endOffset_SDT,stepwith,stepwithMultiplayer);
        break;
    }
    case OP_generateSinLookup:{
        uint64_t dst_VDT = inst->data[0];
        core::operations::generateSinLookup(re,dst_VDT);
        break;
    }
    case OP_addConstDirect:{
        uint64_t dst_V     = inst->data[0];
        uint64_t A_V       = inst->data[1];
        core::dtype direkt = *((core::dtype *)(inst->data+2));
        core::operations::addConstDirect(re,dst_V,A_V,direkt);
        break;
    }
    case OP_addConstVar:{
        uint64_t dst_V          = inst->data[0];
        uint64_t A_V            = inst->data[1];
        uint64_t B_SingleValue  = inst->data[2];
        core::operations::addConstVar(re,dst_V,A_V,B_SingleValue);
        break;
    }

    case OP_addVektors:{
        uint64_t dst_V = inst->data[0];
        uint64_t A_V   = inst->data[1];
        uint64_t B_V   = inst->data[2];
        core::operations::addVektors(re,dst_V,A_V,B_V);
        break;
    }

    case OP_subConstDirekt:{
        uint64_t dst_V     = inst->data[0];
        uint64_t A_V       = inst->data[1];
        core::dtype direkt = *((core::dtype *)(inst->data+2));
        core::operations::subConstDirekt(re,dst_V,A_V,direkt);
        break;
    }

    case OP_subConstVar:{
        uint64_t dst_V          = inst->data[0];
        uint64_t A_V            = inst->data[1];
        uint64_t B_SingleValue  = inst->data[2];
        core::operations::subConstVar(re,dst_V,A_V,B_SingleValue);
        break;
    }

    case OP_subVektors:{
        uint64_t dst_V = inst->data[0];
        uint64_t A_V   = inst->data[1];
        uint64_t B_V   = inst->data[2];
        core::operations::subVektors(re,dst_V,A_V,B_V);
        break;
    }

    case OP_mulConst:{
        uint64_t dst_V     = inst->data[0];
        uint64_t A_V       = inst->data[1];
        core::dtype direkt = *((core::dtype *)(inst->data+2));
        core::operations::mulConst(re,dst_V,A_V,direkt);
        break;
    }
    case OP_mulConstVar:{
        uint64_t dst_V          = inst->data[0];
        uint64_t A_V            = inst->data[1];
        uint64_t B_SingleValue  = inst->data[2];
        core::operations::mulConstVar(re,dst_V,A_V,B_SingleValue);
        break;
    }

    case OP_mulVektors:{
        uint64_t dst_V = inst->data[0];
        uint64_t A_V   = inst->data[1];
        uint64_t B_V   = inst->data[2];
        core::operations::mulVektors(re,dst_V,A_V,B_V);
        break;
    }

    case OP_divConst:{
        uint64_t dst_V     = inst->data[0];
        uint64_t A_V       = inst->data[1];
        core::dtype direkt = *((core::dtype *)(inst->data+2));
        core::operations::divConst(re,dst_V,A_V,direkt);
        break;
    }
    case OP_divConstVar:{
        uint64_t dst_V          = inst->data[0];
        uint64_t A_V            = inst->data[1];
        uint64_t B_SingleValue  = inst->data[2];
        core::operations::divConstVar(re,dst_V,A_V,B_SingleValue);
        break;
    }

    case OP_divVektors:{
        uint64_t dst_V = inst->data[0];
        uint64_t A_V   = inst->data[1];
        uint64_t B_V   = inst->data[2];
        core::operations::divVektors(re,dst_V,A_V,B_V);
        break;
    }
    case OP_setupCall:{
        uint64_t callID = inst->data[0];
        uint64_t libSlot = inst->data[0];
        core::operations::setupCall(re,callID,re->lib + libSlot);
        break;
    }
    case OP_makeCall:{
        uint64_t callID = inst->data[0];
        core::executeProgramm(re->callStorage[callID].p,re->callStorage[callID].re);
        break;
    }
    case OP_deleteCall:{
        uint64_t callID = inst->data[0];
        core::operations::deleteCall(re,callID);
        break;
    }
    case OP_bindValue:{
        uint64_t callID   = inst->data[0];
        uint64_t memType  = inst->data[1];
        uint64_t calMemID = inst->data[2];
        uint64_t calRW    = inst->data[3];
        uint64_t mymemID  = inst->data[4];
        uint64_t myRW     = inst->data[5];
        core::operations::bindValue( re , callID , memType , calMemID , calRW , mymemID , myRW);
        break;
    }
    default:
        std::cout << "unknown OP Code : " << inst->instruction << std::endl;
        break;
    }
    return;
}



void core::executeSlice(core::slice *s,core::runtimeEnvironment *re){
    for(uint64_t i=0;i<s->instructionCount;i++){
        executeInstruction(s->instructions+i,re);
    }
}

void core::executeProgramm(core::programm *p,core::runtimeEnvironment *re){

    //nicht paralelisierbar da sequentielle ausführung aller slices gewünscht
    for(uint64_t i=0;i<p->sliceCount;i++){
        executeSlice(p->slices+i,re);
    }
}





void core::operations::setupCall(
        core::runtimeEnvironment *re,
        uint64_t callID,
        core::programm *p
    ){
    re->callStorage[callID].re=core::buildRuntimeEnvironment(p);
    re->callStorage[callID].p=p;
}
void core::operations::deleteCall(
        core::runtimeEnvironment *re,
        uint64_t callID
    ){
    core::deletRuntimeEnvironment(re->callStorage[callID].re);
    re->callStorage[callID].p = NULL;
}


//writes a intager value to a variable  can be used for initialisation
void core::operations::direktWriteInt(
        core::runtimeEnvironment *re,
        uint64_t variable, // the Id to write the value to
        int64_t value     // the Int value to write
      ){
    *re->VarWriteI_data[variable] = value;
}
void core::operations::direktWriteUInt(
        core::runtimeEnvironment *re,
        uint64_t variable, // the Id to write the value to
        uint64_t value     // the Int value to write
      ){
    *re->VarWriteU_data[variable] = value;
}

//
// writes a double value to a variable can be used for initialisation
void core::operations::direktWriteDtype(
        core::runtimeEnvironment *re,
        uint64_t variable, // the Id to write the value to
        core::dtype value     // the Double value to write
      ){
    *re->VarWriteD_data[variable] = value;
}


// allocates space for an unitalised vektor variable
void core::operations::vektorMemoryAllocDirect(
        core::runtimeEnvironment *re,
        uint64_t vektorID,
        uint64_t size   // the size of data to allocate, therefor the size of the vektor
    ){
    core::memChunk *mc = new core::memChunk;
    mc->mem=new dtype[size];
    mc->memSize=size;

    re->MemRead_data[vektorID] = mc;
    re->MemWrite_data[vektorID] = mc;
}
void core::operations::vektorMemoryAllocVariable(
        core::runtimeEnvironment *re,
        uint64_t vektorID,
        uint64_t variableUInt   // the size of data to allocate, therefor the size of the vektor
    ){
    core::operations::vektorMemoryAllocDirect(re,vektorID,*re->VarReadU_data[variableUInt]);
}



void core::operations::MemoryDealloc(
        core::runtimeEnvironment *re,
        uint64_t vektorID
    ){
    delete[] re->MemRead_data[vektorID]->mem;
    re->MemRead_data[vektorID]->memSize=0;

    delete re->MemRead_data[vektorID];
    re->MemRead_data[vektorID] = NULL;
    re->MemWrite_data[vektorID] = NULL;
}

void core::operations::sampleVektor(
        core::runtimeEnvironment *re,
        uint64_t src_VDT,
        uint64_t dst_VDT,
        uint64_t startOffset_SDT,
        uint64_t endOffset_SDT,
        uint64_t stepwith,
        uint64_t stepwithMultiplayer
    ){

    core::dtype freq = *re->VarReadD_data[stepwith] *
                       *re->VarReadD_data[stepwithMultiplayer];

    core::dtype j= *re->VarReadD_data[startOffset_SDT];

    core::memChunk *src = re->MemRead_data[src_VDT];
    core::memChunk *dst = re->MemWrite_data[dst_VDT];

    uint64_t lookupLen = src->memSize;
    while(((uint64_t)j) > lookupLen){
            j -= lookupLen;
    }

    uint64_t dstLen = dst->memSize;

    for(uint64_t i = 0 ; i < dstLen ; i++ ){
        dtype t = src->mem[(uint64_t)j];
        dst->mem[i] =  t;
        j+=freq;

        while(((uint64_t)j) > lookupLen){
            j -= lookupLen;
        }
    }
    *re->VarWriteD_data[endOffset_SDT]=j;
}

void core::operations::generateSinLookup(
        core::runtimeEnvironment *re,
        uint64_t dst_VDT
    ){
    uint64_t sampleCount = re->MemWrite_data[dst_VDT]->memSize;
    dtype faktor =  (pi*2)/sampleCount;
   for(uint64_t i = 0 ; i < sampleCount ; i++ ){
        re->MemWrite_data[dst_VDT]->mem[i] = (dtype)std::sin( i * faktor);
    }
}







void core::operations::addConstDirect(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    core::dtype direkt
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] + direkt;
    }
}

void core::operations::addConstVar(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_SingleValue
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::dtype     B   = *re->VarReadD_data[B_SingleValue];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] + B;
    }
}

void core::operations::addVektors(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_V
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::memChunk *B   = re->MemRead_data[B_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] + B->mem[i];
    }
}

void core::operations::subConstDirekt(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    core::dtype direkt
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] - direkt;
    }
}

void core::operations::subConstVar(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_SingleValue
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::dtype     B   = *re->VarReadD_data[B_SingleValue];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] - B;
    }
}

void core::operations::subVektors(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_V
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::memChunk *B   = re->MemRead_data[B_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] - B->mem[i];
    }
}

void core::operations::mulConst(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    core::dtype direkt
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] + direkt;
    }
}
void core::operations::mulConstVar(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_SingleValue
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::dtype     B   = *re->VarReadD_data[B_SingleValue];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] * B;
    }
}

void core::operations::mulVektors(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_V
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::memChunk *B   = re->MemRead_data[B_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] * B->mem[i];
    }
}

void core::operations::divConst(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    core::dtype direkt
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] / direkt;
    }
}

void core::operations::divConstVar(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_SingleValue
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    dtype B   = *re->VarReadD_data[B_SingleValue];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] / B;
    }
}

void core::operations::divVektors(
    core::runtimeEnvironment *re,
    uint64_t dst_V,
    uint64_t A_V,
    uint64_t B_V
){
    core::memChunk *dst = re->MemWrite_data[dst_V];
    core::memChunk *A   = re->MemRead_data[A_V];
    core::memChunk *B   = re->MemRead_data[B_V];
    for(uint64_t i=0;i < dst->memSize;i++){
        dst->mem[i] = A->mem[i] / B->mem[i];
    }
}




uint64_t core::help::maxVal(uint64_t *p,uint64_t len){
    uint64_t max = p[0];
    for(uint i = 0 ; i<len ;i++){
        if(p[i]>max)max=p[i];
    }
    return max;
}

core::runtimeEnvironment *core::buildRuntimeEnvironment(core::programm *p){
    core::runtimeEnvironment *re = new core::runtimeEnvironment;

    re->sig = p->sig;

    if(re->sig.memRead_count || re->sig.memWrite_count || re->sig.memAlloc_count ){
        uint64_t a = core::help::maxVal(re->sig.memRead_where ,re->sig.memRead_count);
        uint64_t b = core::help::maxVal(re->sig.memWrite_where,re->sig.memWrite_count);
        uint64_t c = core::help::maxVal(re->sig.memAlloc_where ,re->sig.memAlloc_count);
        uint64_t size = (a>b?a:b);
        size = 1 + (size>c?size:c);

        re->MemRead_data = new core::memChunk*[size];
        re->MemWrite_data = re->MemRead_data ;
    }
    if(re->sig.VarReadU_count || re->sig.VarWriteU_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadU_where,re->sig.VarReadU_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteU_where,re->sig.VarWriteU_count);
        uint64_t size = 1 + (a>b?a:b);
        /*DEBUG_COUT*/ std::cout << "\tSize_U = " << size;
        re->VarReadU_data = new uint64_t*[size];
        re->VarWriteU_data = re->VarReadU_data;
    }
    if(re->sig.VarReadD_count || re->sig.VarWriteD_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadD_where,re->sig.VarReadD_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteD_where,re->sig.VarWriteD_count);
        uint64_t size = 1 + (a>b?a:b);
        /*DEBUG_COUT*/ std::cout << "\tSize_D = " << size;
        re->VarReadD_data = new core::dtype*[size];
        re->VarWriteD_data = re->VarReadD_data;
    }
    if(re->sig.VarReadI_count || re->sig.VarWriteI_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadI_where,re->sig.VarReadI_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteI_where,re->sig.VarWriteI_count);
        uint64_t size = 1 + (a>b?a:b);
        /*DEBUG_COUT*/ std::cout << "\tSize_I = " << size;
        re->VarReadI_data = new int64_t*[size];
        re->VarWriteI_data = re->VarReadI_data;
    }
    return re;
}

void core::deletRuntimeEnvironment(core::runtimeEnvironment *re){
    delete[] re->VarReadU_data;
    delete[] re->VarWriteU_data;
    delete[] re->VarWriteD_data;
    delete[] re->VarReadD_data;
    delete[] re->VarWriteI_data;
    delete[] re->VarReadI_data;
    delete[] re->MemWrite_data;
    delete[] re->MemRead_data;
    delete[] re->lib;


    delete re;
}



void core::operations::bindValue(
        core::runtimeEnvironment *re,
        uint64_t callID,
        uint64_t memType,
        uint64_t calMemID,
        uint64_t calRW,
        uint64_t mymemID,
        uint64_t myRW)
{
    core::runtimeEnvironment *pre = re->callStorage[callID].re;
    switch(memType){
        case P_Bind_MEMYTYPE_U:{
            switch(calRW){
                case P_Bind_Both:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadU_data[calMemID] = re->VarReadU_data[mymemID];
                            pre->VarWriteU_data[calMemID] = re->VarReadU_data[mymemID];
                            return;

                         case P_Bind_Write:
                            pre->VarReadU_data[calMemID] = re->VarWriteU_data[mymemID];
                            pre->VarWriteU_data[calMemID] = re->VarReadU_data[mymemID];
                            return;
                    }
                case P_Bind_Read:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadU_data[calMemID] = re->VarReadU_data[mymemID];
                            return;
                         case P_Bind_Write :
                            pre->VarReadU_data[calMemID] = re->VarWriteU_data[mymemID];
                            return;
                    }
                case P_Bind_Write:{
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarWriteU_data[calMemID] = re->VarReadU_data[mymemID];
                            return;
                         case P_Bind_Write:
                            pre->VarWriteU_data[calMemID] = re->VarWriteU_data[mymemID];
                            return;
                    }
                }
            }
        }
        case P_Bind_MEMYTYPE_D:{
            switch(calRW){
                case P_Bind_Both:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadD_data[calMemID] = re->VarReadD_data[mymemID];
                            pre->VarWriteD_data[calMemID] = re->VarReadD_data[mymemID];
                            return;

                         case P_Bind_Write:
                            pre->VarReadD_data[calMemID] = re->VarWriteD_data[mymemID];
                            pre->VarWriteD_data[calMemID] = re->VarReadD_data[mymemID];
                            return;
                    }
                case P_Bind_Read:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadD_data[calMemID] = re->VarReadD_data[mymemID];
                            return;
                         case P_Bind_Write :
                            pre->VarReadD_data[calMemID] = re->VarWriteD_data[mymemID];
                            return;
                    }
                case P_Bind_Write:{
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarWriteD_data[calMemID] = re->VarReadD_data[mymemID];
                            return;
                         case P_Bind_Write:
                            pre->VarWriteD_data[calMemID] = re->VarWriteD_data[mymemID];
                            return;
                    }
                }
            }
        }
        case P_Bind_MEMYTYPE_I:{
            switch(calRW){
                case P_Bind_Both:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadI_data[calMemID] = re->VarReadI_data[mymemID];
                            pre->VarWriteI_data[calMemID] = re->VarReadI_data[mymemID];
                            return;

                         case P_Bind_Write:
                            pre->VarReadI_data[calMemID] = re->VarWriteI_data[mymemID];
                            pre->VarWriteI_data[calMemID] = re->VarReadI_data[mymemID];
                            return;
                    }
                case P_Bind_Read:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarReadI_data[calMemID] = re->VarReadI_data[mymemID];
                            return;

                         case P_Bind_Write :
                            pre->VarReadI_data[calMemID] = re->VarWriteI_data[mymemID];
                            return;
                    }
                case P_Bind_Write:{
                    switch(myRW){
                         case P_Bind_Read :
                            pre->VarWriteI_data[calMemID] = re->VarReadI_data[mymemID];
                            return;

                         case P_Bind_Write:
                            pre->VarWriteI_data[calMemID] = re->VarWriteI_data[mymemID];
                            return;
                    }
                }
            }
        }
        case P_Bind_MEMYTYPE_M:{
            switch(calRW){

                case P_Bind_Both:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->MemRead_data[calMemID] = re->MemRead_data[mymemID];
                            pre->MemWrite_data[calMemID] = re->MemRead_data[mymemID];
                            return;

                         case P_Bind_Write:
                            pre->MemRead_data[calMemID] = re->MemWrite_data[mymemID];
                            pre->MemWrite_data[calMemID] = re->MemRead_data[mymemID];
                            return;
                    }
                case P_Bind_Read:
                    switch(myRW){
                         case P_Bind_Read :
                            pre->MemRead_data[calMemID] = re->MemRead_data[mymemID];
                            return;
                         case P_Bind_Write :
                            pre->MemRead_data[calMemID] = re->MemWrite_data[mymemID];
                            return;
                    }
                case P_Bind_Write:{
                    switch(myRW){
                         case P_Bind_Read :
                            pre->MemWrite_data[calMemID] = re->MemRead_data[mymemID];
                            return;
                         case P_Bind_Write:
                            pre->MemWrite_data[calMemID] = re->MemWrite_data[mymemID];
                            return;
                    }
                }
            }
        }
    }
    return;
}





















