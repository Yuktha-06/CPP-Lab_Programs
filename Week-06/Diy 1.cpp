#include <iostream>
using namespace std;

class Money {
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        rupees = r + p / 100;
        paise = p % 100;
    }

    Money operator+(Money m) {
        Money temp;
        temp.rupees = rupees + m.rupees;
        temp.paise = paise + m.paise;

        if (temp.paise >= 100) {
            temp.rupees++;
            temp.paise -= 100;
        }

        return temp;
    }

    Money operator-(Money m) {
        Money temp;
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;

        int diff = total1 - total2;

        temp.rupees = diff / 100;
        temp.paise = diff % 100;

        return temp;
    }

    void display() {
        cout << rupees << " Rupees " << paise << " Paise" << endl;
    }
};

int main() {
    Money m1(10, 80);
    Money m2(5, 50);

    Money m3 = m1 + m2;
    Money m4 = m1 - m2;

    cout << "Addition: ";
    m3.display();

    cout << "Subtraction: ";
    m4.display();

    return 0;
}
