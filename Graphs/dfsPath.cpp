#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

vector<ll> dfsPath(ll src, ll parent, ll dst, vector<vector<ll>> &adjList)
{
    if (src == dst)
        return {src};

    for (auto &adjNode : adjList[src])
    {
        if (adjNode != parent)
        {
            vector<ll> temp = dfsPath(adjNode, src, dst, adjList);
            if (temp.size())
            {
                temp.push_back(src);
                return temp;
            }
        }
    }

    return {};
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<vector<ll>> adjList(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adjList[u].push_back(v), adjList[v].push_back(u);
    }

    // path from b to a
    vector<ll> path = dfsPath(a, -1ll, b, adjList);
    reverse(path.begin(), path.end()); // for path from a to b
}