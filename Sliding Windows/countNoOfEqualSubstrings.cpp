#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

ll countNoOfEqualSubstrings(string &a, string &b)
{
    ll count = 0, ans = 0, n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            ans += (count * (count + 1) / 2), count = 0;
        else
            count++;
    }
    ans += count * (count + 1) / 2;

    return ans;
}

int main()
{
}