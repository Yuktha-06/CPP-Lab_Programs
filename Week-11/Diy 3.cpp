#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> wordCount;
    string word;

    cout << "Enter words (press Ctrl+D on Linux/Mac or Ctrl+Z then Enter on Windows to finish):\n";

    // Read words until End-Of-File (EOF)
    while (cin >> word) {
        wordCount[word]++;
    }

    // Handle empty input edge case
    if (wordCount.empty()) {
        cout << "No words were entered.\n";
        return 0;
    }

    cout << "\nWord Frequencies:\n";
    string mostFrequentWord;
    int maxCount = 0;

    // Print each word with its count and track the highest frequency
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << '\n';

        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    cout << "\nMost frequent word: \"" << mostFrequentWord 
         << "\" (appeared " << maxCount << " times)\n";

    return 0;
}
