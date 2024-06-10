#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

/*
PASSWORD
*/

/*
ex.: abcd : a*p^0 + b*p^1 + c*p^2 + d*p^3 ...
*/

void preProcess(string &str, ll n, vector<ll> &dp, vector<ll> &pa)
{
    ll p = 31, pow = p;

    // Base case
    dp[0] = (str[0] - 'a' + 1) * 1;
    pa[0] = 1; // (anything)^0 = 1

    for (int i = 1; i < n; i++)
    {
        dp[i] = (dp[i - 1] + (str[i] - 'a' + 1) * pow) % MOD;
        pa[i] = pow;
        pow = (pow * p) % MOD;
    }
}

ll hshQuery(ll l, ll r, vector<ll> &dp)
{
    ll ans = dp[r];

    if (l > 0)
        ans = (ans - dp[l - 1] + MOD) % MOD;

    return ans;
}

int main()
{
    string str;
    cin >> str;
    ll n = str.size();

    // dp[i] => stores hash value of substring 0 to i
    vector<ll> dp(n, 0), pa(n, 0);

    preProcess(str, n, dp, pa);

    ll ans = -1;

    /*
    Proper prefix: 0 to n-1
    Proper suffix: 1 to n
    Middle substring: 1 to n-1
    */

    for (int i = 0; i < n - 1; i++)
    {
        ll prefHshVal = dp[i];
        ll suffHshVal = hshQuery(n - i - 1, n - 1, dp);

        if ((prefHshVal * pa[n - i - 1]) % MOD == suffHshVal)
        {
            for (int j = 1, k = i + 1; k < n - 1; j++, k++)
            {
                ll midHshVal = hshQuery(j, k, dp);
                if ((prefHshVal * pa[j]) % MOD == midHshVal)
                {
                    ans = i + 1;
                    break;
                }
            }
        }
    }

    if (ans == -1)
        cout << "Just a legend" << endl;
    else
        cout << str.substr(0, ans) << endl;
}