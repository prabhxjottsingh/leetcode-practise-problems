public:
long long int subsequenceCount(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1];
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
}
;