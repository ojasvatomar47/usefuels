#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

void topoDFS(ll node, vector<vector<ll>> &adjList, vector<ll> &vis, stack<ll> &st)
{

    vis[node] = 1;

    for (auto &adjNode : adjList[node])
    {
        if (!vis[adjNode])
            topoDFS(adjNode, adjList, vis, st);
    }

    st.push(node);
}

void dfs(ll node, vector<vector<ll>> &adjTranspose, vector<ll> &vis, vector<ll> &v, ll &mini, map<ll, ll> &mp)
{

    vis[node] = 1;
    mini = min(mini, v[node]);
    mp[v[node]]++;

    for (auto &adjNode : adjTranspose[node])
    {
        if (!vis[adjNode])
            dfs(adjNode, adjTranspose, vis, v, mini, mp);
    }
}

// void pst(stack<ll> st)
// {
//     while (!st.empty())
//         cout << st.top() << " ", st.pop();
//     cout << endl;
// }

pair<ll, ll> kosaraju(vector<vector<ll>> &adjList, ll n, vector<ll> &v)
{
    vector<ll> vis(n + 1, 0);
    stack<ll> st;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            topoDFS(i, adjList, vis, st);
    }

    vector<vector<ll>> adjTranspose(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (auto &it : adjList[i])
            adjTranspose[it].push_back(i);
        vis[i] = 0;
    }

    ll sum = 0, prod = 1;

    while (!st.empty())
    {
        ll node = st.top();
        st.pop();
        map<ll, ll> mp;

        ll mini = 1e18;

        if (!vis[node])
            dfs(node, adjTranspose, vis, v, mini, mp), sum += mini, prod = (prod * mp[mini]) % MOD;
    }

    return {sum, prod};
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<vector<ll>> adjList(n + 1);

    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    pair<ll, ll> ans = kosaraju(adjList, n, v);
    cout << ans.first << " " << ans.second << endl;
}