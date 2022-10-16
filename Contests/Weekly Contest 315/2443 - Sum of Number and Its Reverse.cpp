// Problem Link: https://leetcode.com/problems/sum-of-number-and-its-reverse/

// Time Complexity: O(n)
//Space Complexity: O(1)

class Solution
{
private:
    int reverseOf(int x)
    {
        int num = 0;
        while (x)
        {
            int r = x % 10;
            num = num * 10 + r;
            x /= 10;
        }
        return num;
    }

public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            if (i + reverseOf(i) == num)
                return true;
        }
        return false;
    }
};