#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll sumOfDivisors(ll n)
{
    ll sum = 0;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                sum += i;
            else
                sum += i + n / i;
        }
    }
    return sum;
}

int main()
{
}