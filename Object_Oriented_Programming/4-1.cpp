#include <iostream>
using namespace std;

int main()
{
    string line[5];

    for(int i= 0; i< 5; i++)
    {
        cout<< "이름: ";
        getline(cin, line[i]);
    }
    
    int diction= 0;

    for(int i= 1; i< 5; i++)
    {
        if(line[diction]< line[i]) diction= i;
    }

    cout<< "사전에서 가장 뒤에 나오는 문자열은 "<< line[diction];
}