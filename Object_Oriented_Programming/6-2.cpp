#include <iostream>
using namespace std;

class Int{
private:
    int value;
public:
    Int(int value);
    Int();
    void set(int value);
    int get() const;
};

Int::Int(int value){
    Int::value= value;
}

Int::Int(){
    Int::value= 0;
}

void Int::set(int value) {
    this->value= value;
}

int Int::get() const{
    return this->value;
}

int main()
{
    Int i1 = 20;
    const Int i2 = i1;
    i1.set(10);

    cout<< i1.get()<< " , "<< i2.get()<< endl;
}