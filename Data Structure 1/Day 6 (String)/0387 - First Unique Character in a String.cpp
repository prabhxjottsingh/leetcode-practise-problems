// Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/submissions/

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

//Fast
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};