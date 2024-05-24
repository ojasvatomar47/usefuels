#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

// Function to generate all combinations of size k from the given string
vector<string> generateCombinations(const string &input, ll k)
{
    ll n = input.size();
    vector<string> combinations;

    // Create a bitmask with k 1's and (n-k) 0's
    string bitmask(k, 1); // k leading 1's
    bitmask.resize(n, 0); // n-k trailing 0's

    // Generate all combinations using the bitmask
    do
    {
        string temp;
        for (ll i = 0; i < n; ++i)
        {
            if (bitmask[i])
            {
                temp.push_back(input[i]);
            }
        }
        combinations.push_back(temp);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    return combinations;
}

int main()
{
}