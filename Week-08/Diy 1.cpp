#include <iostream>
using namespace std;

class Account {
protected:
    float balance;

public:
    Account(float b) {
        balance = b;
    }

    virtual void calculateInterest() = 0;

    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(float b) : Account(b) {}

    void calculateInterest() override {
        cout << "Savings Account Interest: "
             << balance * 6 / 100 << endl;
    }
};

class Current : public Account {
public:
    Current(float b) : Account(b) {}

    void calculateInterest() override {
        cout << "Current Account Interest: "
             << balance * 3 / 100 << endl;
    }
};

int main() {
    Savings s(10000);
    Current c(20000);

    Account* acc[2];

    acc[0] = &s;
    acc[1] = &c;

    for (int i = 0; i < 2; i++) {
        acc[i]->calculateInterest();
    }

    return 0;
}
