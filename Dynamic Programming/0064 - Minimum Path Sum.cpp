// Problem Link: https://leetcode.com/problems/minimum-path-sum/

class Solution
{
private:
    int dp[203][203];

    int func(int i, int j, vector<vector<int>> &matrix)
    {
        if (i < 0 || j < 0)
            return 1e6;
        if (i == 0 && j == 0)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int count = matrix[i][j];
        int goUp = func(i, j - 1, matrix) + count;
        int goDown = func(i - 1, j, matrix) + count;
        int finalCall = min(goUp, goDown);
        return dp[i][j] = finalCall;
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        int count = func(grid.size() - 1, grid[0].size() - 1, grid);
        return count;
    }
};