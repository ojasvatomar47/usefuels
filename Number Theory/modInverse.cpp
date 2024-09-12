#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modInv(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    if (g != 1)
    {
        // Modular inverse doesn't exist if gcd(a, m) != 1
        return -1;
    }
    else
    {
        return (x % m + m) % m;
    }
}

// Fermat's theorem
ll modInverse(ll a, ll mod)
{
    ll res = 1;
    ll exponent = mod - 2;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exponent /= 2;
    }
    return res;
}

int main()
{
}