// Problem Link: https://leetcode.com/problems/maximal-square/

// Top-Down Approach:
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = mat[i][0] == '1' ? 1 : 0;
            maxArea = max(maxArea, dp[i][0]);
        }
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = mat[0][j] == '0' ? 0 : 1;
            maxArea = max(maxArea, dp[0][j]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] == '0')
                {
                    dp[i][j] = 0;
                    continue;
                }
                int one = dp[i - 1][j - 1];
                int two = dp[i - 1][j];
                int three = dp[i][j - 1];
                int newVal = min({one, two, three});
                dp[i][j] = newVal + 1;
                maxArea = max(maxArea, dp[i][j]);
            }
        }
        return maxArea * maxArea;
    }
};


//Recursive Approach, Bottom - Up Approach