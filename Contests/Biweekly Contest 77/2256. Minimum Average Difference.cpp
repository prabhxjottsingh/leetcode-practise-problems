// Problem Link: https://leetcode.com/problems/minimum-average-difference/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long int> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        long long int res = 0, minNum = 1e9;
        n = preSum.size();
        for (int i = 0; i < n; i++)
        {
            long long int left = preSum[i] / (i + 1);
            long long int right;
            if (n - i - 1 == 0)
                right = 0;
            else
                right = (preSum[n - 1] - preSum[i]) / (n - i - 1);
            long long int avg = abs(left - right);
            if (minNum > avg)
                res = i;
            minNum = min(minNum, avg);
        }
        return res;
    }
};