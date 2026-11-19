#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "Math Error";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Division by Zero Error";
    }
};

int main() {
    try {
        throw DivideByZero();
    }
    catch (const MathError& e) {
        cout << "Caught: " << e.what() << endl;
    }
    catch (const DivideByZero& e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
