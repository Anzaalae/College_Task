#include <iostream>
using namespace std;

template<typename T>
T add(T input[], int size)
{
    T total= 0;
    for(int i= 0; i< size; i++) total+= input[i];
    
    return total;
}

int main()
{
    int x[]= {1, 2, 3, 4, 5};
    double d[]= {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

    cout<< "sum of x[] = "<< add(x, 5)<< endl;
    cout<< "sum of d[] = "<< add(d, 6)<< endl;
}