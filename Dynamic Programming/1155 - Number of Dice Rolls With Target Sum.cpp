// Problem Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// time Complexity: O(N * Target)
// Space Complexity: O(N * target)

class Solution
{
private:
    const int mod = 1e9 + 7;
    int dp[31][1001];

    int helperFunc(int n, int k, int target)
    {
        if (n == 0)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[n][target] != -1)
            return dp[n][target];
        int count = 0;
        for (int i = 1; i <= k; i++)
        {
            if (i <= target)
                count = ((count % mod) + (helperFunc(n - 1, k, target - i) % mod)) % mod;
        }
        return dp[n][target] = count;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        int countRes = helperFunc(n, k, target);
        return countRes;
    }
};