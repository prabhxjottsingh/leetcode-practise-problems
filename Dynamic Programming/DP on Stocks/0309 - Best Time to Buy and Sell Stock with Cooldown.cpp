class Solution
{
private:
    int func(int idx, bool buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (idx >= n)
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        int take = 0, notTake = 0;
        if (buy)
        {
            take = -prices[idx] + func(idx + 1, 0, n, prices, dp);
            notTake = func(idx + 1, 1, n, prices, dp);
        }
        else
        {
            take = prices[idx] + func(idx + 2, 1, n, prices, dp);
            notTake = func(idx + 1, 0, n, prices, dp);
        }

        return max(take, notTake);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int maxProfit = func(0, 1, n, prices, dp);
        return maxProfit;
    }
};

// Type 2
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j)
                {
                    int caseOne = dp[i + 1][1];
                    int caseTwo = -prices[i] + dp[i + 1][0];
                    dp[i][j] = max(caseOne, caseTwo);
                }
                else
                {
                    int caseOne = dp[i + 1][0];
                    int caseTwo = prices[i] + dp[i + 2][1];
                    dp[i][j] = max(caseOne, caseTwo);
                }
            }
        }
        return dp[0][1];
    }
};