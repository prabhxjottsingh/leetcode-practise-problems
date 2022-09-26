// Problem Link: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        int m = maximumBit;
        vector<int> prevXOR;
        prevXOR.push_back(nums[0]);
        for (int i = 1; i < n; i++)
            prevXOR.push_back((prevXOR.back() ^ nums[i]));
        int temp = 0;
        for (int i = 0; i < m; i++)
            temp |= (1 << i);
        vector<int> res;
        for (int i = n - 1; i > -1; i--)
        {
            int x = prevXOR[i];
            int y = temp;
            int z = (temp ^ x);
            res.push_back(z);
        }
        return res;
    }
};