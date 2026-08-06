#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int right(vector<int> arr, int start, int radius, int cnt)
{
    if (start >= arr.size()) {
        return cnt;
    }
    for (int i = 1; i <= radius && start + i < arr.size(); ++i) {
        if (arr[start] + i >= arr[start + i])
        {
            cnt++;
        }
    }
    return right(arr, start + radius, radius + 1, cnt);
}

int left(vector<int> arr, int start, int radius, int cnt)
{
    if (start < 0) {
        return cnt;
    }
    for (int i = 1; i <= radius && start - i >= 0; ++i) {
        if (arr[start] - i <= arr[start - i])
        {
            cnt++;
        }
    }
    return right(arr, start - radius, radius + 1, cnt);
}

void solve(vector<int> arr, int start, int radius, int cnt)
{
    if (start == arr.size())
        return;
    int l = 0, r = 0;
    if (start - radius >= 0 && arr[start] - radius <= arr[start - 1])
    {
        l = left(arr, start - radius, radius + 1, cnt++);
    }
    if (start + radius < arr.size() && arr[start] + radius >= arr[start + 1])
    {
        r = right(arr, start + radius, radius + 1, cnt++);
    }
    ans = max(ans, l + r);
    solve(arr, start + 1, 1, 0);
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    solve(arr, 0, 1, 0);
    cout << ans;
    return 0;
}