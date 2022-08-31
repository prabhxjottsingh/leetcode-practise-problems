// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1

// Time Complexity: O(sum * n)
// Space Complexity: O(sum * n)

class Solution
{
public:
    vector<int> DistinctSum(vector<int> nums)
    {
        int sum = 0;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][nums[i - 1]] = 1;
            for (int j = 0; j <= sum; j++)
            {
                if (dp[i - 1][j])
                {
                    dp[i][j] = 1;
                    dp[i][j + nums[i - 1]] = 1;
                }
            }
        }
        for (int i = 0; i <= sum; i++)
        {
            if (dp[n][i])
                res.push_back(i);
        }
        return res;
    }
};