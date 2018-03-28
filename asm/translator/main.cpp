#include <iostream>
#include <fstream>
#include <string>

#define lineLength 16000

void fail(){
    std::cout << "fail" << std::endl;
}

uint64_t fillerVal = 0xDEADBEEF;
uint64_t fillerLen = sizeof(uint64_t);

void parseElem(std::ofstream *outputFile,char *str){
    switch(str[0]){
        case 'F' : {
            outputFile->write((char*)&fillerVal , fillerLen);
            break;
        }
        case 'i' :
        case 'I' : {
            switch(str[1]){
            case '6':
                switch(str[2]){
                case '4':
                    int64_t v = std::stoll (str+4);
                    outputFile->write((char*)(&v), sizeof(int64_t));
                    break;
                }
                break;
            case '3':
                switch(str[2]){
                case '2':
                    int32_t v = std::stoll(str+4);
                    outputFile->write((char*)(&v), sizeof(int32_t));
                    break;
                }
                break;
            default:fail();
            }
            break;
        }
        case 'u' :
        case 'U' : {
            switch(str[1]){
            case '6':
                switch(str[2]){
                case '4':
                    uint64_t v = std::stoull (str+4);
                    outputFile->write((char*)(&v), sizeof(uint64_t));
                    break;
                }
                break;
            case '3':
                switch(str[2]){
                case '2':
                    uint32_t v = std::stoull(str+4);
                    outputFile->write((char*)(&v), sizeof(uint32_t));
                    break;
                }
                break;
            default:fail();
            }
            break;
        }
        case 'd' :
        case 'D' : {
            switch(str[1]){
            case '6':
                switch(str[2]){
                case '4':
                    double v = std::stold (str+4);
                    outputFile->write((char*)(&v), sizeof(double));
                    break;
                }
                break;
            case '3':
                switch(str[2]){
                case '2':
                    float v = std::stold (str+4);
                    outputFile->write((char*)(&v), sizeof(float));
                    break;
                }
                break;
            default:fail();
            }
            break;
        }
        default:fail();
    }
}

void parseLine(std::ofstream *outputFile,char *str,char seperator){
    char *mstr=str;
    char *start=str;
    while(*mstr){
        if(seperator == *mstr){
            *mstr='\0';
            parseElem(outputFile,start);
            mstr++;
            start=mstr;
        }else{
            mstr++;
        }
    }
    parseElem(outputFile,start);
}


int main(int args,char **argc){
    if(3!=args){
        std::cout << "wrong usage, two parameters, ( inputFile OutputFile ) !" << std::endl;
        return -1;
    }

    std::ifstream in(argc[1], std::ios::in );
    std::ofstream outputFile (argc[2], std::ios::out | std::ios::binary);
    {
        int e = 0;
        if(!in) {
            std::cout << "Cannot open input file.\n";
            e |= 1;
        }
        if(!outputFile) {
            std::cout << "Cannot output input file.\n";
            e |= 2;
        }

        if(e)return e;
    }

    char str[lineLength];


    while(in) {
        in.getline(str, lineLength);
        if(!in) break;
        parseLine(&outputFile,str,' ');
    }

    in.close();
    outputFile.close();

    return 0;
}
