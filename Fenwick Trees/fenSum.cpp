#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

const long long int N = 1e5 + 5;
ll fen[N];

void update(ll ind, ll val)
{
    ll i = ind + 1; // convert to 1-based index
    while (i < N)
    {
        fen[i] += val;
        i += (i & (-i));
    }
}

ll pref(ll ind)
{
    ll s = 0, i = ind + 1; // convert to 1-based index
    while (i > 0)
    {
        s += fen[i];
        i -= (i & (-i));
    }
    return s;
}

ll rangeSum(ll l, ll r)
{
    return pref(r) - pref(l - 1);
}

ll find(ll k, ll n) // Binary lifting (finding lower bound index => smallest ind st. sum till ind >= k)
{
    ll currPtr = 0, prevSum = 0;
    for (int i = log2(n); i >= 0; i--)
    {
        if (fen[currPtr + (1 << i)] + prevSum < k)
        {
            currPtr += (1 << i);
            prevSum += fen[currPtr];
        }
    }
    return (currPtr + 1);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Initialize Fenwick Tree with given values
    for (int i = 0; i < n; i++)
        update(i, v[i]);

    ll q;
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1) // range sum query
        {
            ll l, r;
            cin >> l >> r;
            cout << rangeSum(l, r) << endl;
        }
        else if (type == 2) // point update
        {
            ll ind, val;
            cin >> ind >> val;
            update(ind, val);
        }
    }

    return 0;
}
