//Problem Link: https://leetcode.com/problems/maximum-subarray/
//Time Complexity: O(n)
//Space Complexity: O(1) (constant)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};