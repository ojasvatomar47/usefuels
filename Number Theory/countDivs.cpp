#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll countDivisors(ll n)
{
    ll count = 0;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                count += 1;
            else
                count += 2;
        }
    }
    return count;
}

int main()
{
}