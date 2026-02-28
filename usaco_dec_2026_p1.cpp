#include <iostream>
#include <bits.h>
// #include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll a, b, ca, cb, fa, x, b_addition, min_a_addition;
        cin >> a >> b >> ca >> cb >> fa;
        ll a_req = fa - a - (b * ca) / cb, b_rem = b % cb;
        if (a_req <= 0)
            cout << 0 << endl;
        else
        {
            // Calculate max b to satisfy a
            x = (a_req * cb) / ca - b_rem;
            if ((a_req * cb) % ca > 0)
                x++;
            if (ca > cb)
            {
                b_addition = cb - 1;
                min_a_addition = 
            }
            else
            {
                // Worst case scenario:(b_addition + b_rem) % cb == cb - 1
                
                b_addition = x - 1;
                min_a_addition = x - b_addition + ((b_addition + b_rem)) / cb * ca;
            }
            if (a_req > min_a_addition)
                x++;
            cout << x << endl;
        }
    }
    return 0;
}