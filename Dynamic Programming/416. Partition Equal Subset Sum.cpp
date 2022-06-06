// Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
private:
    int dp[201][10003];

    bool func(int idx, vector<int> &nums, int sum)
    {
        if (sum == 0)
            return true;
        if (idx == 0)
        {
            if (nums[0] == sum)
                return true;
            return false;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        bool caseOne = false;
        if (nums[idx] <= sum)
            caseOne = func(idx - 1, nums, sum - nums[idx]);
        bool caseTwo = func(idx - 1, nums, sum);
        return dp[idx][sum] = (caseOne | caseTwo);
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum & 1)
            return false;
        bool isPossible = func(n - 1, nums, sum / 2);
        return isPossible;
    }
};