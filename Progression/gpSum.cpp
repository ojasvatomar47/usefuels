#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll sum_of_gp(ll a, ll r, ll n, ll MOD)
{
    if (r == 1)
    {
        return (a * n) % MOD;
    }
    ll r_n = mod_pow(r, n, MOD);
    ll sum = (a * (r_n - 1 + MOD) % MOD) % MOD;
    ll denominator = (r - 1 + MOD) % MOD;

    // Use modular inverse of denominator
    ll inv_denominator = mod_pow(denominator, MOD - 2, MOD);
    sum = (sum * inv_denominator) % MOD;

    return sum;
}

int main()
{
}