// Problem Link: https://leetcode.com/problems/running-sum-of-1d-array/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < (int)nums.size(); i++)
            res.push_back(nums[i] + res.back());
        return res;
    }
};