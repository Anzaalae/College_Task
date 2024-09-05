#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    int id;
    string name;
public:
    Employee(int id, string name): id(id), name(name){};
    virtual ~Employee() {}
    virtual int calculatePay()= 0;
}

#endif