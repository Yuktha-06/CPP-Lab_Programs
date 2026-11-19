#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[100];
    int n = 0;

    ofstream out("students.txt");

    out << "Rahul 85\n";
    out << "Aman 92\n";
    out << "Sahil 95\n";
    out << "Priya 88\n";

    out.close();

    ifstream in("students.txt");

    while (in >> s[n].name >> s[n].marks) {
        n++;
    }

    in.close();

    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    cout << "Student Records:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Name: " << s[i].name
             << " Marks: " << s[i].marks << endl;
    }

    if (n > 0) {
        cout << "\nTopper Details:" << endl;
        cout << "Name: " << s[topper].name << endl;
        cout << "Marks: " << s[topper].marks << endl;
    }

    return 0;
}
