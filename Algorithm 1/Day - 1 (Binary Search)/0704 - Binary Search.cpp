//Problem Link: https://leetcode.com/problems/binary-search/

//Time Complexity: O(log N)
//Space Complexity: O(1) -> Constant

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size();
        while (high > low)
        {
            int mid = ((high + low) >> 1);
            if (nums[mid] > target)
            {
                high = mid;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};