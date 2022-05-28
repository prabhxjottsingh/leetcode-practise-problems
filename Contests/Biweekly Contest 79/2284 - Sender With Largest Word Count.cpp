// Problem Link: https://leetcode.com/problems/sender-with-largest-word-count/

// Time Complexity: O(N * M)
// Space Complexity: O(N)

class Solution
{
private:
    int countWords(string res)
    {
        int count = 1;
        int n = res.size();
        for (int i = 0; i < n; i++)
        {
            if (res[i] == ' ')
                count++;
        }
        return count;
    }

public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> mp;
        int n = senders.size();
        for (int i = 0; i < n; i++)
        {
            mp[senders[i]] += countWords(messages[i]);
        }
        string res;
        int maxWords = -1;
        for (auto &a : mp)
        {
            if (a.second >= maxWords)
            {
                maxWords = a.second;
                res = a.first;
            }
        }
        return res;
    }
};