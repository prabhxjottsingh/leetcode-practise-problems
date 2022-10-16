class Solution
{
private:
    int dp[301][11];
    int func(int idx, int n, vector<int> &nums, int d)
    {
        if (idx == n || d < 0)
        {
            if (d == 0)
                return 0;
            return 1e9;
        }
        if (dp[idx][d] != -1)
            return dp[idx][d];
        int diff = nums[idx], resDiff = 1e9;
        for (int i = idx; i < n; i++)
        {
            diff = max(diff, nums[i]);
            resDiff = min(resDiff, func(i + 1, n, nums, d - 1) + diff);
        }
        return dp[idx][d] = resDiff;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        memset(dp, -1, sizeof(dp));
        int n = jobDifficulty.size();
        int totalDifficulty = func(0, n, jobDifficulty, d);
        if (totalDifficulty >= 1e9)
            return -1;
        return totalDifficulty;
    }
};