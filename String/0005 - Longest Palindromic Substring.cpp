// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/description/

// Time Complexity: O(N ^ 2)
// Space Complexity: O(N)

class Solution
{
private:
    int func(int i, int j, string &s, int n)
    {
        if (i < 0 || j >= n || s[i] != s[j])
            return 0;
        return 2 + func(i - 1, j + 1, s, n);
    }

public:
    string longestPalindrome(string s)
    {
        string resStr;
        int maxLen = 0;
        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            int lenOne = func(i - 1, i + 1, s, n);
            if (maxLen < lenOne)
            {
                maxLen = lenOne;
                idx = i;
            }
        }
        int newIdx = -1;
        for (int i = 0; i < n; i++)
        {
            int lenOne = func(i, i + 1, s, n);
            if (maxLen < lenOne)
            {
                maxLen = lenOne;
                newIdx = i;
            }
        }
        // cout << maxLen << " " << newIdx << endl;
        if (newIdx != -1)
        {
            for (int i = newIdx - (maxLen / 2) + 1; i < newIdx; i++)
                resStr += s[i];
            for (int i = newIdx; i <= newIdx + (maxLen / 2); i++)
                resStr += s[i];
        }
        else
        {
            for (int i = idx - (maxLen / 2); i < idx; i++)
                resStr += s[i];
            for (int i = idx; i <= idx + (maxLen / 2); i++)
                resStr += s[i];
        }
        return resStr;
    }
};