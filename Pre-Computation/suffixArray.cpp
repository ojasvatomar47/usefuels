#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// Function to generate suffix sum array
vector<ll> generateSuffixSum(const vector<ll> &arr)
{
    ll n = arr.size();
    vector<ll> suff(n, 0);

    for (ll i = n - 1; i >= 0; --i)
    {
        suff[i] = (i == n - 1) ? arr[i] : suff[i + 1] + arr[i];
    }

    return suff;
}

int main()
{
    vector<ll> arr = {1, 2, 3, 4, 5}; // Example array
    vector<ll> suff = generateSuffixSum(arr);

    cout << "Suffix sum array: ";
    for (ll val : suff)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
