#include <bits/stdc++.h>
using namespace std;

vector<bool> dfs(const vector<vector<int>> &adj, vector<bool> &visited, int curr) {
    visited[curr] = true;
    if (adj[curr].size() > 0 && !visited[adj[curr][0]]) {
        dfs(adj, visited, adj[curr][0]);
    }
    return visited;
}

void solve(const vector<vector<int>> &adj, int target) {
    if (target == adj.size()) {
        cout << -1;
        return;
    }
    for (int i = 1; i < adj.size(); ++i) {
        if (i == target) {
            continue;
        }
        vector<bool> visited(adj.size(), false);
        vector<bool> flag = dfs(adj, visited, i);
        if (!flag[target]) {
            solve(adj, target + 1);
            break;
        }
        if (adj[target].size() > 0) {
            cout << target;
            return;
        }
    }
}

int main() {
    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);

    int N;
    cin >> N;
    
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj.at(a).push_back(b);
    }
    
    solve(adj, 1);
    return 0;
}