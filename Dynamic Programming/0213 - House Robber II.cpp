// Problem Link: https://leetcode.com/problems/house-robber-ii/

// Time Complexity: O(N)
// Space COomplexity: O(N) + O(N)

class Solution
{
private:
    int dp[100003];

    int func(int n, vector<int> &v)
    {
        if (n == 0)
            return dp[0] = v[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int firstPick = v[n] + func(n - 2, v);
        int secondPick = func(n - 1, v);
        int finalPick = max(firstPick, secondPick);
        return dp[n] = finalPick;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> tempOne, tempTwo;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                tempOne.push_back(nums[i]);
            if (i != n - 1)
                tempTwo.push_back(nums[i]);
        }
        memset(dp, -1, sizeof(dp));
        int sumFirst = func(tempOne.size() - 1, tempOne);
        memset(dp, -1, sizeof(dp));
        int sumSecond = func(tempTwo.size() - 1, tempTwo);
        return max(sumFirst, sumSecond);
    }
};