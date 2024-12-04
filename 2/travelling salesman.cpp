#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calculateCost(vector<vector<int>>& cost, vector<int>& path) {
    int total = 0, n = path.size();
    for (int i = 0; i < n - 1; i++) total += cost[path[i]][path[i + 1]];
    total += cost[path[n - 1]][path[0]];
    return total;
}

int tspBruteForce(vector<vector<int>>& cost) {
    int n = cost.size(), minCost = INT_MAX;
    vector<int> path(n);
    for (int i = 0; i < n; i++) path[i] = i;
    do {
        minCost = min(minCost, calculateCost(cost, path));
    } while (next_permutation(path.begin(), path.end()));
    return minCost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> cost[i][j];
    cout << tspBruteForce(cost) << endl;
    return 0;
}
