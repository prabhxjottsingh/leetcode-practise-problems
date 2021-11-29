// Tags: Array
// Difficulty: Medium
//Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
//Time Complexity: O(n logn)


class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};