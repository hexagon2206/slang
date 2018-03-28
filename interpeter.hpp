#ifndef __PARA__CORE__
#define __PARA__CORE__

#include <stdint-gcc.h>

#include <cmath>
#include <fstream>


#define SAFETY_CHEKS



// tree prefix routing für schnelleres finden von Op Codes ?
#define OP_direktWriteInt 1
#define OP_direktWriteUInt 2
#define OP_direktWriteDtype 3
#define OP_vektorMemoryAllocDirect 4
#define OP_vektorMemoryAllocVariable 5
#define OP_MemoryDealloc 6
#define OP_generateSinLookup 7
#define OP_sampleVektorDirect 8
#define OP_sampleVektor 9
#define OP_addConstDirect 10
#define OP_addConstVar 11
#define OP_addVektors 12
#define OP_subConstDirekt 13
#define OP_subConstVar 14
#define OP_subVektors 15
#define OP_mulConst 16
#define OP_mulConstVar 17
#define OP_mulVektors 18
#define OP_divConst 19
#define OP_divConstVar 20
#define OP_divVektors 21
#define OP_setupCall 22
#define OP_makeCall 23
#define OP_deleteCall 24
#define OP_bindValue 25
#define P_Bind_MEMYTYPE_U 1
#define P_Bind_MEMYTYPE_D 2
#define P_Bind_MEMYTYPE_I 3
#define P_Bind_MEMYTYPE_M 4
#define P_Bind_Read 1
#define P_Bind_Write 2
#define P_Bind_Both 3




#define INST_LEN 9

namespace core{

    //the type used int the Calculation system
    typedef double dtype;

    // An operation can be performed one one ore more slots
    // a slot contains all the data
    typedef struct{
        //mem is a pointer to a chunk of memory where the data is stored
        dtype *mem=0;

        //memSize contains the length of the available memory at mem
        // this is onely checkt if SAFETY_CHEKS is defined
        uint64_t memSize;
    }memChunk;

    // A signature is used to define the in and outputs of a Programm
    // an executionEnvironment is generated acording to  signature
    struct signature{

        // the number of different varaibleRead( signed int64_t variables)
        uint64_t VarWriteI_count;
        // ann array with the length of VarWriteI_count
        // itcontaines the different addressed used for Reading
        uint64_t *VarWriteI_where;

        //same As above
        uint64_t VarWriteU_count;
        uint64_t *VarWriteU_where;

        //same As above
        uint64_t VarWriteD_count;
        uint64_t *VarWriteD_where;

        //same As above
        uint64_t VarReadI_count;
        uint64_t *VarReadI_where;

        //same As above
        uint64_t VarReadU_count;
        uint64_t *VarReadU_where;

        //same As above
        uint64_t VarReadD_count;
        uint64_t *VarReadD_where;

        //same As above
        uint64_t memAlloc_count;
        uint64_t *memAlloc_where;

        //same As above
        uint64_t memDealloc_count;
        uint64_t *memDealloc_where;

        //same As above
        uint64_t memWrite_count;
        uint64_t *memWrite_where;

        //same As above
        uint64_t memRead_count;
        uint64_t *memRead_where;
    };

    // stores an executable, and state aware instruction
    typedef struct {

        // The Opcode, one of the ones defined above
        uint64_t instruction;

        // An void Pointer for state awate instructions
        // may be used for "fancy stuff"
        void *storage;

        // the Parameter for the Instruction,
        // there semantic depends heavely on the instruction
        uint64_t data[INST_LEN];
    } instruction;


    // A slice Contains manny instructions,
    // which can be executed in paralell.
    typedef struct {

        // the individual instructions in the slice
        // they can be executed in parall
        instruction *instructions;

        // the instruction count of this slice
        uint64_t instructionCount;
    }slice;

    // a programm consists of manny slices,
    // which are executed in order.
    // furthermore if has a signature, wich descibes ist memory usage
    typedef struct {

        // the amount of slices contained in this programm
        uint64_t sliceCount;

        // the slices, wich are executed in order
        slice *slices;

        // The Memmory acces signature of this programm
        signature sig;
    }programm;


    // the runtime environement for proramm Executions,
    // supports programm caoning and sub calls

