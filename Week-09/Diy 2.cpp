#include <iostream>
#include <exception>
using namespace std;

class StackOverflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow!";
    }
};

class StackUnderflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow!";
    }
};

class Stack {
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 4)
            throw StackOverflow();

        arr[++top] = x;
        cout << x << " pushed" << endl;
    }

    void pop() {
        if (top == -1)
            throw StackUnderflow();

        cout << arr[top--] << " popped" << endl;
    }

    void display() {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
    }
    catch (const StackOverflow& e) {
        cout << e.what() << endl;
    }

    s.display();

    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (const StackUnderflow& e) {
        cout << e.what() << endl;
    }

    return 0;
}
