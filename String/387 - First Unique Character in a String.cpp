//Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/
//Time Complexity: O(n)
//Space Complexity: O(26)

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int hshArray[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; i++)
            hshArray[s[i] - 'a'] += 1;
        for (int i = 0; i < n; i++)
        {
            if (hshArray[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};