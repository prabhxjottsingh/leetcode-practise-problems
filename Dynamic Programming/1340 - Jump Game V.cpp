// Problem Link: https://leetcode.com/problems/jump-game-v/description/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
private:
    int dp[1001];

    int func(int idx, vector<int> &arr, int d)
    {
        int forw = idx + d;
        int back = idx - d;
        int n = arr.size();
        if (dp[idx] != -1)
            return dp[idx];
        int forwStepsCount = 0;
        int backStepsCount = 0;
        int maxInBetween = 0;
        for (int i = idx + 1; i < min(n, forw + 1); i++)
        {
            maxInBetween = max(maxInBetween, arr[i]);
            if (maxInBetween < arr[idx])
                forwStepsCount = max(forwStepsCount, 1 + func(i, arr, d));
            else
                break;
        }
        maxInBetween = 0;
        for (int i = idx - 1; i > max(-1, back - 1); i--)
        {
            maxInBetween = max(maxInBetween, arr[i]);
            if (maxInBetween < arr[idx])
                backStepsCount = max(backStepsCount, 1 + func(i, arr, d));
            else
                break;
        }
        return dp[idx] = max(forwStepsCount, backStepsCount);
    }

public:
    int maxJumps(vector<int> &arr, int d)
    {
        int maxJumps = 0;
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == -1)
                maxJumps = max(maxJumps, 1 + func(i, arr, d));
            else
                maxJumps = max(maxJumps, dp[i]);
        }
        return maxJumps;
    }
};