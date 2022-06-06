// Problem Link: https://leetcode.com/problems/coin-change/

class Solution
{
private:
    int dp[10003];
    int func(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];
        int res = 1e9;
        for (auto &a : coins)
        {
            if (a <= amount)
                res = min(res, func(coins, amount - a) + 1);
        }
        return dp[amount] = res;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int res = func(coins, amount);
        if (res >= 1e9)
            return -1;
        return res;
    }
};

// Method: 2

int minimumElementsUtil(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (T % arr[0] == 0)
            return T / arr[0];
        else
            return 1e9;
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);

    int taken = 1e9;
    if (arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);

    return dp[ind][T] = min(notTaken, taken);
}