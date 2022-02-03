//Tags: Medium, Array
//Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//Time Complexity: O(N*log N)
//Space Complexity: O(1)

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (find(nums.begin(), nums.end(), target) != nums.end())
            return true;
        return false;
    }
};