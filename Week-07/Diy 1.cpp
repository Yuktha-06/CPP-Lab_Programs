#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(string n, int i, int t) : Employee(n, i) {
        teamSize = t;
    }

    void display() {
        cout << "Manager Details" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(string n, int i, string s) : Employee(n, i) {
        skill = s;
    }

    void display() {
        cout << "\nEngineer Details" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Rahul", 101, 10);
    Engineer e("Aman", 102, "Verilog");

    m.display();
    e.display();

    return 0;
}
