// Problem Link: https://leetcode.com/problems/shortest-common-supersequence/

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        int dp[n + 1][m + 1];
        string res;
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n, j = m;
        while ((i > 0) && (j > 0))
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                res += str2[j - 1];
                j--;
            }
            else
            {
                res += str1[i - 1];
                i--;
            }
        }
        while (i > 0)
        {
            res += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            res += str2[j - 1];
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};