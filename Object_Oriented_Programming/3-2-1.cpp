#include <iostream>
using namespace std;

int big(int a, int b)
{
    if(a> b) return a;
    else return b;
}

int big(int a, int b, int c)
{
    if(a>= b && a>= c) return a;
    else if(b>= c && b>= a) return b;
    else if(c>= a && c>= b) return c;
}


int main()
{
    int x= big(3, 5);
    int y= big(300, 60);
    int z= big(30, 60, 50);
    cout<< x<< ' '<< y<< ' '<< z<< endl;
}