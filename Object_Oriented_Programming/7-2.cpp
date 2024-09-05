#include <iostream>
using namespace std;

class Color {
    int red, green, blue;
public:
    Color() {red= green= blue= 0;}
    Color(int r, int g, int b) {setColor(r, g, b);}
    void setColor(int r, int g, int b) {red= r; green= g; blue= b; }
    void show() const {cout<< red<< ' '<< green<< ' '<< blue<< endl; }
};

int main() {
    Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
    Color* p;                     // Color 타입의 포인터 변수 p 선언
    p= &screenColor;
    p->show();
    Color colors[3];
    p= colors;

    p->setColor(255, 0, 0);
    (p+ 1)->setColor(0, 255, 0);
    (p+ 2)->setColor(0, 0, 255);

    for(int i= 0; i< 3; i++) {
        (p+ i)->show();
    }
}