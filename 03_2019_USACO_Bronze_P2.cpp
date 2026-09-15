#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

vector<bool> dfs(vector<bool> &visited, int &curr) {
    if (!visited[curr]) {
        visited[curr] = true;
        for (int i = 0; i < adj[curr].size(); ++i) {
            if (!visited[adj[curr][i]]) {
                dfs(visited, adj[curr][i]);
            }
        }
    }
    return visited;
}

int solve(int target) {
    if (target == adj.size()) {
        return -1;
    }
    for (int i = 0; i < adj.size(); ++i) {
        if (i == target) {
            continue;
        }
        vector<bool> visited(adj.size(), false);
        vector<bool> flag = dfs(visited, i);
        if (!flag[target]) {
            solve(target + 1);
            break;
        }
    }
    return target;
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj.at(a).push_back(b);
    }
    
    cout << solve(0);
    return 0;
}