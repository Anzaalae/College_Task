#include "11-3FullTimeEmployee.h"
#include "11-3PartTimeEmployee.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

Employee *createEmployee() {
    int type, int id;
    string name;
    cout<< "1. Full Time"<< endl;
    cout<< "2. Part Time"<< endl;
    cout<< "������� ������ �����ϼ��� >> ";
    cin>> type;
    if(type < 1 || type > 2) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::stramsize>::max(), '\n');
        throw"�߸��� �����Դϴ�.";
    }
    cout<< "����� ���̵� �Է�: ";
    cin>> id;
    cin.ignore();
    cout<< "����� �̸� �Է� ";
    getline(cin, name);

    switch(type) {
    case 1:
        int salary;
        cout<< "���� �Է�: ";
        cin>> salary;
        return new FullTimeEmployee(id, name, salary);
    default:
        int hourlyWage, hoursWorked;
        cout<< "�ñ� �Է�: ";
        cin>> hourlyWage;
        cout<< "�ٷ� �ð� �Է�: ";
        cin>> hourlyWorked;
        return new partTimeEmployee(id, name, hourlyWage, hoursWorked);    
    }
}

int main() {
    const int NUM_OF_WORKERS = 4;
    Employee * workers[NUM_OF_WORKERS];
    int i= 0;
    while(i< NUM_OF_WORKERS) {
        try {
            workers[i]= createEmployee();
            i++;
        } catch(const char *err) {
            cerr<< err<< endl;
        }
    }

    for(int i= 0; i< NUM_OF_WORKERS; i++) {
        cout<< endl;
        workers[i]->printInfo(cout);
        cout<< "�̹��� �ݿ��� "<< workers[i]->calculatePay()<<"���Դϴ�."\<< endl;
    }

    for(int i= 0; i< NUM_OF_WORKERS; i++) delete workers[i];
}