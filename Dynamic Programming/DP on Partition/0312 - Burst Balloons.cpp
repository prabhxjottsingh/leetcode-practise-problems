class Solution
{
private:
    int dp[301][301];
    int func(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxCo = INT_MIN;
        for (int idx = i; idx <= j; idx++)
        {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1] + func(i, idx - 1, nums) + func(idx + 1, j, nums);
            maxCo = max(maxCo, cost);
        }
        return dp[i][j] = maxCo;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int coinsMax = func(1, n, nums);
        return coinsMax;
    }
};