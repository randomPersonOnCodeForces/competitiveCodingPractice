#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    cin >> N;

    string str;
    cin >> str;

    for (int j = 1; j <= N; ++j)
    {
        int segLen = j, i = 0;
        string temp;
        unordered_set<string> uniqueSeg;
        while (i < N)
        {
            for (int k = 0; k < segLen; ++k)
            {
                temp += str[i + k];
            }
            uniqueSeg.insert(temp);
            temp.clear();
            i++;
        }
        if (uniqueSeg.size() == str.length())
        {
            cout << segLen;
            return 0;
        }
    }
    cout << N;
    return 0;
}
