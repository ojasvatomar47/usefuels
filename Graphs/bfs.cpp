#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

void bfs(const vector<vector<ll>> &adjList, ll vertices, ll start, vector<set<ll>> &levels)
{
    vector<ll> vis(vertices, 0);
    queue<ll> q;

    vis[start] = 1, q.push(start);

    while (!q.empty())
    {
        ll n = q.size();

        set<ll> st;

        for (ll i = 0; i < n; i++)
        {
            ll node = q.front();
            q.pop();

            st.insert(node);

            for (auto &adjNode : adjList[node])
            {
                if (!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }

        levels.push_back(st);
    }
}

int main()
{
}