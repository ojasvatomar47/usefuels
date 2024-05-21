#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

bool predicate(vector<ll> &arr, ll k, ll mid);

ll firstTick(vector<ll> &arr, ll l, ll h, ll k)
{
    ll low = l, high = h;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (predicate(arr, k, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (low <= h) ? low : -1;
}

int main()
{
}