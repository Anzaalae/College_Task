#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char password[100], password2[100];
    cout<< "새 암호를 입력하시오 >>";
    cin>> password;
    cout<< "새 암호를 다시 입력하세요 >>";
    cin>> password2;

    int check;
    check= strcmp(password, password2);

    if(check== 0) cout<< "같습니다.";
    else if(check== 1) cout<< "같지 않습니다.";

}