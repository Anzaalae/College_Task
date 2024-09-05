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
        cout<< title<< ' '<< price<< "원 "<< pages<< " 페이지"<< endl;
    }

    const string &getTitle() const {
        return title;
    }

    bool operator==(int a) {
        if(this->price == a) return true;
        else return false;
    }
    bool operator==(string a) {
        if(this->title.compare(a) == 0) return true;
        else return false;
    }
    bool operator==(Book& b) {
        if(this->price == b.price && this->pages == b.pages && this->title.compare(b.title) == 0)
            return true;
        else
            return false;
    }
};

int main() {
    Book a("명품 C++", 30000, 500), b("고품격 C++", 30000, 500);

    // price 비교
    if(a== 30000) cout<< "정가 30000원"<< endl;

    // 책 비교
    if(a== "명품 C++") cout<< "명품 C++ 입니다."<< endl;

    // 다 비교
    if(a== b) cout<< "두 책이 같은 책입니다."<< endl;
}