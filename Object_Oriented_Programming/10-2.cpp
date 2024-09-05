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
        cout << "�������� " << Circle::getRadius() << "�� " << name << endl;
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
    cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���. \n";
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

    cout << "���� ������ ū ���ڴ� " << large.getName() << "�Դϴ�.\n";
}