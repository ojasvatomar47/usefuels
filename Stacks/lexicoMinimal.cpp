#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

// function for lexicographically smallest string after k deletions in original string s
string lexicographicallyMinimal(string s, ll k)
{
    stack<char> stack;

    for (char c : s)
    {
        while (!stack.empty() && stack.top() > c && k > 0)
        {
            stack.pop();
            k--;
        }
        stack.push(c);
    }

    // If there are still characters to remove, remove from the end of the stack
    while (k > 0)
    {
        stack.pop();
        k--;
    }

    // Collect the characters from the stack
    string result;
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    // The stack constructs the string in reverse order, so reverse it
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
}