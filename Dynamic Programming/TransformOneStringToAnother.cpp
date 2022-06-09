#include<bits/stdc++.h>
using namespace std;

int func(string &s, string &t)
{
    int n = s.size();
    int m = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int res = n + m - (2 * func(s, t));
}