#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

// n/2 + n/3 + n/4 + .... + n/n : tc: O(n*logn)
// n/2 + n/3 + n/5 + n/7 + .... : tc: O(n*log(logn))

vector<bool> sieveOfEratosthenes(ll n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main()
{
}