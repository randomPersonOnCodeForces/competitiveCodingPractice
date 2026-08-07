// Passed all test cases

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N, {0, 0});
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    int ans = arr[0].first + arr[0].second;
    for (int i = 1; i < N; ++i) {
        ans = max(arr[i].first, ans) + arr[i].second;
    }
    cout << ans;
    return 0;
}