    typedef struct runtimeEnvironment_t{
        // the signature of the Environment
        // whot it is at least capabale of
        // maybe more, but at least this
        signature sig;

        uint64_t **VarReadU_data;
        uint64_t **VarWriteU_data;

        dtype    **VarWriteD_data;
        dtype    **VarReadD_data;

        int64_t  **VarWriteI_data;
        int64_t  **VarReadI_data;


        core::memChunk **MemWrite_data;
        core::memChunk **MemRead_data;

        struct call{
             struct runtimeEnvironment_t *re;
             programm *p;
        } ;
        struct call *callStorage;

        programm *lib;
    }runtimeEnvironment;

    core::runtimeEnvironment *buildRuntimeEnvironment(core::programm *p);
    void deletRuntimeEnvironment(core::runtimeEnvironment *re);


    void executeInstruction(instruction *inst,runtimeEnvironment *re);
    void executeSlice(slice *s,runtimeEnvironment *re);
    void executeProgramm(programm *p,runtimeEnvironment *re);

    core::programm *loadProgramm(std::ifstream *in);



    namespace help{
        uint64_t maxVal(uint64_t *p,uint64_t len);
    }

    namespace operations{
        void setupCall(
                core::runtimeEnvironment *re,
                uint64_t callID,
                core::programm *p
            );
        void deleteCall(
                core::runtimeEnvironment *re,
                uint64_t callID
            );

        void bindValue(
                core::runtimeEnvironment *re,
                uint64_t callID,
                uint64_t memType,
                uint64_t calMemID,
                uint64_t calRW,
                uint64_t mymemID,
                uint64_t myRW);
                //        // a variable is later referenced by a touple (id,type) for faster varaible lookup in the interpreter
//        // a for using a varialbe not deklaration is necesacry.
//        // the id must lay within the size bounderys, no checking is performed
//        // if used incorektly the appliction could crash or misbehave
//
//        // writes a intager value to a variable can be used for initialisation
        void direktWriteInt(
                core::runtimeEnvironment *re,
                uint64_t variable, // the Id to write the value to
                int64_t value     // the Int value to write
            );
        void direktWriteUInt(
                core::runtimeEnvironment *re,
                uint64_t variable, // the Id to write the value to
                uint64_t value     // the Int value to write
            );
//
//        // writes a double value to a variable can be used for initialisation
        void direktWriteDtype(
                core::runtimeEnvironment *re,
                uint64_t variable, // the Id to write the value to
                core::dtype value     // the Double value to write
            );

        // allocates space for an unitalised vektor variable
        void vektorMemoryAllocDirect(
                core::runtimeEnvironment *re,
                uint64_t vektorID,
                uint64_t size   // the size of data to allocate, therefor the size of the vektor
            );
        void vektorMemoryAllocVariable(
                core::runtimeEnvironment *re,
                uint64_t vektorID,
                uint64_t variableUInt   // the size of data to allocate, therefor the size of the vektor
            );        // dealocates the space of an previusly initalised vaktor variable, it is uninitialised afterwords

        void MemoryDealloc(
                core::runtimeEnvironment *re,
                uint64_t vektorID
            );

        void sampleVektorDirect(
                core::runtimeEnvironment *re,
                uint64_t src_VDT,
                uint64_t dst_VDT,
                uint64_t startOffset_SDT,
                uint64_t endOffset_SDT,
                core::dtype stepwith,
                core::dtype stepwithMultiplayer
            );
        void sampleVektor(
                core::runtimeEnvironment *re,
                uint64_t src_VDT,
                uint64_t dst_VDT,
                uint64_t startOffset_SDT,
                uint64_t endOffset_SDT,
                uint64_t stepwith,
                uint64_t stepwithMultiplayer
            );

        void generateSinLookup(
                core::runtimeEnvironment *re,
                uint64_t dst_VDT
            );

        void addConstDirect(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                core::dtype B_Direct
            );

        void addConstVar(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_SingleValue
            );

        void addVektors(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_V
            );

        void subConstDirekt(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                core::dtype direkt
            );

        void subConstVar(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_SingleValue
            );

        void subVektors(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_V
            );

        void mulConst(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                core::dtype direkt
            );
        void mulConstVar(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_SingleValue
            );

        void mulVektors(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_V
            );

        void divConst(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                core::dtype direkt
            );

        void divConstVar(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_SingleVariable
            );

        void divVektors(
                core::runtimeEnvironment *re,
                uint64_t dst_V,
                uint64_t A_V,
                uint64_t B_V
            );

    };
};

#endif
