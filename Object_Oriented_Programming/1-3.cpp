#include <iostream>
using namespace std;

double biggest(double a[], int num)
{
    double big= a[0];
    for(int i= 1; i< num; i++)
    {
        if(big< a[i]) big= a[i];
    }

    return big;
}

int main()
{
    double a[5];
    cout<< "5���� �Ǽ��� �Է��϶�>>";

    for(int i= 0; i< 5; i++)
    {
        cin>> a[i];
    }
    cout<< "���� ū �� = "<< biggest(a, 5)<< endl;
}