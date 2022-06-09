// Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution
{
private:
    int dp[1001][1001];
    int func(int start, int end, string &s)
    {
        if (end < start)
            return 0;
        if (s[start] == s[end])
        {
            if (start == end)
                return dp[start][end] = 1;
            else
                return dp[start][end] = (2 + func(start + 1, end - 1, s));
        }
        if (dp[start][end] != -1)
            return dp[start][end];
        int caseOne = func(start + 1, end, s);
        int caseTwo = func(start, end - 1, s);
        return dp[start][end] = max(caseOne, caseTwo);
    }

public:
    int longestPalindromeSubseq(string s)
    {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        int count = func(0, n - 1, s);
        return count;
    }
};