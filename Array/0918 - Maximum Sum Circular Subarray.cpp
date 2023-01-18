// Problem Link: https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int currMax = 0;
        int currMin = 0;
        int maxx = -1e9;
        int minn = 1e9;
        int sum = 0;
        for (auto &a : nums)
        {
            currMax = max(currMax + a, a);
            currMin = min(currMin + a, a);
            maxx = max(maxx, currMax);
            minn = min(minn, currMin);
            sum += a;
        }
        if (sum == minn)
            return maxx;
        return max(maxx, sum - minn);
    }
};