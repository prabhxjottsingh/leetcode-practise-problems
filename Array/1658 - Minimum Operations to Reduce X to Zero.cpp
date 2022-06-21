// Problem Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        int maxOpt = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum < x)
            return -1;
        if (sum == x)
            return n;
        sum -= x;
        int curr = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            curr += nums[j];
            while (i < n && curr > sum)
            {
                curr -= nums[i];
                i++;
            }
            if (curr == sum)
                maxOpt = min(maxOpt, n - (j - i + 1));
        }
        if (maxOpt == INT_MAX)
            return -1;
        return maxOpt;
    }
};