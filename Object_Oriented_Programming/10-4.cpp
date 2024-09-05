#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;

public:
    Person(const string &name= "", int age= 1): name(name), age(age){}
    const string &getName() const {return name;}
    int getAge() const {return age;}
};

class Student: virtual public Person {
    int score;

public:
    Student(int score= 0, const string &name= "", int age= 0): Person(name, age), score(score) {};
    int getScore() const {return score;}
};

class Worker: virtual public Person {
    int salary;

public:
    Worker(int salary= 0, const string &name= "", int age= 0): Person(name, age), salary(salary) {};
    int getSalary() const {return salary;}
};

class StudentWorker: public Student, public Worker {
public: 
    StudentWorker(const string &name, int age, int score, int salary)
    : Person(name, age), Student(score, name, age), Worker(salary, name, age) {}
};

int main() {
    StudentWorker sw("John Doe", 20, 85, 5000);
    cout << "Name: " << sw.getName() << endl;
    cout << "Age: " << sw.getAge() << endl;
    cout << "Score: " << sw.getScore() << endl;
    cout << "Salary: " << sw.getSalary() << endl;
    return 0;
}