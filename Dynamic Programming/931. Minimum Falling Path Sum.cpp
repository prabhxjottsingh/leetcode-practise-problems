// Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
private:
    int dp[201][201];

    int func(int i, int j, vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (j >= m || j < 0)
            return 1e6;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int oneCase = matrix[i][j] + func(i - 1, j - 1, matrix);
        int twoCase = matrix[i][j] + func(i - 1, j, matrix);
        int threeCase = matrix[i][j] + func(i - 1, j + 1, matrix);
        int finalStep = min(oneCase, min(twoCase, threeCase));
        return dp[i][j] = finalStep;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int count = INT_MAX;
        memset(dp, -1, sizeof(dp));
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            count = min(count, func(n - 1, i, matrix));
        }
        return count;
    }
};