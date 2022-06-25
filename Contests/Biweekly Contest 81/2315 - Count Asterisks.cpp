// Problem Link: https://leetcode.com/problems/count-asterisks/

// Time Complexity: O(N)
// Space Complexity: O(!)

class Solution
{
public:
    int countAsterisks(string s)
    {
        int n = s.size();
        int count = 0;
        int pair = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (pair % 2 == 0)
                    count++;
            }
            if (s[i] == '|')
                pair++;
        }
        return count;
    }
};