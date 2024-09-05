#include <iostream>
using namespace std;

class Rectangle{
    public:
        int width;
        int height;

        Rectangle()
        {
            width= 1;
            height= 1;
        }
        Rectangle(int line){
            width= line;
            height= line;
        }
        Rectangle(int _width, int _height){
            width= _width;
            height= _height;
        }

        int isSquare()
        {
            if(width== height) return 1;
            return 0;
        }
};

int main()
{
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}