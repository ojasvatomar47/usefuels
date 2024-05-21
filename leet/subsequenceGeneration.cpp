#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

void generateSubsequences(const vector<ll> &nums, vector<ll> &current, ll index, vector<vector<ll>> &result)
{
    if (index == nums.size())
    {
        result.push_back(current);
        return;
    }

    // Exclude the current element
    generateSubsequences(nums, current, index + 1, result);

    // Include the current element
    current.push_back(nums[index]);
    generateSubsequences(nums, current, index + 1, result);

    current.pop_back(); // Backtrack
}

int main()
{
}