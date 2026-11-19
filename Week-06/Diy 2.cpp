#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    int numerator, denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);

        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        cout << "Enter numerator and denominator: ";
        in >> f.numerator >> f.denominator;

        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        f.simplify();
        return in;
    }

    friend ostream& operator<<(ostream& out, Fraction f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f;

    try {
        cin >> f;
        cout << "Simplified Fraction: " << f << endl;
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
