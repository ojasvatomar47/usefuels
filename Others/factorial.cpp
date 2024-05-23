#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll MOD = 1e9 + 7;

// Factorial function with modulo
ll factorialMod(ll n, ll mod)
{
    ll result = 1;
    for (ll i = 1; i <= n; ++i)
    {
        result = (result * i) % mod;
    }
    return result;
}

const ll MAX = 2e5 + 7;
vector<ll> fact(MAX);

ll multiMOD(ll a, ll b)
{
    return ((a * b) % MOD);
}

void computeFactorials()
{
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
        fact[i] = multiMOD(i, fact[i - 1]);
}

int main()
{
    ll n = 5; // Example number
    cout << "Factorial of " << n << " with modulo " << MOD << " is " << factorialMod(n, MOD) << endl;
    return 0;
}
