//Tags: Arrray, Medium, Binary SEarch
//Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
//Time Complexity: O(log n)
//Space Complexity: O(N) because of use of maps

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        sort(nums.begin(), nums.end());
        int low = 0, high = n - 1, mid = 0;
        while ((high - low) > 1)
        {
            mid = (high + low) / 2;
            if (nums[mid] == target)
                return mp[nums[mid]];
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (nums[mid] == target)
            return mp[nums[mid]];
        else if (nums[low] == target)
            return mp[nums[low]];
        else if (nums[high] == target)
            return mp[nums[high]];
        return -1;
    }
};

//Better Approach with constant space complexity

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1, mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[beg] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }

            else
            {
                if (target >= nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};