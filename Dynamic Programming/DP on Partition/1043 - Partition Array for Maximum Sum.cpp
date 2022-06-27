class Solution
{
private:
    int dp[503];
    int func(int idx, int k, int n, vector<int> &arr)
    {
        if (idx == n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int maxi = 0, maxRes = 0;
        int len = 0;
        for (int j = idx; j < min(idx + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + func(j + 1, k, n, arr);
            maxRes = max(maxRes, sum);
        }
        return dp[idx] = maxRes;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        int res = func(0, k, n, arr);
        return res;
    }
};