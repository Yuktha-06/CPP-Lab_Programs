#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* arr;
    int size;

public:
    SafeArray(int s) {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }

        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    SafeArray a(5);

    try {
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;

        cout << "Array Elements:" << endl;

        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }

        cout << endl;

        cout << "Accessing index 7: " << a[7] << endl;
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
