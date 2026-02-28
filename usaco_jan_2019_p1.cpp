#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> data, int pebbleStartShell)
{
    int currPebbleLocation = pebbleStartShell, cnt = 0;
    std::string swap(3, '-');
    swap[currPebbleLocation - 1] = 'p';
    for (int i = 0; i < data.size(); ++i)
    {
        int a = data[i][0], b = data[i][1], guess = data[i][2];
        if (a == currPebbleLocation)
        {
            swap[a - 1] = '-';
            swap[b - 1] = 'p';
            currPebbleLocation = b;
        }
        else if (b == currPebbleLocation)
        {
            swap[b - 1] = '-';
            swap[a - 1] = 'p';
            currPebbleLocation = a;
        }
        if (swap[guess - 1] == 'p')
            cnt++;
    }
    return cnt;
}

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, ans0 = 0, ans1 = 0, cnt0 = 0, cnt1 = 0;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i)
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    int ans = 0;
    for (int i = 1; i <= 3; ++i)
    {
        ans = max(ans, solve(data, i));
    }
    cout << ans << endl;
    return 0;
}