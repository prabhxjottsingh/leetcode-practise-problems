// Problem link: https://leetcode.com/problems/break-a-palindrome/

// Time Complexity: O(26 * N)
// Space Complexity: O(N)

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        string resStr(n, 'z');
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != palindrome[n - i - 1])
                {
                    char orgChar = palindrome[i];
                    palindrome[i] = ch;
                    if (ch != palindrome[n - i - 1])
                    {
                        found = true;
                        resStr = min(resStr, palindrome);
                    }
                    palindrome[i] = orgChar;
                }
            }
        }
        if (found)
            return resStr;
        return "";
    }
};