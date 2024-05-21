#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &str)
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "radar";
    cout << (isPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
