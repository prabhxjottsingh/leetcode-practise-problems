// Problem Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// Time Complexity: O(Log N)
// Space Complexity: O(1)

class Solution
{
private:
    int check(vector<int> nums, int k)
    {
        int n = nums.size(), i = 0, j = 0, count = 0;
        for (i = 0; i < n; i++)
        {
            while (j < n && nums[j] - nums[i] <= k)
                j++;
            count += (j - i - 1);
        }
        return count;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = 10000009, mid;
        while (high > low)
        {
            mid = (high + low) >> 1;
            if (check(nums, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};