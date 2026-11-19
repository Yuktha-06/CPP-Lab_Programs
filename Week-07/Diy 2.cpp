#include <iostream>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string n) {
        name = n;
        cout << "Shape Constructor Called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(string n, int s) : Shape(n) {
        sides = s;
        cout << "Polygon Constructor Called" << endl;
    }
};

class Rectangle : public Polygon {
    float area;

public:
    Rectangle(string n, int s, float a) : Polygon(n, s) {
        area = a;
        cout << "Rectangle Constructor Called" << endl;
    }

    void display() {
        cout << "\nShape: " << name << endl;
        cout << "Number of Sides: " << sides << endl;
        cout << "Area: " << area << endl;
    }
};

int main() {
    Rectangle r("Rectangle", 4, 50.5);

    r.display();

    return 0;
}
