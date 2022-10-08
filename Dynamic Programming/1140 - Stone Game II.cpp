// Problem Link: https://leetcode.com/problems/stone-game-ii/

// time Complexity: O(N * 2 * N * 2)
// Space Complexity: O(N * N * 2)

class Solution
{
private:
    int dp[101][201][2];

    int func(int idx, int n, int m, bool aliceTurns, vector<int> &piles)
    {
        if (idx >= n)
            return 0;
        if (dp[idx][m][aliceTurns] != -1)
            return dp[idx][m][aliceTurns];

        int sum = 0;
        int maxSum;
        if (aliceTurns)
        {
            maxSum = INT_MIN;
            for (int x = idx; x < idx + 2 * m; x++)
            {
                if (x < n)
                {
                    sum += piles[x];
                    int newM = max(m, x - idx + 1);
                    if (aliceTurns)
                        maxSum = max(maxSum, sum + func(x + 1, n, newM, (aliceTurns ^ 1), piles));
                }
            }
        }
        else
        {
            maxSum = INT_MAX;
            for (int x = idx; x < idx + 2 * m; x++)
            {
                if (x < n)
                {
                    int newM = max(m, x - idx + 1);
                    maxSum = min(maxSum, func(x + 1, n, newM, aliceTurns ^ 1, piles));
                }
            }
        }
        return dp[idx][m][aliceTurns] = maxSum;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        int aliceTurns = 1;
        int m = 1;
        int maxSumAlice = func(0, n, m, aliceTurns, piles);
        return maxSumAlice;
    }
};