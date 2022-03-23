// Problem Link: https://leetcode.com/problems/broken-calculator/

// Time Complexity: O(log Target)
// Space Complexity: O(1)

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int operations = 0;
        while (target > startValue)
        {
            if (target & 1)
                target++;
            else
                target /= 2;
            operations++;
        }
        operations += startValue - target;
        return operations;
    }
};