#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ostream>

class Book {
    std::string title;
    int price;
    int pages;

public:
    Book(const std::string &title, int price, int pages): title(title), price(price), pages(pages) {}
    const std::string& getTitle()const ;
    bool operator!() const;
    Book& operator++();
    Book operator++(int);

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif