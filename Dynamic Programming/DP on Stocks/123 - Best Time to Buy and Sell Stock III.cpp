class Solution
{
private:
    int dp[100003][2][3];
    int func(int idx, int n, bool buy, vector<int> &prices, int cap)
    {
        if (cap == 0 || idx == n)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        int take = 0, notTake = 0;

        if (buy)
        {
            take = (-1) * prices[idx] + func(idx + 1, n, 0, prices, cap);
            notTake = func(idx + 1, n, 1, prices, cap);
        }
        else
        {
            take = prices[idx] + func(idx + 1, n, 1, prices, cap - 1);
            notTake = func(idx + 1, n, 0, prices, cap);
        }

        return dp[idx][buy][cap] = max(take, notTake);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        bool buy = true;
        int cap = 2;
        int n = prices.size();
        int res = func(0, n, buy, prices, cap);
        return res;
    }
};