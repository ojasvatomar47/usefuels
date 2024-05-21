#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll chineseRemainder(std::vector<ll> nums, std::vector<ll> rems)
{
    ll prod = 1;
    for (ll num : nums)
        prod *= num;

    ll result = 0;
    for (ll i = 0; i < nums.size(); i++)
    {
        ll pp = prod / nums[i];
        ll x, y;
        gcdExtended(pp, nums[i], x, y);
        result += rems[i] * x * pp;
    }
    return (result % prod + prod) % prod;
}

int main()
{
}