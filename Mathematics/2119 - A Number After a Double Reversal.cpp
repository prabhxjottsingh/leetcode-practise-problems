//Tag: Easy, MAthematics
//Problem Link: https://leetcode.com/problems/a-number-after-a-double-reversal/
//Time Complexity: O(n) ,where n is the number of digits in the integer

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        int x = num;
        int reversed1 = 0;
        while (num)
        {
            int r = num % 10;
            reversed1 = reversed1 * 10 + r;
            num /= 10;
        }
        int reversed2 = 0;
        while (reversed1)
        {
            int r = reversed1 % 10;
            reversed2 = reversed2 * 10 + r;
            reversed1 /= 10;
        }
        if (reversed2 == x)
            return true;
        return false;
    }
};