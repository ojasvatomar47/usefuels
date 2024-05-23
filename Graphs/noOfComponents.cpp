#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

void dfs(ll node, const vector<vector<ll>> &adj, vector<ll> &visited)
{
    visited[node] = 1;

    for (ll neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

ll noOfComponents(ll n, vector<vector<ll>> &adjList)
{
    ll count = 0;
    vector<ll> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjList, vis);
        }
    }

    return count;
}

int main()
{
}