// Problem Link: https://leetcode.com/problems/add-digits/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int addDigits(int num)
    {
        int x = 0;
        do
        {
            x = 0;
            while (num)
            {
                x += (num % 10);
                num /= 10;
            }
            num = x;
        } while (num > 9);
        return x;
    }
};  