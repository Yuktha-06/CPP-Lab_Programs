#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater

using namespace std;

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    // Min-heap to keep track of the 3 largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        minHeap.push(num);
        
        // If the heap grows beyond 3 elements, remove the smallest one
        if (minHeap.size() > 3) {
            minHeap.pop();
        }
    }

    // Extract the top 3 elements (they come out in ascending order)
    vector<int> top3;
    while (!minHeap.empty()) {
        top3.push_back(minHeap.top());
        minHeap.pop();
    }

    // Print from largest to smallest
    for (int i = top3.size() - 1; i >= 0; --i) {
        cout << top3[i] << (i > 0 ? " " : "");
    }
    cout << "\n";

    return 0;
}
