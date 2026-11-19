#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    // 1. Product of all elements
    // Note: Initial value is 1 (multiplicative identity)
    long long product = std::accumulate(nums.begin(), nums.end(), 1LL, 
        [](long long acc, int val) {
            return acc * val;
        });

    // 2. Sum of only the even elements
    // Note: Initial value is 0 (additive identity)
    int even_sum = std::accumulate(nums.begin(), nums.end(), 0, 
        [](int acc, int val) {
            return (val % 2 == 0) ? (acc + val) : acc;
        });

    std::cout << "Product of all elements: " << product << "\n"; // Output: 720
    std::cout << "Sum of even elements: " << even_sum << "\n";    // Output: 12

    return 0;
}
