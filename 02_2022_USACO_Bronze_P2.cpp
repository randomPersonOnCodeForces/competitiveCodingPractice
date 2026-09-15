// Passed all test cases

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N;
    cin >> N;

    string A;
    cin >> A;

    string B;
    cin >> B;

    int i = 0, ans = 0;
    bool flag = false;
    while (i < N) {
        if (A[i] != B[i] && flag == false) {
            ans++;
            flag = true;
        }
        else if (flag == true && A[i] == B[i]) {
            flag = false;
        }
        i++;
    }
    cout << ans;
    return 0;
}