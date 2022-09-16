// Problem link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

// Time Complexity: O(M * M)
// Space Complexity: O(M * M)

class Solution
{
private:
    int func(int idx, int i, int j, int m, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp)
    {
        if (idx == (int)multipliers.size())
            return 0;
        if (dp[i][j % m] != -123)
            return dp[i][j % m];
        int caseOne = multipliers[idx] * nums[i] + func(idx + 1, i + 1, j, m, nums, multipliers, dp);
        int caseTwo = multipliers[idx] * nums[j] + func(idx + 1, i, j - 1, m, nums, multipliers, dp);
        return dp[i][j % m] = max(caseOne, caseTwo);
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, -123));
        int maxScore = func(0, 0, n - 1, m, nums, multipliers, dp);
        return maxScore;
    }
};