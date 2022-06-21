class Solution
{
private:
    int func(int idx, int n, bool buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0 || idx == n)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        int take = 0, notTake = 0;

        if (buy)
        {
            take = (-1) * prices[idx] + func(idx + 1, n, 0, prices, cap, dp);
            notTake = func(idx + 1, n, 1, prices, cap, dp);
        }
        else
        {
            take = prices[idx] + func(idx + 1, n, 1, prices, cap - 1, dp);
            notTake = func(idx + 1, n, 0, prices, cap, dp);
        }

        return dp[idx][buy][cap] = max(take, notTake);
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        bool buy = true;
        int cap = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        int res = func(0, n, buy, prices, k, dp);
        return res;
    }
};