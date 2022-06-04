// Problem Link: https://leetcode.com/problems/unique-paths-ii/

class Solution
{
private:
    int dp[201][201];

    int func(int i, int j, vector<vector<int>> &matrix)
    {
        if (i < 0 || j < 0)
            return 0;
        if (matrix[i][j])
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, matrix);
        int down = func(i, j - 1, matrix);
        int ways = up + down;
        return dp[i][j] = ways;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        memset(dp, -1, sizeof(dp));
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int countPaths = func(n - 1, m - 1, obstacleGrid);
        return countPaths;
    }
};