// Problem Link: https://leetcode.com/problems/split-array-largest-sum/
// Space Complexity: O(1) -> Constant
// Time Complexity: O(N * log N)

class Solution
{
private:
    bool isPossible(vector<int> v, int mid, int k)
    {
        int count = 0, sum = 0, n = v.size(), i;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
                return false;
            else if (sum + v[i] <= mid)
                sum += v[i];
            else
            {
                count++;
                sum = v[i];
            }
        }
        return (count <= k);
    }

public:
    int splitArray(vector<int> &nums, int m)
    {
        int low = INT_MAX, high = 0, sum = 0, ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            low = min(low, nums[i]);
            high += nums[i];
        }
        sum = high;
        while (high >= low)
        {
            int mid = low + ((high - low) >> 1);
            if (isPossible(nums, mid, m) == false)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
