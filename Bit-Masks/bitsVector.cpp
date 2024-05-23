#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

vector<ll> bitsVector(ll x)
{
    vector<ll> bits(32, 0);
    ll j = 0, temp = x;
    while (temp)
        bits[j++] = (temp & 1), temp >>= 1;

    // reverse(bits.begin(), bits.end());
    return bits;
}

int main()
{
}