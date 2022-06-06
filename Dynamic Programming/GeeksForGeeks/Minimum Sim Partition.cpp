class Solution
{
public:
    int minimumDifference(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            sum += abs(arr[i]);
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];
                dp[i][target] = (take | notTake);
            }
        }
        int minDiff = INT_MAX;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n - 1][i])
            {
                minDiff = min(minDiff, abs(i - (sum - i)));
                // cout << minDiff << " ";
            }
        }
        return minDiff;
    }
};