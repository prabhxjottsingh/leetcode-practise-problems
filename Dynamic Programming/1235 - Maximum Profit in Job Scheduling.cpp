// Problem Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Time Complexity: O(N log N)
// Space Complexity: O(N)

class Solution
{
private:
    static const int N = 5e4 + 7;
    int dp[N];

    class jobDetails
    {
    public:
        int start;
        int end;
        int pro;
    };

    static bool comp(const jobDetails &a, const jobDetails &b)
    {
        return a.start < b.start;
    }

    int binarySearch(int low, int high, vector<jobDetails> &nums, int k)
    {
        int res = high + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid].start < k)
                low = mid + 1, res = low;
            else
                high = mid - 1;
        }
        return res;
    }

    int func(int idx, int n, vector<jobDetails> &nums)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int findNextIdx = binarySearch(idx, n - 1, nums, nums[idx].end);
        int takeProfit = nums[idx].pro + func(findNextIdx, n, nums);
        int notTakeProfit = func(idx + 1, n, nums);
        return dp[idx] = max(takeProfit, notTakeProfit);
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        vector<jobDetails> vp;
        int n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            jobDetails obj;
            obj.start = startTime[i];
            obj.end = endTime[i];
            obj.pro = profit[i];
            vp.push_back(obj);
        }
        sort(vp.begin(), vp.end(), comp);
        int maxProfit = func(0, n, vp);
        return maxProfit;
    }
};