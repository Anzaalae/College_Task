#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "11-3Employee.h"

class FullTimeEmployee: public Employee{
    int salary;
pubilc:
    FullTimeEmployee(int id, string name, int salary)
        :Employee(id, name), salary(salary){}
    int calculatePay();
};

#endif