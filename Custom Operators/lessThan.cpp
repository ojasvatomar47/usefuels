#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

struct Round
{
    ll rnd[5];
};

bool operator<(const Round &X, const Round &Y)
{
    ll cnt = 0;
    for (int i = 0; i < 5; i++)
        cnt += X.rnd[i] < Y.rnd[i];
    return cnt >= 3;
}

int main()
{
    ll n;
    cin >> n;
    vector<Round> mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> mat[i].rnd[j];
    }
}