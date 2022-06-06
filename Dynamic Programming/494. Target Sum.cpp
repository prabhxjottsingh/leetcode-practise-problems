class Solution
{
private:
    int func(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int idx = 1; idx <= n; idx++)
        {
            for (int targetSum = 0; targetSum <= sum; targetSum++)
            {
                int caseOne = dp[idx - 1][targetSum];
                int caseTwo = 0;
                if (nums[idx - 1] <= targetSum)
                    caseTwo = dp[idx - 1][targetSum - nums[idx - 1]];
                dp[idx][targetSum] = caseOne + caseTwo;
            }
        }
        return dp[n][sum];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum < target)
            return 0;
        if (((sum + target) & 1) || (sum + target < 0))
            return 0;
        int targetSum = (sum + target) / 2;
        int count = func(nums, targetSum);
        return count;
    }
};