#include <iostream>
using namespace std;

bool average(int a[], int size, int& avg)
{
    if(size<= 0) return false;

    int total= 0;
    for(int i= 0; i< size; i++)
    {
        total += a[i];
    }
    avg= total/ size;

    return true;
}

int main()
{
    int x[]= {0,1,2,3,4,5};
    int avg;

    if(average(x, 5, avg)) cout<< "����� "<< avg<< endl;
    else cout<< "�Ű����� ����"<< endl;

    if(average(x, -1, avg)) cout<< "����� "<< avg<< endl;
    else cout<< "�Ű����� ����"<< endl;
}