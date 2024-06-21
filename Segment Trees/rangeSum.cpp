#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

class SGT
{
    vector<ll> seg;

public:
    SGT(ll n)
    {
        seg.resize(4 * n + 1);
    }

    void build(ll ind, ll low, ll high, vector<ll> &v)
    {
        if (low == high) // leaf node
        {
            seg[ind] = v[low];
            return;
        }

        ll mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, v);      // left subtree call
        build(2 * ind + 2, mid + 1, high, v); // right subtree call
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }

    void update(ll ind, ll low, ll high, ll i, ll val)
    {
        if (low == high) // reached i
        {
            seg[ind] = val;
            return;
        }

        ll mid = (low + high) >> 1;

        if (i <= mid) // i lies in the left subtree
            update(2 * ind + 1, low, mid, i, val);
        else // i lies in the right subtree
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r)
    {

        // No overlap => l r low high | low high l r
        if (r < low || l > high)
            return 0;

        // Complete overlap => l low high r
        else if (low >= l && high <= r)
            return seg[ind];

        // Partial overlap => l low r high | low l high r
        else
        {
            ll mid = (low + high) >> 1;
            ll left = query(2 * ind + 1, low, mid, l, r);
            ll right = query(2 * ind + 2, mid + 1, high, l, r);
            return (left + right);
        }
    }
};

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    SGT sgt(n);
    sgt.build(0, 0, n - 1, v);

    ll q;
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1) // find sum in range l to r
        {
            ll l, r;
            cin >> l >> r;
            ll ans = sgt.query(0, 0, n - 1, l, r);
            cout << ans << endl;
        }
        else // update v[ind] = val
        {
            ll ind, val;
            cin >> ind >> val;
            sgt.update(0, 0, n - 1, ind, val);
        }
    }
}