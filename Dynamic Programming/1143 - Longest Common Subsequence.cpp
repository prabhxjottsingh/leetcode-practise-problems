class Solution
{
private:
    int dp[1003][1003];
    int func(int idxOne, int idxTwo, string &a, string &b)
    {
        if (idxOne < 0 || idxTwo < 0)
            return 0;

        if (dp[idxOne][idxTwo] != -1)
            return dp[idxOne][idxTwo];

        if (a[idxOne] == b[idxTwo])
            return dp[idxOne][idxTwo] = (1 + func(idxOne - 1, idxTwo - 1, a, b));

        int caseOne = func(idxOne - 1, idxTwo, a, b);
        int caseTwo = func(idxOne, idxTwo - 1, a, b);

        return dp[idxOne][idxTwo] = max(caseOne, caseTwo);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        memset(dp, -1, sizeof(dp));
        int count = func(n - 1, m - 1, text1, text2);
        return count;
    }
};