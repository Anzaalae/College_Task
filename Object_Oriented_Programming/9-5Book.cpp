#include "9-5book.h"
#include <iostream>

const std::string& Book::getTitle() const{
    return this->title;
}

bool Book::operator!() const{
    if(this->price== 0) return true;
    else return false;
}

Book& Book::operator++() {
    this->price= this->price* 1.1;
}

Book Book::operator++(int) {
    Book temp(*this);
    this->price= this->price* 1.1;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
        return os << "å�̸�: "<<book.title << ", ����: " << book.price << ", ��������: " << book.pages;
}