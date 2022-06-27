class Solution
{
private:
    int dp[101][101];
    int func(int i, int j, int arr[])
    {

        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;

        for (int k = i; k < j; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + func(i, k, arr) + func(k + 1, j, arr);
            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        int res = func(1, N - 1, arr);
        return res;
    }
};