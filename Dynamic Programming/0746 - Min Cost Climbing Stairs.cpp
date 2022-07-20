class Solution
{
private:
    int func(int idx, int n, vector<int> &cost, int dp[])
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int costOfOneStep = cost[idx] + func(idx + 1, n, cost, dp);
        int costOfTwoSteps = cost[idx] + func(idx + 2, n, cost, dp);
        dp[idx] = min(costOfOneStep, costOfTwoSteps);
        return dp[idx];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        int startFromZero = func(0, n, cost, dp);
        memset(dp, -1, sizeof(dp));
        int startFromOne = func(1, n, cost, dp);
        int finalCost = min(startFromZero, startFromOne);
        return finalCost;
    }
};