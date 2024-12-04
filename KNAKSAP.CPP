#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0); 

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter the number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Maximum value in knapsack: " << knapsack(W, weights, values, n) << endl;
    return 0;
}
