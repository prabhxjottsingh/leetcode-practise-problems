//Problem Link: https://leetcode.com/problems/smallest-range-ii/description/

//Time Complexity: O(N * log N)
//Space Complexity: O(1)

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int smallest = nums[0] + k;
        int n = nums.size();
        int largest = nums[n - 1] - k;
        int minDiff = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++)
        {
            int mn = min(smallest, nums[i + 1] - k);
            int mx = max(largest, nums[i] + k);
            // if( mn < 0 )
            //     continue;
            minDiff = min(minDiff, mx - mn);
        }
        return minDiff;
    }
};