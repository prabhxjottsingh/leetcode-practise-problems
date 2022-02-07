// Problem Link: https://leetcode.com/contest/biweekly-contest-71/problems/partition-array-according-to-given-pivot/
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans;
        vector<int> smaller, equal, greater;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
                smaller.push_back(nums[i]);
            else if (nums[i] > pivot)
                greater.push_back(nums[i]);
            else if (nums[i] == pivot)
                equal.push_back(nums[i]);
        }
        for (int i = 0; i < smaller.size(); i++)
            ans.push_back(smaller[i]);
        for (int i = 0; i < equal.size(); i++)
            ans.push_back(equal[i]);
        for (int i = 0; i < greater.size(); i++)
            ans.push_back(greater[i]);
        return ans;
    }
};