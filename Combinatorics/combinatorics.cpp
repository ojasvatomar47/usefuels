#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 998244353;

ll binExpoMOD(ll a, ll b)
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

const ll MAX = 2e5 + 7;
vector<ll> fact(MAX);

ll addMOD(ll x, ll y)
{
    return (x + y) % MOD;
}

ll subMOD(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll multiMOD(ll x, ll y)
{
    return ((x * y) % MOD);
}

ll invMOD(ll x)
{
    return binExpoMOD(x, MOD - 2);
}

ll divMOD(ll x, ll y)
{
    return multiMOD(x, invMOD(y));
}

ll nCr(ll n, ll r)
{
    if (n < r)
        return 0;
    return divMOD(fact[n], multiMOD(fact[r], fact[n - r]));
}

void computeFactorials()
{
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
        fact[i] = multiMOD(i, fact[i - 1]);
}

int main()
{
}