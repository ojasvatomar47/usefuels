#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
 
const long long int MOD = 1e9 + 7;

bool isSubmask(ll a, ll b) {
    return (a & b) == a;
}

// min. no. x to add to a so that a+x becomes submask of b
ll func1(ll a, ll b) {
    ll ta = a, tb = b, c = 0, s = 0, x = 0;
    while (tb && !isSubmask(a + x, b))
    {
        if (tb & 1)
        {
            x = (1 << c) - s;
            if (isSubmask(a + x, b))
                break;
        }
        c++, s |= ((ta & 1) << (c - 1));
        ta >>= 1, tb >>= 1;
    }
    return x;
}
 
// min. no. x to add to b so that a becomes submask of b+x
ll func2(ll a, ll b) {
    ll ta = a, tb = b, c = 0, x = 0;
    ll s1 = 0, s2 = 0;
    while (ta && !isSubmask(a, b + x))
    {
        s1 |= ((ta & 1) << c), s2 |= ((tb & 1) << c);
        if ((ta & 1) && !(tb & 1))
        {
            x = s1 - s2;
            if (isSubmask(a, b + x))
                break;
        }
        c++, ta >>= 1, tb >>= 1;
    }
}

int main()
{
    
}