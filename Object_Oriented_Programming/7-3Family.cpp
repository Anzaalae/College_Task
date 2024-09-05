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
    std::cout<< this->name<< " ������ ������ ���� "<< size<< "�� �Դϴ�.\n";
    for(int i= 0; i< this->size; i++) {
        std::cout<< p[i].getName() <<", ";
    }
}