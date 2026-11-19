#include <iostream>
#include <memory>
using namespace std;

class Box {
    int w, h, d;

public:
    Box(int w, int h, int d) : w(w), h(h), d(d) {}

    Box() : Box(1, 1, 1) {}

    Box(int s) : Box(s, s, s) {}

    int volume() const {
        return w * h * d;
    }
};

int main() {
    unique_ptr<Box> a = make_unique<Box>();
    unique_ptr<Box> b = make_unique<Box>(3);
    unique_ptr<Box> c = make_unique<Box>(2, 3, 4);

    cout << a->volume() << " "
         << b->volume() << " "
         << c->volume() << endl;

    return 0;
}
