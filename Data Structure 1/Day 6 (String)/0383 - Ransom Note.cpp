// Problem Link: https://leetcode.com/problems/ransom-note/

// Time Complexity: O(n+m)
// Space Complexity: O(26)

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};
        int n = magazine.size(), m = ransomNote.size();
        for (int i = 0; i < n; i++)
        {
            hash[magazine[i] - 'a']++;
        }
        for (int i = 0; i < m; i++)
        {
            if (hash[ransomNote[i] - 'a'] > 0)
            {
                hash[ransomNote[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};