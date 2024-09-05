#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "11-3Employee.h"
class PartTimeEmployee: public Employee{
    int hourlyWage, hourlsWorked;
pubilc:
    FullTimeEmployee(int id, string name, int hourlyWage, int hoursWorked)
        :Employee(id, name), hourlyWage(hourlyWage), hoursWorked(hoursyWorked){}
    int calculatePay();
};

#endif