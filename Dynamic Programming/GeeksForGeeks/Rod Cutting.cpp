class Solution
{
private:
    int dp[1003][1003];
    int func(int idx, int cost[], int n)
    {
        if (idx == 0)
        {
            return (n * cost[0]);
        }
        if (dp[idx][n] != -1)
            return dp[idx][n];
        int notTake = func(idx - 1, cost, n);
        int take = INT_MIN;
        int len = idx + 1;
        if (len <= n)
            take = cost[idx] + func(idx, cost, n - len);
        int finalRes = max(take, notTake);
        return dp[idx][n] = finalRes;
    }

public:
    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return func(n - 1, price, n);
    }
};