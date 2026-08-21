// Passed all test cases

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int N;
    cin >> N;

    unordered_map<string, int> milkBuckets = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        int a;
        cin >> a;
        milkBuckets[str] += a;
    }
    vector<int> milkBucketsRanking;
    map<int, string> ranking;
    for (const auto& [name, buckets] : milkBuckets) {
        milkBucketsRanking.push_back(buckets);
        ranking[buckets] = name;
    }
    sort(milkBucketsRanking.begin(), milkBucketsRanking.end());

    int secondPlaceInd = 8;
    bool flag = false;
    for (int i = 0; i < milkBucketsRanking.size(); ++i) {
        if (milkBucketsRanking[0] < milkBucketsRanking[i] && !flag) {
            flag = true;
            secondPlaceInd = i;
        }
        else if (secondPlaceInd != 8 && milkBucketsRanking[secondPlaceInd] == milkBucketsRanking[i] && flag) {
            cout << "Tie";
            return 0;
        }
    }
    if (secondPlaceInd == 8) {
        cout << "Tie";
        return 0;
    }
    cout << ranking[milkBucketsRanking[secondPlaceInd]];
    return 0;
}