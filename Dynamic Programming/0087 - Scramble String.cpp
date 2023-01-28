// sc: O(n ^ 2)
// tc: O(n ^ 2)

class Solution
{
private:
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return 1;
        string idx;
        idx += s1, idx += " ", idx += s2;
        if (dp.count(idx))
            return dp[idx];
        int n = s1.size();
        for (int i = 1; i < n; i++)
        {
            bool case1 = isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));

            bool case2 = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

            if (case1 || case2)
                return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
};