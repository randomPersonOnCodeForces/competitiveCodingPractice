// Passed all test cases
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int misplacedCowInd = -1;
    bool left = true, right = true;
    for (int i = 0; i < N; ++i) {
        if ((i == N - 1 && arr[i] < arr[i - 1]) || (0 < i && i < N - 1 && arr[i - 1] > arr[i] && arr[i - 1] <= arr[i + 1])) {
            misplacedCowInd = i;
            right = false;
            break;
        }
        else if ((i == 0 && arr[i] > arr[i + 1]) || (0 < i && i < N - 1 && arr[i + 1] < arr[i] && arr[i - 1] <= arr[i + 1])) {
            misplacedCowInd = i;
            left = false;
            break;
        }
    }
    if (misplacedCowInd == -1) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    if (left) {
        bool flag = false;
        for (int i = misplacedCowInd - 1; i >= 0 && arr[misplacedCowInd] < arr[i]; --i) {
            if (!flag && arr[misplacedCowInd] < arr[i]) {
                cnt++;
            }
            flag = false;
            if (i > 0 && arr[i - 1] == arr[i]) {
                flag = true;
            }
        }
    }
    else if (right) {
        bool flag = false;
        for (int i = misplacedCowInd + 1; i < N && arr[misplacedCowInd] > arr[i]; ++i) {
            if (!flag && arr[misplacedCowInd] > arr[i]) {
                cnt++;
            }
            flag = false;
            if (i < N - 1 && arr[i + 1] == arr[i]) {
                flag = true;
            }
        }
    }
    cout << cnt;
    return 0;
}