#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius= 1; }
    Circle(int radius) { this->radius= radius; }
    double getArea() const { return 3.14*radius*radius; }

    int getRadius() {return radius;}
    void setRadius(int radius) {this->radius= radius;}
};

void swap(Circle *A, Circle *B) {
    int temp= A->getRadius();
    A->setRadius(temp);
    B->setRadius(A->getRadius());
}

int main() {
    Circle A;
    Circle B(3);
    cout<< "A의 면적 = "<< A.getArea()<< " , "<< "B의 면적 = "<< B.getArea()<< endl;
    swap(A, B);
    cout<< "A의 면적 = "<< A.getArea()<< " , "<< "B의 면적 = "<< B.getArea()<< endl;
}