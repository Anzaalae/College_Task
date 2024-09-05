#include <iostream>
using namespace std;

class Shape{
    string name;
public:
    Shape(string name): name(name){}
    void setName(string _name) {name= _name;}
    string getName(void) {return name;}
    virtual double getArea(void) = 0;
};

class Oval: public Shape{
    int r;
public:
    Oval(string name, int r): Shape(name), r(r){}
    double getArea(void) {return r* r* 3.141592;}
};

class Rect: public Shape{
    int width;
    int height;
public:
    Rect(string name, int width, int height): Shape(name), width(width), height(height){}
    double getArea(void) {return width* height;}
};

class Triangular: public Shape{
    int width;
    int height;
public:
    Triangular(string name, int width, int height): Shape(name), width(width), height(height){}
    double getArea(void) {return width* height/ 2.0;}
};

int main() {
    Shape *p[3];

    p[0]= new Oval("ºó´ë¶±", 10);
    p[1]= new Rect("Âû¶±", 30, 40);
    p[2]= new Triangular("Åä½ºÆ®", 30, 40);

    for(int i= 0; i< 3; i++)
        cout<< p[i]->getName()<< " ³ÐÀÌ´Â "<< p[i]->getArea()<< endl;

    for(int i= 0; i< 3; i++) delete p[i];
}