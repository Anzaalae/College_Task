#include <iostream>
using namespace std;

class Book {
    string title;
    int price;
    int pages;
public:
    Book(const string &title=string(), int price= 0, int pages= 0) {
        this->title= title;
        this->price= price;
        this->pages= pages;
    }

    void show() const {
        cout<< title<< ' '<< price<< "�� "<< pages<< " ������"<< endl;
    }

    const string &getTitle() const {
        return title;
    }

    Book& operator+=(int b2) {
        price+= b2;
        return *this;
    }
    Book& operator-=(int b2) {
        price-= b2;
        return *this;
    }
};

int main() {
    Book a("û��", 20000, 300), b("�̷�", 30000, 500);

    a+= 500;
    b-= 500;
    a.show();
    b.show();
}