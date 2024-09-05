#ifndef RAM_H
#define RMA_H

const int MEM_SIZE = 100* 1024;

class Ram{
    char mem[MEM_SIZE];
    int size;
public:
    Ram(); // mem을 0으로 초기화 하고 size를 MEM_SIZE로 초기화
    ~Ram(); // "메모리가 제거됨" 문자열 출력
    char read(int address); // address 주소의 메모리를 읽어 리턴
    void write(int address, char value); // address 주소에 valude 저장
private:
    bool isValidAddr(int addr);
};

#endif