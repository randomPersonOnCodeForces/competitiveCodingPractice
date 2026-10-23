#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
    int N;
    cin >> N;
    vector<ull> ans;
    for (int i = 0; i < N; ++i)
    {
        ull curr, target;
        cin >> curr >> target;
        ull cnt = 0;
        while (curr > target) {
            if (curr % 2 == 1) {
                cnt += 2;
                curr = (curr + 1) / 2;
            }
            else {
                cnt++;
                curr /= 2;
            }
        }
        if (curr == target) {
            ans.push_back(cnt);
            continue;
        }
        vector<ull> targetRem;
        targetRem.push_back(target);
        for (int i = 0; i < log2(target); ++i) {
            targetRem.push_back((target >> i));
        }
        ull minOps = targetRem[0] - curr, inc = 0;
        while (curr > 1) {
            for (int i = 0; i < targetRem.size(); ++i) {
                if (targetRem[i] < curr) {
                    inc += 1 + (curr & 1);
                    curr = (curr + (curr & 1)) / 2;
                    break;
                }
                if (minOps > inc + targetRem[i] - curr + i) {
                    minOps = inc + targetRem[i] - curr + i;
                }
            }
        }
        ans.push_back(cnt + minOps);
    }
    for (int i = 0; i < N; ++i)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}