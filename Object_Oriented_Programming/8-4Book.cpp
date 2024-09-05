#include "8-4Book.h"
#include <cstring>

Book::Book(Book& b) {
    this->title= new char[strlen(b.title)+ 1];
    this->title= strcpy(this->title, b.title);
    this->price= b.price;
}

Book::Book(const char* title, int price) {
    this->title= new char[strlen(title)+ 1];
    strcpy(this->title, title);
    this->price= price;
}

Book::~Book() {
    delete [] title;
}

void Book::set(const char* title, int price) {
    delete [] this->title;
    this->title= new char[strlen(title)+ 1];
    strcpy(this->title, title);
    this->price= price;
}