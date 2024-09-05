#include <iostream>
using namespace std;

class Circle {
    int redius;
public:
    void setRadius(int redius); // 반지름을 설정한다.
    double getArea() const; // 면적을 리턴한다.
};

void Circle::setRadius(int radius) {
    this->redius= radius;
}

double Circle::getArea() const{
    return this->redius*this->redius*3.141592;
}

int main()
{
    Circle c[3];
    int temp;

    for(int i= 0; i< 3; i++) {
        cout<< "원 1의 반지름 >> ";
        cin>> temp;
        c[i].setRadius(temp);
    }

    int count= 0;
    for(int i= 0; i< 3; i++)
    {
        if(c[i].getArea()> 100.0) count++;
    }

    cout<< "면적이 100보다 큰 원은 "<< count<< "개 입니다.\n";
}