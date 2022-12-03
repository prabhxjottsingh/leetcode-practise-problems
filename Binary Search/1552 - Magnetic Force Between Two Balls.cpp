// Problem Link: https://leetcode.com/problems/magnetic-force-between-two-balls/

// Time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
private:
    bool isPossible(int x, vector<int> &nums, int cows)
    {
        int prev = nums[0];
        int n = nums.size();
        cows -= 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - prev >= x)
            {
                prev = nums[i];
                cows -= 1;
            }
            if (cows == 0)
                return true;
        }
        return cows == 0;
    }

public:
    int maxDistance(vector<int> &stalls, int m)
    {
        int low = 0;
        int high = 1e9;
        int res = 0;
        int count = 0;
        sort(stalls.begin(), stalls.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            count += 1;
            if (isPossible(mid, stalls, m))
                res = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    }
};