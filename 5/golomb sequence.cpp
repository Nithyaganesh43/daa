#include <iostream>
#include <vector>
using namespace std;

vector<int> golombSequence(int n) {
    vector<int> seq(n + 1);
    seq[1] = 1;
    for (int i = 2; i <= n; i++) {
        seq[i] = 1 + seq[i - seq[seq[i - 1]]];
    }
    return seq;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq = golombSequence(n);
    for (int i = 1; i <= n; i++) cout << seq[i] << " ";
    cout << endl;
    return 0;
}
