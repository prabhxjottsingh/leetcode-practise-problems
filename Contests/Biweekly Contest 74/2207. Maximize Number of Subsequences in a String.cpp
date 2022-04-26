// Problem Link: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int n = text.size();
        long long int countOne = 0, countTwo = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (text[i] == pattern[0])
                countOne++;
            else if (text[i] == pattern[1])
            {
                ans += countOne;
                countTwo++;
            }
        }
        ans += max(countTwo, countOne);
        if (pattern[0] == pattern[1])
        {
            ans = countOne * (countOne + 1) / 2;
        }
        return ans;
    }
};