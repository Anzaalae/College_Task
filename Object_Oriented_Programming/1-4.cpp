#include <iostream>
using namespace std;

int main()
{
    char c[100];
    int count= 0;
    cout<< "���ڵ��� �Է��϶�(100�� �̸�)."<< endl;

    int i= 0;
    cin.getline(c, 100, '\n');

    while(c[i])
    {
        if(c[i]== 'x') count++;
        i++;
    }

    cout<< 'x'<<"�� ������ "<< count<< endl;
}