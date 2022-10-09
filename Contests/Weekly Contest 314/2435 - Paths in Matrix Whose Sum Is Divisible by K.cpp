// Problem Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

// Time Complexity: O(N * M * K)
// Space Complexity: O(N * M * K)

class Solution
{
private:
    const int mod = 1e9 + 7;

    int func(int i, int j, int n, int m, vector<vector<int>> &grid, int sum, int k, vector<vector<vector<int>>> &dp)
    {
        if (i >= n || j >= m)
            return 0;
        sum += grid[i][j];
        sum %= k;
        if (i == n - 1 && j == m - 1)
            return sum == 0;
        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];
        int caseDown = func(i + 1, j, n, m, grid, sum, k, dp);
        int caseUp = func(i, j + 1, n, m, grid, sum, k, dp);
        int totalCases = ((caseDown % mod) + (caseUp % mod)) % mod;
        return dp[i][j][sum] = totalCases;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        int countPaths = func(0, 0, n, m, grid, 0, k, dp);
        return countPaths;
    }
};