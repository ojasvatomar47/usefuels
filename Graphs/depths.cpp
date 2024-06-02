#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

void depths(ll node, ll parent, vector<ll> &depth, vector<vector<ll>> &adjList)
{
    for (auto &adjNode : adjList[node])
    {
        if (adjNode != parent)
        {
            depth[adjNode] = depth[node] + 1;
            depths(adjNode, node, depth, adjList);
        }
    }
}

int main()
{
    ll n;
    vector<vector<ll>> adjList(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adjList[u].push_back(v), adjList[v].push_back(u);
    }

    vector<ll> depth(n + 1, 0);

    ll src = 1;
    depths(src, -1ll, depth, adjList);
}