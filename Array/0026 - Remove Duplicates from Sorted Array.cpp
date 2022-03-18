// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0, right = 1, n = nums.size();
        while (right < n)
        {
            if (nums[left] != nums[right])
            {
                left++;
                nums[left] = nums[right];
                right++;
            }
            else
            {
                right++;
            }
        }
        return (left + 1);
    }
};