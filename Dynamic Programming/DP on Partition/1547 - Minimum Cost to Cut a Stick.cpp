class Solution
{
private:
    int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minCost = 1e9;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + func(i, ind - 1, cuts, dp) + func(ind + 1, j, cuts, dp);
            minCost = min(cost, minCost);
        }
        return dp[i][j] = minCost;
    }

public:
    int minCost(int n, vector<int> &a)
    {
        // cuts.push_back(0);
        int sz = a.size();
        // memset(dp, -1, sizeof(dp));
        a.push_back(n);
        a.insert(a.begin(), 0);
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, -1));
        sort(a.begin(), a.end());
        return func(1, sz, a, dp);
    }
};