class Solution
{
private:
    int dp[2502][2502];

    int func(int idx, int prevIdx, int n, vector<int> &nums)
    {

        if (idx == n)
            return 0;

        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        int len = func(idx + 1, prevIdx, n, nums);

        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
            len = max(len, 1 + func(idx + 1, idx, n, nums));

        return dp[idx][prevIdx + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return func(0, -1, nums.size(), nums);
    }
};

// Second Method
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int idx = n - 1; idx > -1; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                int len = dp[idx + 1][prevIdx + 1];
                if (prevIdx == -1 || nums[idx] > nums[prevIdx])
                    len = max(len, 1 + dp[idx + 1][idx + 1]);
                dp[idx][prevIdx + 1] = len;
            }
        }
        return dp[0][0];
    }
};

// Using Binary Search
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = 1;
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};