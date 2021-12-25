//Tags: Easy, Bits
//Problem Link: https://leetcode.com/problems/number-of-1-bits/
//Time Complexity: O(1), constant

//Approach: We are using rigth shift operator which basically make us kind of iterate through every bit of integer n 
//and if the AND of that bit with either 1 or we can say not equal to zero, then it is a set bit, and count++, then return count.

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((n >> i) & 1) != 0)
                count++;
        }
        return count;
    }
};