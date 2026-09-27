// Passed all test cases

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<int> l(4, 0), f(4, 0);
    cin >> l[0] >> l[1] >> l[2] >> l[3];
    cin >> f[0] >> f[1] >> f[2] >> f[3];
    int ans = (l[3] - l[1]) * (l[2] - l[0]);
    if (l[0] >= f[0] && l[2] <= f[2] && l[1] >= f[1] && l[3] <= f[3]) {
        cout << 0;
        return 0;
    }
    else if (l[0] >= f[0] && l[2] <= f[2]) {
        if (l[1] <= f[1] && l[3] <= f[3] && l[3] > f[1]) {
            ans = (l[2] - l[0]) * (f[1] - l[1]);
        }
        else if (l[1] >= f[1] && l[3] >= f[3] && f[3] > l[1]) {
            ans = (l[2] - l[0]) * (l[3] - f[3]);
        }
    }
    else if (l[1] >= f[1] && l[3] <= f[3]) {
        if (l[0] <= f[0] && l[2] <= f[2] && l[2] > f[0]) {
            ans = (l[3] - l[1]) * (f[0] - l[0]);
        }
        else if (l[0] >= f[0] && l[2] >= f[2] && l[0] < f[2]) {
            ans = (l[3] - l[1]) * (l[2] - f[2]);
        }
    }
    cout << abs(ans);
    return 0;
}