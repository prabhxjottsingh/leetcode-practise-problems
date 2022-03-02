// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

// Time Complexity: O(N + M) -> M = Number of words
// Space Complexity: O(1)

class Solution
{
private:
    void reverseWord(string &s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

public:
    string reverseWords(string s)
    {
        int n = s.size();
        string ans, temp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                reverseWord(temp);
                ans += temp;
                ans += " ";
                temp.clear();
            }
            else
            {
                temp += s[i];
            }
        }
        reverseWord(temp);
        ans += temp;
        return ans;
    }
};