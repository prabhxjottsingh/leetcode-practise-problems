// Problem Link: https://leetcode.com/problems/minimum-window-substring/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0;
        int j = 0;
        int resLen = INT_MAX;
        int count = 0;
        int start = -1;
        int n = s.size(), m = t.size();
        map<char, int> mp;
        for (int i = 0; i < m; i++)
        {
            if (mp[t[i]] == 0)
                count++;
            mp[t[i]]++;
        }
        while (j < n)
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
            if (count == 0)
            {
                while (count == 0)
                {
                    if (resLen > (j - i + 1))
                    {
                        resLen = min(resLen, j - i + 1);
                        start = i;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if (start == -1)
            return "";
        string res;
        for (int i = start; i < start + resLen; i++)
        {
            res += s[i];
        }
        return res;
    }
};