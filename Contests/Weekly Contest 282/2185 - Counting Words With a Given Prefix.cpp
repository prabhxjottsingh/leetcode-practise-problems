// Problem Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/

// Time Complexity O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        int n = words.size(), m = pref.size();
        for (int i = 0; i < n; i++)
        {
            if (words[i].substr(0, m) == pref)
                count++;
        }
        return count;
    }
};