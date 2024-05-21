#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> computePrefixXOR(const vector<ll> &nums)
{
    vector<ll> prefixXOR(nums.size());
    prefixXOR[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
    }
    return prefixXOR;
}

ll getXORInRange(const vector<ll> &prefixXOR, ll l, ll r)
{
    if (l == 0)
        return prefixXOR[r];
    else
        return prefixXOR[r] ^ prefixXOR[l - 1];
}

const long long int MOD = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> prefixXOR = computePrefixXOR(v);
}