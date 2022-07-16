class Solution
{
private:
    map<int, int> dp;
    bool func(int idx, int n, int k, int tempSum, int targetSum, int mask, vector<int> &nums)
    {
        if (k == 0)
            return true;
        if (idx < 0)
        {
            if (tempSum == 0)
                return func(n - 1, n, k - 1, targetSum, targetSum, mask, nums);
            return false;
        }
        if (dp.count(mask))
            return dp[mask];
        bool flag;
        if ((mask & (1 << idx)) == 0 && nums[idx] <= tempSum)
        {
            flag = func(idx - 1, n, k, tempSum - nums[idx], targetSum, (mask | (1 << idx)), nums);
        }
        flag |= func(idx - 1, n, k, tempSum, targetSum, mask, nums);
        return dp[mask] = flag;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        int n = nums.size();
        int maxElem = 0;
        for (auto &a : nums)
        {
            sum += a;
            maxElem = max(maxElem, a);
        }
        if (sum % k || maxElem > sum / k)
            return false;
        bool flag;
        int tempSum = sum / k;
        int targetSum = sum / k;
        int mask = 0;
        flag = func(n - 1, n, k, tempSum, targetSum, mask, nums);
        return flag;
    }
};