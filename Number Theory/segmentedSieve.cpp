#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void generateSieve()
{
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}

vector<int> generatePrimes(int n)
{
    vector<int> ds;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
            ds.push_back(i);
    }
    return ds;
}

int main()
{
    generateSieve();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        vector<int> primes = generatePrimes(sqrt(r));

        int dummy[r - l + 1];
        memset(dummy, 1, sizeof(dummy));

        for (auto &pr : primes)
        {
            int firstMultiple = (l / pr + (l % pr != 0)) * pr;

            for (int j = max(pr * pr, firstMultiple); j <= r; j += pr)
            {
                dummy[j - l] = 0;
            }
        }

        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l])
                cout << i << endl;
        }
    }
}