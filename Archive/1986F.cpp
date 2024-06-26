#include <bits/stdc++.h>
using namespace std;

#define ll long long int

map<pair<ll, ll>, ll> M;
ll timer;

pair<ll, ll> dfs(ll node, vector<vector<ll>> &adj, vector<ll> &H, ll par)
{

    if (H[node] != -1)
    {
        return {H[node], 0};
    }

    timer++;
    H[node] = timer;

    ll res = H[node], sum = 1;

    for (auto &adjNode : adj[node])
    {
        if (adjNode == par)
            continue;
        pair<ll, ll> P = dfs(adjNode, adj, H, node);
        ll x = P.first, y = P.second;

        sum += y;

        if (x <= H[node])
        {
            res = min(res, x);
        }
        else
        {
            M[{node, adjNode}] = y;
        }
    }

    H[node] = res;
    return {res, sum};
}

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> adj(n);

        while (m--)
        {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        M.clear();
        timer = 0;
        vector<ll> H(n, -1);
        pair<ll, ll> P = dfs(0, adj, H, -1);

        ll ans = n * (n - 1) / 2;
        for (auto &adjNode : M)
        {
            ll l = adjNode.second, r = n - adjNode.second;
            ans = min(ans, (l * (l - 1) + (r * (r - 1))) / 2);
        }

        cout << ans << endl;
    }
    return 0;
}