#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int right(const vector<int>& arr, int start, int radius, int cnt)
{
    int initPos = start;
    for (int i = initPos + 1; i < arr.size(); ++i)
    {
        if (arr[initPos] + radius >= arr[i])
        {
            start = i;
            cnt++;
        }
    }
    if (initPos == start)
        return cnt;
    return right(arr, start, radius + 1, cnt);
}

int left(const vector<int>& arr, int start, int radius, int cnt)
{
    int initPos = start;
    for (int i = initPos - 1; i >= 0; --i)
    {
        if (arr[initPos] - radius <= arr[i])
        {
            start = i;
            cnt++;
        }
    }
    if (initPos == start)
        return cnt;
    return left(arr, start, radius + 1, cnt);
}

void solve(const vector<int>& arr, int start, int radius)
{
    if (start == arr.size())
        return;
    int l = 0, r = 0, rPos = start, lPos = start;
    if (start - 1 >= 0)
    {
        for (int i = start - 1; i >= 0; --i)
        {
            if (arr[start] - radius <= arr[i])
            {
                lPos = i;
                l++;
            }
        }
        if (lPos == start)
            l = 0;
        else
            l = left(arr, lPos, radius + 1, l);
    }
    if (start + 1 < arr.size())
    {
        for (int i = start + 1; i < arr.size(); ++i)
        {
            if (arr[start] + radius >= arr[i])
            {
                rPos = i;
                r++;
            }
        }
        if (rPos == start)
            r = 0;
        else
            r = right(arr, rPos, radius + 1, r);
    }
    ans = max(ans, l + r + 1);
    solve(arr, start + 1, 1);
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
    solve(arr, 0, 1);
    cout << ans;
    return 0;
}