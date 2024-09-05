#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 1): radius(radius) {}
    void setRadius(int radius) {this->radius= radius;}
    double getArea() const {return 3.14*radius*radius;}
};

void readRadius(Circle *donut) {
    int temp;
    cout<< "정수 값으로 반지름을 입력하세요>> ";
    cin>> temp;
    donut->setRadius(temp);
}

int main() {
    Circle donut;
    readRadius(&donut);
    cout<< "donut의 면적 = "<< donut.getArea()<< endl;
}