#include <iostream>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
        cout << "Person Constructor Called" << endl;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(string n, int r) : Person(n) {
        rollNo = r;
        cout << "Student Constructor Called" << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(string n, int e) : Person(n) {
        empId = e;
        cout << "Employee Constructor Called" << endl;
    }
};

class TA : public Student, public Employee {
public:
    TA(string n, int r, int e)
        : Person(n), Student(n, r), Employee(n, e) {
        cout << "TA Constructor Called" << endl;
    }

    void display() {
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Employee ID: " << empId << endl;
    }
};

int main() {
    TA t("Sahil", 25, 101);

    cout << "\nTA Details" << endl;
    t.display();

    return 0;
}
