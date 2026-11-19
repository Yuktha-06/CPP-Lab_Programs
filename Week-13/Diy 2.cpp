#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Base class
class Shape {
public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

// Circle class
class Circle : public Shape {
    float r;

public:
    Circle(float r) {
        this->r = r;
    }

    void area() override {
        cout << "Area of Circle: " << 3.14 * r * r << endl;
    }
};

// Rectangle class
class Rectangle : public Shape {
    float l, b;

public:
    Rectangle(float l, float b) {
        this->l = l;
        this->b = b;
    }

    void area() override {
        cout << "Area of Rectangle: " << l * b << endl;
    }
};

// Triangle class
class Triangle : public Shape {
    float b, h;

public:
    Triangle(float b, float h) {
        this->b = b;
        this->h = h;
    }

    void area() override {
        cout << "Area of Triangle: " << 0.5 * b * h << endl;
    }
};

int main() {

    vector<unique_ptr<Shape>> shapes;
    string choice;

    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        cout << "\nEnter shape name (circle/rectangle/triangle): ";
        cin >> choice;

        if (choice == "circle") {
            float r;
            cout << "Enter radius: ";
            cin >> r;

            shapes.push_back(make_unique<Circle>(r));
        }

        else if (choice == "rectangle") {
            float l, b;
            cout << "Enter length and breadth: ";
            cin >> l >> b;

            shapes.push_back(make_unique<Rectangle>(l, b));
        }

        else if (choice == "triangle") {
            float b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;

            shapes.push_back(make_unique<Triangle>(b, h));
        }

        else {
            cout << "Invalid shape name!" << endl;
        }
    }

    cout << "\n--- Shape Areas ---\n";

    for (auto &s : shapes) {
        s->area();
    }

    return 0;
}
