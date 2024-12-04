#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assignMiceToHoles(vector<int>& mice, vector<int>& holes) {
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int maxTime = 0;
    for (int i = 0; i < mice.size(); i++) {
        maxTime = max(maxTime, abs(mice[i] - holes[i]));
    }
    return maxTime;
}

int main() {
    int n;
    cin >> n;
    vector<int> mice(n), holes(n);
    for (int i = 0; i < n; i++) cin >> mice[i];
    for (int i = 0; i < n; i++) cin >> holes[i];
    cout << assignMiceToHoles(mice, holes) << endl;
    return 0;
}
