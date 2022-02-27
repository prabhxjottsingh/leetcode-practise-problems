// Problem Link: https://leetcode.com/problems/search-insert-position/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] >= target)
                return i;
        }
        return size;
    }
};

// Time Complexity: O(log N)
// Space Complexity: O(1)

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size();
        while (high > low)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] == target)
                return mid;
            else
            {
                high = mid - 1;
            }
        }
        if (low < nums.size() && nums[low] < target)
            return low + 1;
        return low;
    }
};