#include <iostream>
using namespace std;

class Oval
{
    public:
        int width;
        int height;
    
        Oval(int _width, int _height){
            width= _width;
            height= _height;
        }
        Oval(){
            width= 1;
            height= 1;
        }

        ~Oval(){
            cout<< "Oval ¼Ò¸ê width: "<< width<< ", height: "<< height<< endl;
        }

        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }

        void set(int w, int h){
            width= w;
            height= h;
        }
        void show(){
            cout<< "width: "<< width<< ", "<< "height: "<< height<< endl;
        }
};

int main()
{
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout<< b.getWidth()<< ", " << b.getHeight()<< endl;
}