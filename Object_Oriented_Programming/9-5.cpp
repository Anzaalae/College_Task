#include "9-5Book.h"
#include <iostream>
using namespace std;

int main() {
    Book book1("�������", 0, 50), book2("C++", 10000, 1000);
    if(!book1) cout<< "��¥��"<< endl;
    cout<< ++book2<< endl;
    cout<< book2++<< endl;
    cout<< book2 << endl;
}