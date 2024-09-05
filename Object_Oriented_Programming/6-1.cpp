#include <iostream>
using namespace std;

#include "Ram.h"

int main()
{
    Ram ram;

    ram.write(100, 'A');
    ram.write(101, 'B');
    ram.write(-2, 'C');
    ram.write(102400, 'D');

    char res= ram.read(100);

    if(res!= -1)
        cout<< "100 번지의 값 = "<< res<<endl;

    res = ram.read(101);
    if(res!= -1)
        cout<< "101 번지의 값 = "<< res<< endl;
    
    res = ram.read(-2);
    if(res!= -1)
        cout<< "-2 번지의 값 = "<< res<< endl;
    
    res = ram.read(102400);
    if(res!= -1)
        cout<< "102400 q번지의 값 = "<< res<< endl;
}