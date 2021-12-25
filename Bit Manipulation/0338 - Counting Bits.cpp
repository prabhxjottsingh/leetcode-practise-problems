//Tags: Easy, Bits
//Problem Link: https://leetcode.com/problems/counting-bits/
//Time Complexity: O(n+1), constant

//Approach: We are using rigth shift operator which basically make us kind of iterate through every bit of integer n
//and if the AND of that bit with either 1 or we can say not equal to zero, then it is a set bit, and count++, then return count.

class Solution
{
private:
    int numberOfBits(int n)
    {
        int count = 0;
        for (int j = 0; j < 32; j++)
        {
            if (((n >> j) & 1) != 0)
                count++;
        }
        return count;
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++)
        {
            ans.push_back(numberOfBits(i));
        }
        return ans;
    }
};