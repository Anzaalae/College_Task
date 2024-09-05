#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void reverceArray(T input[], int num)
{
    for(int i= 0; i< num/ 2; i++) swap(input[i], input[num- 1- i]);
}

int main()
{
    int x[]= {1, 10, 100, 5, 4};
    reverceArray(x, 5);
    for(int i= 0; i< 5; i++) cout<< x[i]<< ' ';
    cout<< endl;
}