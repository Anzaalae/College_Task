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
    friend bool operator==(Book& a, int price);
    friend bool operator==(Book& a, string str);
    friend bool operator==(Book& a, Book& b);
};

bool operator==(Book& a, int price) {
    if(a.price == price) return true;
    else return false;
}
bool operator==(Book& a, string str) {
    if(a.title.compare(str) == 0) return true;
    else return false;
}
bool operator==(Book& a, Book& b) {
        if(a.price == b.price && a.pages == b.pages && a.title.compare(b.title) == 0)
            return true;
        else
            return false;
    }

int main() {
    Book a("��ǰ C++", 30000, 500), b("��ǰ�� C++", 30000, 500);

    // price ��
    if(a== 30000) cout<< "���� 30000��"<< endl;

    // å ��
    if(a== "��ǰ C++") cout<< "��ǰ C++ �Դϴ�."<< endl;

    // �� ��
    if(a== b) cout<< "�� å�� ���� å�Դϴ�."<< endl;
}