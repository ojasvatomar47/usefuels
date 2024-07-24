#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;

const long long int MOD = 1e9 + 7;

vector<vector<ll>> prefSum(const vector<vector<ll>> &v)
{
    ll n = v.size();
    ll m = v[0].size();

    vector<vector<ll>> pref(n, vector<ll>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ll current = v[i][j];
            if (i > 0)
                current += pref[i - 1][j];
            if (j > 0)
                current += pref[i][j - 1];
            if (i > 0 && j > 0)
                current -= pref[i - 1][j - 1];
            pref[i][j] = current;
        }
    }
    return pref;
}

ll querySum(const vector<vector<ll>> &prefix, ll r1, ll c1, ll r2, ll c2)
{
    ll total = prefix[r2][c2];
    if (r1 > 0)
        total -= prefix[r1 - 1][c2];
    if (c1 > 0)
        total -= prefix[r2][c1 - 1];
    if (r1 > 0 && c1 > 0)
        total += prefix[r1 - 1][c1 - 1];
    return total;
}

int main()
{
}