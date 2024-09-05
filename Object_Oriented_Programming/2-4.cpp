#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success)
{
    for(int i= 0; i< 6; i++)
    {
        if(a[i]== c)
        {
            success= true;
            return a[i];
        }
    }

    success= false;
    return a[0];
}

int main()
{
    char s[]= "sMall";
    bool b= false;
    char& loc= find(s, 'M', b);
    if(b== false)
    {
        cout<< "M을 발견할 수 없다."<< endl;
        return 0;
    }
    loc= 'm';
    cout<< s<< endl;
}