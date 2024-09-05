#ifndef RAM_H
#define RMA_H

const int MEM_SIZE = 100* 1024;

class Ram{
    char mem[MEM_SIZE];
    int size;
public:
    Ram(); // mem�� 0���� �ʱ�ȭ �ϰ� size�� MEM_SIZE�� �ʱ�ȭ
    ~Ram(); // "�޸𸮰� ���ŵ�" ���ڿ� ���
    char read(int address); // address �ּ��� �޸𸮸� �о� ����
    void write(int address, char value); // address �ּҿ� valude ����
private:
    bool isValidAddr(int addr);
};

#endif