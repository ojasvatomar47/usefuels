#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// Function to generate prefix sum array
vector<ll> generatePrefixSum(const vector<ll> &arr)
{
    ll n = arr.size();
    vector<ll> pref(n, 0);

    for (ll i = 0; i < n; ++i)
    {
        pref[i] = (i == 0) ? arr[i] : pref[i - 1] + arr[i];
    }

    return pref;
}

int main()
{
    vector<ll> arr = {1, 2, 3, 4, 5}; // Example array
    vector<ll> pref = generatePrefixSum(arr);

    cout << "Prefix sum array: ";
    for (ll val : pref)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
