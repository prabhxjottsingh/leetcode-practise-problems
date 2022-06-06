// Problem Link: https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

bool helperFunc(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
    {
        if (target == arr[0])
            return true;
        return false;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool caseTwo = false, caseOne = false;
    if (arr[idx] <= target)
        caseOne = helperFunc(idx - 1, arr, target - arr[idx], dp);
    caseTwo = helperFunc(idx - 1, arr, target, dp);
    return dp[idx][target] = (caseOne | caseTwo);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    bool flag = helperFunc(n - 1, arr, k, dp);
    return flag;
}