#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long int

const long long int MOD = 1e9 + 7;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds_pair;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, ans = -1, num = 0;
        cin >> n;
        pbds_pair st;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i], st.insert({v[i], i + 1});

        // Print
        for (auto it = st.begin(); it != st.end(); ++it)
            cout << "(" << it->first << "," << it->second << ") ";
        cout << endl;

        vector<ll> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        for (ll mush = 1; mush <= n / 2 + (n & 1); mush++)
        {
            ll len = st.size();
            auto it = *st.find_by_order(len - mush);

            ll tempans = it.first * mush;
            if (ans < tempans)
                ans = tempans, num = mush;

            pair<ll, ll> temp = {v[p[mush - 1] - 1], p[mush - 1]};
            st.erase(temp);
        }
        cout << ans << " " << num << endl;
    }
}