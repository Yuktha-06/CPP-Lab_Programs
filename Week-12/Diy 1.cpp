#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<string, int>> items = {
        {"apple", 50},
        {"banana", 10},
        {"cherry", 30}
    };

    // Sort by the integer (second) field in ascending order
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // Print the sorted vector
    for (const auto& [name, count] : items) {
        cout << name << ": " << count << '\n';
    }

    return 0;
}
