// Problem Link: https://leetcode.com/problems/coin-change-2/

// Time Complexity: O(N)
// Space Complexity: O(305 * 10010)

class Solution
{
private:
    int dp[305][10010];

    int helperFunction(int idx, int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        if (idx < 0)
            return 0;
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int ways = 0;
        for (int coinAmount = 0; coinAmount <= amount; coinAmount += coins[idx])
        {
            ways += helperFunction(idx - 1, amount - coinAmount, coins);
        }
        return dp[idx][amount] = ways;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof(dp));
        int res = helperFunction(coins.size() - 1, amount, coins);
        return res;
    }
};

// Method 2:
class Solution
{
private:
    int dp[303][5005];
    int func(int idx, vector<int> &coins, int amount)
    {
        if (idx == 0)
        {
            if (amount % coins[idx] == 0)
                return 1;
            return 0;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int notTake = func(idx - 1, coins, amount);
        int take = 0;
        if (coins[idx] <= amount)
            take = func(idx, coins, amount - coins[idx]);
        return dp[idx][amount] = (take + notTake);
    }

public:
    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int countWays = func(n - 1, coins, amount);
        return countWays;
    }
};