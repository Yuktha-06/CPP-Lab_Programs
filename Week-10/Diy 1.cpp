#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nums.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return 1;
    }

    int num, count = 0;
    int sum = 0, min, max;

    while (file >> num) {
        if (count == 0) {
            min = max = num;
        }

        sum += num;
        count++;

        if (num < min)
            min = num;

        if (num > max)
            max = num;
    }

    file.close();

    if (count == 0) {
        cout << "File is empty!" << endl;
    }
    else {
        cout << "Count: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    }

    return 0;
}
