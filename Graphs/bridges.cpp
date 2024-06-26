#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

vector<pair<ll, ll>> bridges;
ll step = 1;

void dfs(ll node, ll parent, vector<vector<ll>> &adjList, vector<ll> &tme, vector<ll> &low, vector<ll> &vis)
{
    vis[node] = 1;
    tme[node] = low[node] = step++;

    for (auto &adjNode : adjList[node])
    {
        if (adjNode == parent)
            continue;

        if (!vis[adjNode])
        {
            dfs(adjNode, node, adjList, tme, low, vis);

            low[node] = min(low[node], low[adjNode]);

            if (low[adjNode] > tme[node])
            {
                bridges.push_back({node, adjNode});
            }
        }
        else
        {
            low[node] = min(low[node], low[adjNode]);
        }
    }
}

void findBridges(vector<vector<ll>> &adjList, ll n)
{
    ll step = 1;
    vector<ll> tme(n + 1, 0), low(n + 1, 0), vis(n + 1, 0);
    step = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0, adjList, tme, low, vis);
    }
}

int main()
{
}