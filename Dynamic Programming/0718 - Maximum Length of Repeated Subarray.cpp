// Problem Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// Time Complexity: O(N * M)
// space Complexity: O(M * M)

class Solution
{
private:
    int dp[1001][1001];
    int func(int i, int j, int n, int m, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == n || j == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (nums1[i] == nums2[j])
            return dp[i][j] = 1 + func(i + 1, j + 1, n, m, nums1, nums2);
        return dp[i][j] = 0;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        memset(dp, -1, sizeof(dp));
        int maxLen = -1;
        int n = nums1.size();
        int m = nums2.size();
        maxLen = max(maxLen, func(0, 0, n, m, nums1, nums2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxLen = max(maxLen, func(i, j, n, m, nums1, nums2));
            }
        }
        return maxLen;
    }
};