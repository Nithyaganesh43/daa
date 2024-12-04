#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computeLPS(string pattern, vector<int>& lps) {
    int length = 0, i = 1;
    lps[0] = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) lps[i++] = ++length;
        else if (length != 0) length = lps[length - 1];
        else lps[i++] = 0;
    }
}

void kmpSearch(string text, string pattern) {
    int textLength = text.size(), patternLength = pattern.size();
    vector<int> lps(patternLength);
    computeLPS(pattern, lps);
    int i = 0, j = 0;
    while (i < textLength) {
        if (text[i] == pattern[j]) i++, j++;
        if (j == patternLength) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < textLength && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    kmpSearch(text, pattern);
    return 0;
}
