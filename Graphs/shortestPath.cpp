#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define test(...)
#define deb(...)
#else
#include "deb.h"
#endif

typedef long long int ll;
typedef long double lld;

const long long int MOD = 1e9 + 7;

vector<ll> shortestPath(int src, int n, vector<vector<pair<ll, ll>>> &adj)
{
    vector<ll> dist(n, LLONG_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        pq;

    pq.push({0ll, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto &[adjNode, wt] : adj[node])
        {
            int nwWt = d + wt;
            if (dist[adjNode] > nwWt)
            {
                dist[adjNode] = nwWt;
                pq.push({nwWt, adjNode});
            }
        }
    }
    return dist;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1, testcase = 1;
    cin >> t;
    while (t--)
    {
        test(testcase++);
        solve();
    }
    return 0;
}
