// Passed all test cases

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    unordered_map<string, int> cows = {{"Beatrice", 0}, {"Belinda", 1}, {"Bella", 2}, {"Bessie", 3}, {"Betsy", 4}, {"Blue", 5}, {"Buttercup", 6}, {"Sue", 7}};
    string names[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    int N;
    cin >> N;

    vector<vector<int>> adj(8);
    for (int i = 0; i < N; ++i)
    {
        vector<string> str(6, "");
        for (int j = 0; j < 6; ++j)
        {
            cin >> str[j];
        }
        adj.at(cows[str[0]]).push_back(cows[str[5]]);
        adj.at(cows[str[5]]).push_back(cows[str[0]]);
    }
    for (int i = 0; i < 8; ++i)
    {
        if (adj[i].size() == 0)
        {
            continue;
        }
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(8, false);
    vector<int> sortedOrder;
    for (int i = 0; i < 8; ++i) {
        if (!visited[i] && adj[i].size() <= 1) {
            int curr = i;
            while (curr != -1) {
                sortedOrder.push_back(curr);
                visited[curr] = true;
                int next = -1;
                for (int j = 0; j < adj[curr].size(); ++j) {
                    if (!visited[adj[curr][j]]) {
                        next = adj[curr][j];
                        break;
                    }
                }
                curr = next;
            }
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        cout << names[sortedOrder[i]] << endl;
    }
    return 0;
}