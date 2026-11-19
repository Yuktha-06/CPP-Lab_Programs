#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // --- Testing with int ---
    int x = 10, y = 20;
    cout << "Before swap (int): x = " << x << ", y = " << y << endl;
    swapVals(x, y);
    cout << "After swap (int):  x = " << x << ", y = " << y << endl;

    int intArr[] = {45, 12, 89, 33, 67};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Max in int array: " << findMax(intArr, intSize) << "\n\n";

    // --- Testing with double ---
    double d1 = 3.14, d2 = 9.81;
    cout << "Before swap (double): d1 = " << d1 << ", d2 = " << d2 << endl;
    swapVals(d1, d2);
    cout << "After swap (double):  d1 = " << d1 << ", d2 = " << d2 << endl;

    double doubleArr[] = {12.5, 45.8, 3.9, 99.1, 56.4};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Max in double array: " << findMax(doubleArr, doubleSize) << endl;

    return 0;
}
