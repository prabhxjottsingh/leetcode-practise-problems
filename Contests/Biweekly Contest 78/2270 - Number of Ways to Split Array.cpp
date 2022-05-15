// Problem Link: https://leetcode.com/problems/number-of-ways-to-split-array/

// Space Complexity: O(N)
// Time COmplexity: O(N)

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        vector<long long int> prefixSum;
        if ((int)nums.size() == 0)
            return 0;
        int n = nums.size();
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long int firstSum = prefixSum[i];
            long long int lastSum = prefixSum[n - 1] - prefixSum[i];
            if (firstSum >= lastSum)
                count++;
        }
        return count;
    }
};