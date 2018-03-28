#include <iostream>
#include <cstdint>
#include <fstream>
#include "interpeter.hpp"

void fillRe(core::runtimeEnvironment *re ){

    if(re->sig.VarReadU_count || re->sig.VarWriteU_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadU_where,re->sig.VarReadU_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteU_where,re->sig.VarWriteU_count);
        uint64_t size = 1 + (a>b?a:b);
        for(uint64_t i=0; i < size ; i++){
            re->VarReadU_data[i] = new uint64_t;
        }
    }
    if(re->sig.VarReadD_count || re->sig.VarWriteD_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadD_where,re->sig.VarReadD_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteD_where,re->sig.VarWriteD_count);
        uint64_t size = 1 + (a>b?a:b);
        for(uint64_t i=0; i < size ; i++){
            re->VarReadD_data[i] = new core::dtype;
        }
    }
    if(re->sig.VarReadI_count || re->sig.VarWriteI_count){
        uint64_t a = core::help::maxVal(re->sig.VarReadI_where,re->sig.VarReadI_count);
        uint64_t b = core::help::maxVal(re->sig.VarWriteI_where,re->sig.VarWriteI_count);
        uint64_t size = 1 + (a>b?a:b);
        for(uint64_t i=0; i < size ; i++){
            re->VarReadI_data[i] = new int64_t;
        }
    }
}



int main(){
    //DEBUG_COUT std::cout << sizeof(uint64_t) << std::endl;
    //DEBUG_COUT std::cout << (sizeof(core::instruction)/sizeof(uint64_t)) << std::endl;
    //DEBUG_COUT std::cout << "Hello world!" << std::endl;
    std::ifstream *addIn = new std::ifstream("./asm/callTest/add.slang.prog", std::ios::in | std::ios::binary);
    std::ifstream *setupIn = new std::ifstream("./asm/callTest/calerSetup.slang.prog", std::ios::in | std::ios::binary);
    std::ifstream *callerIn = new std::ifstream("./asm/callTest/caller.slang.prog", std::ios::in | std::ios::binary);



    core::programm *add_p = core::loadProgramm(addIn);
    core::programm *setup_p = core::loadProgramm(setupIn);
    core::programm *caller_p = core::loadProgramm(callerIn);

    core::runtimeEnvironment *re = core::buildRuntimeEnvironment(setup_p);
    fillRe(re);

    re->lib=add_p;
    re->callStorage = new core::runtimeEnvironment::call;
    core::executeProgramm(setup_p,re);

    re->MemRead_data[0]->mem[0]=1;
    re->MemRead_data[0]->mem[1]=2;
    re->MemRead_data[0]->mem[2]=3;
    re->MemRead_data[0]->mem[3]=4;
    re->MemRead_data[0]->mem[4]=5;

    re->MemRead_data[1]->mem[0]=9;
    re->MemRead_data[1]->mem[1]=8;
    re->MemRead_data[1]->mem[2]=7;
    re->MemRead_data[1]->mem[3]=6;
    re->MemRead_data[1]->mem[4]=5;

    core::executeProgramm(caller_p,re);

    std::cout << re->MemRead_data[0]->mem[0] << std::endl;
    std::cout << re->MemRead_data[0]->mem[1] << std::endl;
    std::cout << re->MemRead_data[0]->mem[2] << std::endl;
    std::cout << re->MemRead_data[0]->mem[3] << std::endl;
    std::cout << re->MemRead_data[0]->mem[4] << std::endl;
    return 0;
    //core::executeProgramm(loop,re);
    {
        std::ofstream outputFile ("data.bin", std::ios::out | std::ios::binary);

        for(uint64_t i = 0 ;i < 200 ; i++){
//            core::executeProgramm(loop,re);
            outputFile.write((char*)(re->MemRead_data[1]->mem), re->MemRead_data[1]->memSize*sizeof(core::dtype));
        }

        outputFile.close();
    }
    //DEBUG_COUT std::cout << std::endl;
    return 0;
}
