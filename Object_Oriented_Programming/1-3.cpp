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
    cout<< "5개의 실수를 입력하라>>";

    for(int i= 0; i< 5; i++)
    {
        cin>> a[i];
    }
    cout<< "제일 큰 수 = "<< biggest(a, 5)<< endl;
}