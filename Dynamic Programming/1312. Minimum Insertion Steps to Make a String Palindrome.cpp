class Solution
{
private:
    int func(string &s, string &t)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0, dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }

public:
    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        int count = func(s, t);
        int finalRes = n - count;
        return finalRes;
    }
};