#include <iostream>

using namespace std;

int main()
{
    char name[100], address[100];
    int age;

    cout<< "이름은? ";
    cin.getline(name, 100);
    cout<< "주소는? ";
    cin.getline(address, 100);
    cout<< "나이는? ";
    cin>> age;

    cout<< "----------------------------------"<< '\n';
    cout<< name<< '. ';
    cout<< address<< '. ';
    cout<< age<< "세";
}