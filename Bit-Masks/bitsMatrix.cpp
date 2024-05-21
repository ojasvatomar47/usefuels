#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

vector<vector<ll>> bitsMatrix(vector<ll> &v, ll n)
{
    // Computing bits matrix
    // consists the input array in binary format
    vector<vector<ll>> bits(n + 1, vector<ll>(33, 0));

    for (int i = 0; i < n; i++)
    {
        ll x = v[i], j = 32;
        while (x)
        {
            bits[i + 1][j] = (x & 1), x >>= 1, j--;
        }
    }

    // Cumulative freq. of number of set bits for from 0 to i for each 0<=i<n
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            bits[i][j] += bits[i - 1][j];
        }
    }

    return bits;
}

int main()
{
}