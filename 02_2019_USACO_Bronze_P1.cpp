// Passed all test cases

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<ll> cows(3, 0);
    cin >> cows[0] >> cows[1] >> cows[2];
    sort(cows.begin(), cows.end());
    vector<ll> maxMove = cows;

    if (cows[1] - cows[0] == 1 && cows[2] - cows[1] == 1)
    {
        cout << 0 << '\n'
             << 0;
        return 0;
    }

    int ans = max(cows[1] - cows[0] - 1, cows[2] - cows[1] - 1);
    if (cows[1] - cows[0] == 2 || cows[2] - cows[1] == 2)
    {
        cout << 1 << '\n'
             << ans;
    }
    else
    {
        cout << 2 << '\n'
             << ans;
    }
    return 0;
}