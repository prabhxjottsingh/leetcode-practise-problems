//Tag: Easy
//Problem Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
//Time Complexity: O(num)
//Space Complexity: constant

class Solution
{
public:
    int count = 0;
    int numberOfSteps(int num)
    {
        if (num == 0)
            return count;
        count++;
        if (num % 2 == 0)
            return numberOfSteps(num / 2);
        else
            return numberOfSteps(num - 1);
    }
};