// Problem Link: https://leetcode.com/problems/valid-anagram/

// Time Complexity: O(n)
// Space Complexity: O(52)

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int a[26] = {0}, i;
        int b[26] = {0};
        int x = s.length(), y = t.length();
        if (x != y)
            return 0;
        for (i = 0; i < x; i++)
        {
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }
        for (i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }
};