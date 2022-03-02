// Problem Link: https://leetcode.com/problems/is-subsequence/

// Time Complexity: O(M)
// Space Complexity: O(1)

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (j < m)
        {
            if (i < n && s[i] == t[j])
                i++;
            j++;
        }
        if (i == n)
            return true;
        return false;
    }
};