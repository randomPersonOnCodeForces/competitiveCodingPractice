#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int, int> order;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i) {
        int key;
        cin >> key;
        order[key] = i;
    }
    for (int i = 0; i < N; ++i) {
        int key;
        cin >> key;
        arr[i] = order[key];
    }

    
    return 0;
}

/*

5
1 2 3 4 5
3 1 2 4 5

1 2 3 4 5

*/