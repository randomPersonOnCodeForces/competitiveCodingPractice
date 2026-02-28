#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<ll> bucketCapacity(3, 0), milkAmount(3, 0);

    for (int i = 0; i < 3; ++i)
        cin >> bucketCapacity[i] >> milkAmount[i];
    for (int i = 0; i < 100; ++i)
    {
        ll milkA = milkAmount[i % 3], milkB = milkAmount[(i + 1) % 3], capA = bucketCapacity[i % 3], capB = bucketCapacity[(i + 1) % 3], prev = milkB;
        milkB += min(capB - milkB, milkA), milkA -= milkB - prev;
        milkAmount[i % 3] = milkA, milkAmount[(i + 1) % 3] = milkB;
        if (i == 99)
        {
            cout << milkAmount[0] << '\n' << milkAmount[1] << '\n' << milkAmount[2] << endl;
        }
    }
    return 0;
}