#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// Function to generate all divisors of a number
vector<ll> generateDivisors(ll n)
{
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (n / i != i)
                divs.push_back(n / i);
        }
    }
    return divs;
}

// Function to generate all pairs of divisors (d, k/d)
vector<pair<ll, ll>> generateDivsPairs(ll k)
{
    vector<pair<ll, ll>> divs;
    for (ll i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            divs.push_back({i, k / i});
            if (i != k / i)
                divs.push_back({k / i, i});
        }
    }
    return divs;
}

// Function to count the number of divisors
ll numberOfDivisors(ll n)
{
    ll count = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
                count++;
        }
    }
    return count;
}

// Function to calculate the sum of all divisors
ll sumOfDivisors(ll n)
{
    ll sum = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (n / i != i)
                sum += n / i;
        }
    }
    return sum;
}

int main()
{
    ll n = 28; // Example number

    // Generate and print all divisors
    vector<ll> divs = generateDivisors(n);
    cout << "Divisors of " << n << ": ";
    for (ll d : divs)
        cout << d << " ";
    cout << endl;

    // Generate and print all divisor pairs
    vector<pair<ll, ll>> divsPairs = generateDivsPairs(n);
    cout << "Divisor pairs of " << n << ": ";
    for (auto p : divsPairs)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;

    // Calculate and print the number of divisors
    ll numDivs = numberOfDivisors(n);
    cout << "Number of divisors of " << n << ": " << numDivs << endl;

    // Calculate and print the sum of divisors
    ll sumDivs = sumOfDivisors(n);
    cout << "Sum of divisors of " << n << ": " << sumDivs << endl;

    return 0;
}
