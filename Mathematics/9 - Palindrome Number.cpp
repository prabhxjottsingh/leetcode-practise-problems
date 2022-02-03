//Problem Link: https://leetcode.com/problems/palindrome-number/
//Time Complexity: O([log10(n)]) -> to_string() -> function
//Space Complexity: O(n) -> because of string

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};

//Time Complexity: O(n) -> n = number of digits in the number
//Space Complexity: O(1)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return 0;
        int z = x;
        long long int y = 0;
        while (x)
        {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        cout << y << " ";
        if (y == z)
            return 1;
        return 0;
    }
};