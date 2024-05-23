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

int main()
{
}