#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

// Function to compute (base^exp) % mod
ll binExpo(ll base, ll exp, ll mod)
{
    ll result = 1;
    base = base % mod; // Taking modulo of base

    while (exp > 0)
    {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1)
            result = (result * base) % mod;

        // exp must be even now
        exp = exp >> 1; // exp = exp/2
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
}