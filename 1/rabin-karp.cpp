#include <iostream>
#include <string>
using namespace std;

const int base = 256, prime = 101;

void rabinKarp(string text, string pattern) {
    int textLength = text.size(), patternLength = pattern.size();
    int hashText = 0, hashPattern = 0, power = 1;
    for (int i = 0; i < patternLength - 1; i++) power = (power * base) % prime;
    for (int i = 0; i < patternLength; i++) {
        hashPattern = (base * hashPattern + pattern[i]) % prime;
        hashText = (base * hashText + text[i]) % prime;
    }
    for (int i = 0; i <= textLength - patternLength; i++) {
        if (hashPattern == hashText) {
            int j = 0;
            while (j < patternLength && text[i + j] == pattern[j]) j++;
            if (j == patternLength) cout << "Pattern found at index " << i << endl;
        }
        if (i < textLength - patternLength) {
            hashText = (base * (hashText - text[i] * power) + text[i + patternLength]) % prime;
            if (hashText < 0) hashText += prime;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    rabinKarp(text, pattern);
    return 0;
}
