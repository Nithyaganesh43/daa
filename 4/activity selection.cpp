#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size(), count = 1, last = 0;
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; i++) activities[i] = {finish[i], start[i]};
    sort(activities.begin(), activities.end());
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= activities[last].first) {
            count++;
            last = i;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> start(n), finish(n);
    for (int i = 0; i < n; i++) cin >> start[i] >> finish[i];
    cout << activitySelection(start, finish) << endl;
    return 0;
}
