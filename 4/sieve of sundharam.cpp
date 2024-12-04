#include <iostream>
#include <vector>
using namespace std;

void sieveOfSundaram(int n) {
    int m = (n - 1) / 2;
    vector<bool> marked(m + 1, false);
    for (int i = 1; i <= m; i++) {
        for (int j = i; i + j + 2 * i * j <= m; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }
    if (n > 2) cout << 2 << " ";
    for (int i = 1; i <= m; i++) {
        if (!marked[i]) cout << 2 * i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    sieveOfSundaram(n);
    return 0;
}
