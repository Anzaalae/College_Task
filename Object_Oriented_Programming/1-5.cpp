#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char password[100], password2[100];
    cout<< "�� ��ȣ�� �Է��Ͻÿ� >>";
    cin>> password;
    cout<< "�� ��ȣ�� �ٽ� �Է��ϼ��� >>";
    cin>> password2;

    int check;
    check= strcmp(password, password2);

    if(check== 0) cout<< "�����ϴ�.";
    else if(check== 1) cout<< "���� �ʽ��ϴ�.";

}