#include <iostream>
using namespace std;

int main()
{
    string line[5];

    for(int i= 0; i< 5; i++)
    {
        cout<< "�̸�: ";
        getline(cin, line[i]);
    }
    
    int diction= 0;

    for(int i= 1; i< 5; i++)
    {
        if(line[diction]< line[i]) diction= i;
    }

    cout<< "�������� ���� �ڿ� ������ ���ڿ��� "<< line[diction];
}