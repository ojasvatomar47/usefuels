#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

class MathFunctions
{
public:
    ll binpowMOD(ll a, ll b)
    {
        ll ans = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                ans *= a;
                ans %= MOD;
            }
            a *= a;
            a %= MOD;
            b = b >> 1;
        }
        return ans;
    }

    ll mod(ll x)
    {
        return ((x % MOD) + MOD) % MOD;
    }

    ll add(ll a, ll b)
    {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }

    ll sub(ll a, ll b)
    {
        return ((a - b) % MOD + MOD) % MOD;
    }

    ll mult(ll a, ll b)
    {
        return ((a * b) % MOD);
    }

    ll inv(ll a)
    {
        return binpowMOD(a, MOD - 2);
    }

    ll divide(ll a, ll b)
    {
        return mult(a, inv(b));
    }

    ll nCr(ll n, ll r)
    {
        if (n < r)
            return 0;
        ll factN = factorial(n);
        ll factR = factorial(r);
        ll factNR = factorial(n - r);
        return divide(factN, mult(factR, factNR));
    }

    ll factorial(ll n)
    {
        ll res = 1;
        for (ll i = 1; i <= n; ++i)
        {
            res = mult(res, i);
        }
        return res;
    }
};

int main()
{
}