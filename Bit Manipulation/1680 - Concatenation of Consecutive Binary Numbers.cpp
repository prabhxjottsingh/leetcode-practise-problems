// Problem Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// Time Complexity: O(N * K)
// Space Complexity: O(1)

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long res = 0;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            int sz = (int)(log2(i) + 1);
            res = (((res << sz) % mod) + (i % mod)) % mod;
        }
        return res;
    }
};