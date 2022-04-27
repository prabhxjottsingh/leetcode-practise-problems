// Problem Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/


//Time Complexity: O(32)
//Space Complexity: O(1)

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((start & (1 << i)) != (goal & (1 << i)))
                count++;
        }
        return count;
    }
};