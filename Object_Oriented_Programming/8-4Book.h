#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book {
    char* title;
    int price;
public:
    Book(Book& b);// 복사 생성자 선언
    Book(const char* title, int price);
    ~Book();
    void set(const char* title, int price);
    void show() const {std::cout<< title<<' '<<price<<"원"<<std::endl;}
};

#endif