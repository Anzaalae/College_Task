#include "Ram.h"

#include <iostream>
using namespace std;

Ram::Ram(){
    for(int i= 0; i< MEM_SIZE; i++)
        Ram::mem[i]= 0;
}
Ram::~Ram(){
    cout<< "메모리가 제거됨"<< endl;
}

char Ram::read(int address){
    if(isValidAddr(address))
        return Ram::mem[address];
    else{
        cout<< "주소 범위를 벗어남"<< endl;
        return -1;  
    }
}

void Ram::write(int address, char value){
    if(isValidAddr(address))
        Ram::mem[address]= value;
    else{
        cout<< "주소 범위를 벗어남"<< endl;
    }
}

bool Ram::isValidAddr(int addr){
    if(addr >= 0 && addr < MEM_SIZE)
        return true;
    else 
        return false;
}