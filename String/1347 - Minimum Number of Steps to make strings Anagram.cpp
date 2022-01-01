//Tags: String, Medium
//Problem Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
//Time Complexity: O(n + m)
//Space Complexity: O(n), because I have used the approach of map

class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> mp;
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            mp[t[i]]--;
        }
        for (auto &a : mp)
        {
            if (a.second > 0)
                count += a.second;
        }
        return count;
    }
};