// Problem link: https://leetcode.com/problems/stone-game/

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution
{
private:
    int dp[501][501];

    long func(int i, int j, vector<int> &piles)
    {
        if (j < i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long caseFront = piles[i];
        caseFront += max(func(i + 2, j, piles), func(i + 1, j - 1, piles));
        long caseBack = piles[j];
        caseBack += max(func(i, j - 2, piles), func(i + 1, j - 1, piles));
        return dp[i][j] = max(caseFront, caseBack);
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        memset(dp, -1, sizeof(dp));
        long totalSum = 0;
        for (auto &a : piles)
            totalSum += a;
        int n = piles.size();
        long aliceMaxSum = func(0, n - 1, piles);
        long bobSum = totalSum - aliceMaxSum;
        return aliceMaxSum > bobSum;
    }
};