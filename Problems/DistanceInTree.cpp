#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const long long int MOD = 1e9 + 7;

/*
    dp1[i][j] => total no. of nodes at a distance of j from node i in the subtree rooted at i = summation (dp1[children][j-1])
    dp2[i][j] => total no. of nodes at a distance of j from node i in the whole tree = dp1[node][j] + (dp2[parent][j-1] - dp1[node][j-2])
*/
vector<vector<ll>> dp1(50001, vector<ll>(501, 0)), dp2(50001, vector<ll>(501, 0));

// filling dp1
void dfs(ll node, ll parent, vector<vector<ll>> &adjList, ll &k)
{

    for (auto &adjNode : adjList[node])
    {
        if (adjNode != parent)
            dfs(adjNode, node, adjList, k);
    }

    dp1[node][0] = 1; // nodes at distance 0 from current node = current node itself
    for (int i = 1; i <= k; i++)
    {
        for (auto &adjNode : adjList[node])
        {
            if (adjNode != parent)
                dp1[node][i] += dp1[adjNode][i - 1]; // dist from node = x, then dist from child of node = x-1
        }
    }
}

// filling dp2
void dfs1(ll node, ll parent, vector<vector<ll>> &adjList, ll &k)
{

    for (int i = 0; i <= k; i++)
        dp2[node][i] += dp1[node][i];

    if (parent != 0) // not the root of the main tree
    {
        dp2[node][1] += dp2[parent][0];

        for (int i = 2; i <= k; i++)
        {
            dp2[node][i] += (dp2[parent][i - 1] - dp1[node][i - 2]);
        }
    }

    for (auto &adjNode : adjList[node])
    {
        if (adjNode != parent)
            dfs1(adjNode, node, adjList, k);
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> adjList(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1, 0, adjList, k);
    dfs1(1, 0, adjList, k);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp2[i][k];
    cout << ans / 2 << endl;
}
