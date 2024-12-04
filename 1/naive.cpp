#include <iostream>
#include <string>
using namespace std;

void searchPattern(string text, string pattern) {
    int textLength = text.size(), patternLength = pattern.size();
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j = 0;
        while (j < patternLength && text[i + j] == pattern[j]) j++;
        if (j == patternLength) cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    searchPattern(text, pattern);
    return 0;
}
