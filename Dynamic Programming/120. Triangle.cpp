// Problem Link: https://leetcode.com/problems/triangle/

class Solution
{
private:
    int dp[201][201];

    int func(int i, int j, vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        if (i == (n - 1))
        {
            return triangle[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int firstCase = triangle[i][j] + func(i + 1, j, triangle);
        int secondCase = triangle[i][j] + func(i + 1, j + 1, triangle);
        int finalStep = min(firstCase, secondCase);
        return dp[i][j] = finalStep;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        memset(dp, -1, sizeof(dp));
        int countSum = func(0, 0, triangle);
        return countSum;
    }
};