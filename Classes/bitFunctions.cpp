#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const long long int MOD = 1e9 + 7;

class BitFunctions
{
public:
    // Get the value of the bit at position pos
    bool getBit(ll num, ll pos)
    {
        return (num & (1 << pos)) != 0;
    }

    // Set the value of the bit at position pos to 1
    ll setBit(ll num, ll pos)
    {
        return num | (1 << pos);
    }

    // Clear the value of the bit at position pos to 0
    ll clearBit(ll num, ll pos)
    {
        return num & ~(1 << pos);
    }

    // Update the value of the bit at position pos to newValue (0 or 1)
    ll updateBit(ll num, ll pos, ll newValue)
    {
        num &= ~(1 << pos);             // Clear the bit at position pos
        return num | (newValue << pos); // Set the bit to newValue
    }

    // Count the number of set bits (1s) in an lleger
    ll countSetBits(ll num)
    {
        ll count = 0;
        while (num)
        {
            num &= (num - 1); // Clear the least significant bit
            count++;
        }
        return count;
    }

    // Find the rightmost set bit (1) position
    ll findRightmostSetBit(ll num)
    {
        if (num == 0)
            return -1; // No set bits
        ll pos = 0;
        while ((num & 1) == 0)
        {
            num >>= 1;
            pos++;
        }
        return pos;
    }

    // Find the leftmost set bit (1) position
    ll findLeftmostSetBit(ll num)
    {
        ll pos = sizeof(ll) * 8 - 1;
        while (pos >= 0 && !(num & (1 << pos)))
        {
            pos--;
        }
        return pos;
    }

    // Convert an lleger to a vector of its bits
    vector<ll> bitsVector32(ll x)
    {
        vector<ll> bits(32, 0);
        ll j = 0;
        ll temp = x;
        while (temp && j < 32)
        {
            bits[j++] = (temp & 1);
            temp >>= 1;
        }
        // reverse(bits.begin(), bits.end()); // Reverse the bits to get MSB to LSB order
        return bits;
    }

    vector<ll> bitsVector64(ll x)
    {
        // Change the size to 64 for a 64-bit integer
        vector<ll> bits(64, 0);
        ll j = 0;
        ll temp = x;
        while (temp && j < 64)
        {
            bits[j++] = (temp & 1);
            temp >>= 1;
        }

        // Uncomment the following line if you want the bits in the standard order (MSB to LSB)
        // reverse(bits.begin(), bits.end());

        return bits;
    }

    // Convert a vector of ll'egers to a matrix of its bits
    vector<vector<ll>> bitsMatrix(vector<ll> &v)
    {
        ll n = v.size();
        vector<vector<ll>> bits(n, vector<ll>(32, 0));
        for (ll i = 0; i < n; i++)
        {
            ll x = v[i], j = 31;
            while (x)
            {
                bits[i][j--] = (x & 1);
                x >>= 1;
            }
        }
        return bits;
    }
};

int main()
{
}