#include <iostream>
using namespace std;

class Calculator {
protected:
    int value1, value2;
public:
    friend istream &operator>>(istream &, Calculator &);
    virtual int calculate() const = 0;
};

istream &operator>>(istream &in, Calculator &calc) {
    return in>> calc.value1>> calc.value2;
}

class Adder: public Calculator {
    int calculate() const  {
        return value1 + value2;
    }
};

class Substractor: public Calculator {
    int calculate() const {
        return value1 - value2;
    }
};

void calculate(Calculator &calc) {
    cout<< "�� ���� ���� �Է��ϼ��� >>";
    cin>> calc;
    cout<< "���: "<< calc.calculate()<< endl;
}

int main() {
    Adder adder;
    Substractor substractor;
    calculate(adder);
    calculate(substractor);
}