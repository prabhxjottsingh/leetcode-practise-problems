//Tags: Array, Sorting, Medium
//Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//Time Complexity: Used the in-built function *min_element(v.begin(),v.end())
//Space Complexity: Constant

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return *min_element(nums.begin(), nums.end());
    }
};