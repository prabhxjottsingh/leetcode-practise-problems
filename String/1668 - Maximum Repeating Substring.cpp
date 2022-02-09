// Problem Link: https://leetcode.com/problems/maximum-repeating-substring/

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int n = sequence.size();
        string find = word;
        int count = 0, m = word.size();
        for (int i = 0; i < n; i++)
        {
            if (sequence.substr(i, m) == word)
            {
                count++;
                i = -1;
                word += find;
                m += find.size();
            }
        }
        return count;
    }
};