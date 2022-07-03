class Solution
{
private:
    int dp[1003][1003][4];

    int helperFunc(int idx, int prev, vector<int> &nums, int flag)
    {

        if (idx == nums.size())
            return 0;

        if (dp[idx][prev][flag] != -1)
            return dp[idx][prev][flag];

        int take = -1e6;
        int notTake = -1e6;

        if (flag == 1)
        {
            if (nums[idx] > prev)
                take = 1 + helperFunc(idx + 1, nums[idx], nums, 0);
            notTake = helperFunc(idx + 1, prev, nums, flag);
        }
        else if (flag == 0)
        {
            if (nums[idx] < prev)
                take = 1 + helperFunc(idx + 1, nums[idx], nums, 1);
            notTake = helperFunc(idx + 1, prev, nums, flag);
        }
        else
        {
            take = max(1 + helperFunc(idx + 1, nums[idx], nums, 1), 1 + helperFunc(idx + 1, nums[idx], nums, 0));
            notTake = helperFunc(idx + 1, prev, nums, flag);
        }

        return dp[idx][prev][flag] = max(take, notTake);
    }

public:
    int wiggleMaxLength(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int maxCount = helperFunc(0, 0, nums, 2);
        return maxCount;s
    }
};