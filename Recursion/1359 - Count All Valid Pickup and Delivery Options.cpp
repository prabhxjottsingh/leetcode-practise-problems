// Problem Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int countOrders(int n)
    {
        if (n == 0)
            return 1;
        long long ans;
        ans = (n * (2 * n - 1) % mod) * (long long)(countOrders(n - 1) % mod);
        return (ans % mod);
    }
};