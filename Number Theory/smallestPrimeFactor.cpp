#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;

const int N = 5e6 + 1;
ll spf[N]; // smallest prime factor

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (int i = 4; i < N; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < N; i++)
    {
        if (spf[i] == i) // prime
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
}
