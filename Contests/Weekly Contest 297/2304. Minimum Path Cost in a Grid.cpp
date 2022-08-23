// Problem Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid/

// Space Complexity: O(51 * 51)
// Time Complexity: O(N * N)

class Solution
{
private:
    int dp[51][51];
    int func(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row == n - 1)
            return grid[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int val = grid[row][col];
        int minCost = 1e8;
        for (int j = 0; j < m; j++)
        {
            int cost = moveCost[val][j];
            int newCost = cost + val + func(row + 1, j, grid, moveCost);
            minCost = min(minCost, newCost);
        }
        return dp[row][col] = minCost;
    }

public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        memset(dp, -1, sizeof(dp));
        int minCost = 1e8;
        int n = grid.size();
        int m = grid[0].size();
        for (int j = 0; j < m; j++)
        {
            minCost = min(minCost, func(0, j, grid, moveCost));
        }
        return minCost;
    }
};