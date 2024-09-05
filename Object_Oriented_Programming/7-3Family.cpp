#include "Family.h"

Family::Family(const std::string &name, int size) {
    this->name= name;
    this->size= size;
    this->p = new Person[this->size];
}

Family::~Family() {
    delete [] p;
}

void Family::setName(int index, const std::string &name) {
    p[index].setName(name);
}

void Family::show() const{
    std::cout<< this->name<< " 가족은 다음과 같이 "<< size<< "명 입니다.\n";
    for(int i= 0; i< this->size; i++) {
        std::cout<< p[i].getName() <<", ";
    }
}