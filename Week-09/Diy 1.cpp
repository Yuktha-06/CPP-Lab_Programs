#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance! Withdrawal Failed.";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }

    void display() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    try {
        account.display();

        account.deposit(1000);

        account.withdraw(2000);

        account.withdraw(6000);

    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    account.display();

    return 0;
}
