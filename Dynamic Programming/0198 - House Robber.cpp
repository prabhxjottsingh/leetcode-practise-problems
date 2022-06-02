// Problem Link: https://leetcode.com/problems/house-robber/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
private:
    int dp[1002];

    int func(int n, vector<int> &nums)
    {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int firstChoice = nums[n] + func(n - 2, nums);
        int secondChoice = func(n - 1, nums);
        int finalChoice = max(firstChoice, secondChoice);

        dp[n] = finalChoice;

        return dp[n];
    }

public:
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return func(n - 1, nums);
    }
};