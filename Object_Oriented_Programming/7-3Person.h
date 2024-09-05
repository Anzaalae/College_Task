#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
    std::string name;
public:
    Person() {name= "";}
    Person(const std::string &name) {this->name= name;}
    const std::string &getName() const {return name;}
    void setName(const std::string &name) {this->name= name;}
};

#endif