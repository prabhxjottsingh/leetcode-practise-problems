// Problem Link: https://leetcode.com/problems/maximum-xor-after-operations/

class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int res = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
            res |= nums[i];
        return res;
    }
};