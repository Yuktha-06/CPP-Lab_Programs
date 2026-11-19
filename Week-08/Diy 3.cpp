#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base {
    int* arr;

public:
    Derived() {
        arr = new int[100];
        cout << "Memory Allocated" << endl;
    }

    ~Derived() {
        delete[] arr;
        cout << "Derived Destructor Called" << endl;
    }
};

int main() {
    Base* ptr = new Derived();

    delete ptr;

    return 0;
}
