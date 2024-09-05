#include <iostream>
using namespace std;

int main()
{
    char c[100];
    int count= 0;
    cout<< "문자들을 입력하라(100개 미만)."<< endl;

    int i= 0;
    cin.getline(c, 100, '\n');

    while(c[i])
    {
        if(c[i]== 'x') count++;
        i++;
    }

    cout<< 'x'<<"의 개수는 "<< count<< endl;
}