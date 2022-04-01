// Problem Link: https://leetcode.com/problems/reverse-string/
// Time Complexity: O(N)
// Space Complexity: O(1) -> Constant Time

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0, last = s.size() - 1;
        while (start < last)
        {
            char ch = s[start];
            s[start] = s[last];
            s[last] = ch;
            start++;
            last--;
        }
    }
};