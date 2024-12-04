#include <iostream>
#include <vector>
#include <string>
using namespace std;

string preprocessString(string str) {
    string modified = "#";
    for (char c : str) modified += c, modified += "#";
    return modified;
}

int findLongestPalindrome(string str) {
    string processed = preprocessString(str);
    int size = processed.size(), center = 0, right = 0, maxLength = 0;
    vector<int> palindrome(size, 0);
    for (int i = 0; i < size; i++) {
        if (i < right) palindrome[i] = min(right - i, palindrome[2 * center - i]);
        while (i + 1 + palindrome[i] < size && i - 1 - palindrome[i] >= 0 && 
               processed[i + 1 + palindrome[i]] == processed[i - 1 - palindrome[i]]) palindrome[i]++;
        if (i + palindrome[i] > right) center = i, right = i + palindrome[i];
        maxLength = max(maxLength, palindrome[i]);
    }
    return maxLength;
}

int main() {
    string str;
    cin >> str;
    cout << findLongestPalindrome(str) << endl;
    return 0;
}
