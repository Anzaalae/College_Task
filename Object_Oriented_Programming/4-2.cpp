#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> line(5);

    cout<< "�̸��� 5�� �Է��϶�\n";

    for(int i= 0; i< 5; i++)
    {
        cout<< i+ 1<< " >> ";
        getline(cin, line[i]);
    }
    
    int diction= 0;

    for(int i= 1; i< 5; i++)
    {
        if(line[diction]< line[i]) diction= i;
    }

    cout<< "�������� ���� �ڿ� ������ ���ڿ��� "<< line[diction];
}