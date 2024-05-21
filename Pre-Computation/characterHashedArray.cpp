#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

vector<ll> characterFrequency(const string &str)
{
    vector<ll> freq(26, 0); // Assuming only lowercase English letters
    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            freq[c - 'a']++;
        }
    }
    return freq;
}

int main()
{
}