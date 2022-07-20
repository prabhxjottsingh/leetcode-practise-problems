class Solution
{
private:
    int dp[203][1001];
    int func(int idx, int n, vector<int> &nums, int target)
    {
        if (target == 0)
            return 1;
        if (idx == n)
            return 0;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int caseOne = 0;
        if (nums[idx] <= target)
            caseOne = func(0, n, nums, target - nums[idx]);
        int caseTwo = func(idx + 1, n, nums, target);
        return dp[idx][target] = (caseOne + caseTwo);
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int count = func(0, n, nums, target);
        return count;
    }
};