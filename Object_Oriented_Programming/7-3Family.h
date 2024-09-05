#ifndef FAMILY_H
#define FAMILY_H

#include "Person.h"

class Family {
    std::string name;
    Person* p;
    int size;
public:
    Family(const std::string &name, int size);
    ~Family();

    void setName(int index, const std::string &name);

    void show() const;
};

#endif