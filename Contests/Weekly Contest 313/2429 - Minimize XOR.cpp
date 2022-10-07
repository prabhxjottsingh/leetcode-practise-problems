// Problem Link: https://leetcode.com/problems/minimize-xor/

// Time Complexity: O(31)
// Space complexity: O(1)

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int countSetBits = __builtin_popcount(num2);
        int res = 0;
        for (int i = 31; i > -1 && countSetBits > 0; i--)
        {
            if ((num1 & (1 << i)) != 0)
                res |= (1 << i), countSetBits -= 1;
        }
        for (int i = 0; i < 31; i++)
        {
            if (countSetBits > 0 && ((res & (1 << i)) == 0))
                res |= (1 << i), countSetBits -= 1;
        }
        return res;
    }
};