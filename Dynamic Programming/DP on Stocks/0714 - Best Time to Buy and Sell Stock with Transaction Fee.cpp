class Solution
{
private:
    int dp[50003][2];

    int func(int idx, int n, bool buy, vector<int> &prices, int fee)
    {
        if (idx == n)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        long long int take = 0;
        long long int notTake = 0;
        if (buy)
        {
            take = ((-1) * prices[idx]) + func(idx + 1, n, 0, prices, fee);
            notTake = func(idx + 1, n, 1, prices, fee);
        }
        else
        {
            take = prices[idx] + func(idx + 1, n, 1, prices, fee) - fee;
            notTake = func(idx + 1, n, 0, prices, fee);
        }
        dp[idx][buy] = max(take, notTake);
        return dp[idx][buy];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        bool buy = true;
        int maxProfit = func(0, n, buy, prices, fee);
        return maxProfit;
    }
};