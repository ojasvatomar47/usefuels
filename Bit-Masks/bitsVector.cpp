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

vector<ll> bitsVector(ll x)
{
    // Change the size to 64 for a 64-bit integer
    vector<ll> bits(64, 0);
    ll j = 0;
    ll temp = x;
    while (temp && j < 64)
    {
        bits[j++] = (temp & 1);
        temp >>= 1;
    }

    // Uncomment the following line if you want the bits in the standard order (MSB to LSB)
    // reverse(bits.begin(), bits.end());

    return bits;
}

int main()
{
}