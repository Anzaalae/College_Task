#include <iostream>
#include <string>
using namespace std;

class Circle
{
    int radius;

public:
    Circle(int radius = 1) : radius(radius) {}
    void setRadius(int radius) { this->radius = radius; }
    int getRadius() const { return radius; }
    double getArea() const { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle
{
    string name;

public:
    NamedCircle(string _name = "", int _radius = 1) : Circle(_radius)
    {
        Circle::setRadius(_radius);
        name = _name;
    }
    void show()
    {
        cout << "반지름이 " << Circle::getRadius() << "인 " << name << endl;
    }
    string getName()
    {
        return name;
    }
    void setCircle(int _radius, string _name)
    {
        Circle::setRadius(_radius);
        name = _name;
    }

    friend istream &operator>>(istream &in, NamedCircle &circle);
};

istream &operator>>(istream &in, NamedCircle &circle)
{
    int radius;
    string name;
    in >> radius >> name;
    circle.setCircle(radius, name);
    return in;
}

int main()
{
    const int NUM_OF_PIZZA = 5;
    NamedCircle pizza[NUM_OF_PIZZA];
    cout << "5개의 피자 반지름과 피자 이름을 입력하세요. \n";
    int radius;
    string name;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " >> ";
        cin >> pizza[i];
    }

    NamedCircle large = pizza[0];
    for (int i = 1; i < 5; i++)
    {
        if (pizza[i].getArea() > large.getArea())
            large = pizza[i];
    }

    cout << "가장 면적이 큰 피자는 " << large.getName() << "입니다.\n";
}