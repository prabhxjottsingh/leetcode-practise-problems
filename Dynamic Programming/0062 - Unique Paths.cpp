// Problem Link: https://leetcode.com/problems/unique-paths/

class Solution
{
private:
    int dp[201][201];

    int func(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i, j - 1);
        int left = func(i - 1, j);
        int totalSum = up + left;
        return dp[i][j] = totalSum;
    }

public:
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return func(m - 1, n - 1);
    }
};