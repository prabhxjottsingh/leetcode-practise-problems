// tc: O(n)
// sc: O(n)
class Solution
{
private:
    int dp[101];
    int func(int i, string &s)
    {
        if (i == -1)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int ways = 0;
        if (s[i] >= '1')
            ways += func(i - 1, s);
        if (i - 1 > -1 && s[i - 1] == '1')
            ways += func(i - 2, s);
        if (i - 1 > -1 && s[i - 1] == '2' && s[i] < '7')
            ways += func(i - 2, s);
        return dp[i] = ways;
    }

public:
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));
        int countWays = func(s.size() - 1, s);
        return countWays;
    }
};

//----------------
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] >= '1')
                dp[i] = dp[i - 1];
            if (i - 2 > -1 && s[i - 2] == '1')
                dp[i] += dp[i - 2];
            if (i - 2 > -1 && s[i - 2] == '2' && s[i - 1] < '7')
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};