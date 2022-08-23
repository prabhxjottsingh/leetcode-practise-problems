//Problem Link: https://leetcode.com/problems/strong-password-checker-ii/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        int n = password.size();
        bool isLen = n >= 8;
        bool isLower = false;
        bool isUpper = false;
        bool isDigit = false;
        bool isSpecial = false;
        char prev = '`';
        bool isPrevSame = false;
        for (auto &a : password)
        {
            if (a >= 'a' && a <= 'z')
                isLower = true;
            else if (a >= 'A' && a <= 'Z')
                isUpper = true;
            else if (a >= '0' && a <= '9')
                isDigit = true;
            else
                isSpecial = true;
            if (prev == a)
                isPrevSame = true;
            prev = a;
        }
        if (!isLen || !isLower || !isUpper || !isDigit || !isSpecial || isPrevSame)
            return false;
        return true;
    }
};