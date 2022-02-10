// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum = 0, n = nums.size();
        map<int, int> values;
        values[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (values.count(sum - k))
                count += values[sum - k];
            values[sum]++;
        }
        return count;
    }
};