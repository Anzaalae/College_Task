#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, temp;
    cout<< "���� ���� ���ڿ��� �Է��ϼ���. �Է��� ���� &���� �Դϴ�."<< endl;
    getline(cin, temp, '&');
    cin.ignore();

    string find, replace;
    cout<< "find: ";
    getline(cin, find);
    cin.ignore();
    cout<< "replace: ";
    getline(cin, replace);
    cin.ignore();

    size_t location= 0;
    while(true)
    {
        location= s.find(find, location);
        if(location== string::npos) break;
        s.erase(location, sizeof(find));
        s.insert(location, replace);
        location+= sizeof(replace);
    }

    cout<< s<< endl;
}