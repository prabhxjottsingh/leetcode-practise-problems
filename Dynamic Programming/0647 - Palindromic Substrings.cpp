// Problem Link: https://leetcode.com/problems/palindromic-substrings/

// Time Complexity: O(N * N)
// Space Complexity: O(N * N)

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int gap = 0;
        int resCount = 0;
        while (gap < n)
        {
            int i = 0;
            int j = gap;
            while (j < n)
            {
                if (gap == 0)
                    dp[i][j] = 1, resCount += 1;
                else if (gap == 1 && s[i] == s[j])
                    dp[i][j] = 1, resCount += 1;
                else if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1, resCount += 1;
                i += 1;
                j += 1;
            }
            gap += 1;
        }
        return resCount;
    }
};