#include <iostream>
using namespace std;

class Circle {
    int redius;
public:
    void setRadius(int redius); // �������� �����Ѵ�.
    double getArea() const; // ������ �����Ѵ�.
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
        cout<< "�� 1�� ������ >> ";
        cin>> temp;
        c[i].setRadius(temp);
    }

    int count= 0;
    for(int i= 0; i< 3; i++)
    {
        if(c[i].getArea()> 100.0) count++;
    }

    cout<< "������ 100���� ū ���� "<< count<< "�� �Դϴ�.\n";
}