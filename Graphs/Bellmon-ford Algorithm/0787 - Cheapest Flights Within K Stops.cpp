// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// time Complexity: O(K * N)
// Space Complexity: o(n * k)

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dp(k + 2, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= k + 1; i++)
            dp[i][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &a : flights)
            {
                int u = a[0];
                int v = a[1];
                int wt = a[2];
                if (dp[i - 1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], wt + dp[i - 1][u]);
            }
        }
        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};