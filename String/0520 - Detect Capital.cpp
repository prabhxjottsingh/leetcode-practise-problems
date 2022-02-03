//Problem Link: https://leetcode.com/problems/detect-capital/
//Time Complexity: O(n)
//Space Complexity: O(1) -> Space Complexity

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        if (n == 1)
            return 1;
        if (islower(word[0]))
        {
            for (int i = 0; i < n; i++)
            {
                if (isupper(word[i]))
                    return 0;
            }
            return 1;
        }
        if (islower(word[1]))
        {
            for (int i = 1; i < n; i++)
            {
                if (isupper(word[i]))
                    return false;
            }
            return true;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (islower(word[i]))
                    return false;
            }
            return true;
        }
    }
};