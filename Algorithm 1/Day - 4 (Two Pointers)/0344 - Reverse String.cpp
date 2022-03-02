// Problem Link: https://leetcode.com/problems/reverse-string/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};