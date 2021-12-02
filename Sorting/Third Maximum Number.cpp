//Tag: Easy
//Space Complexity: O(1) Constant
//Time Complxity: O(n)
//Problem Link:https://leetcode.com/problems/third-maximum-number/

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.rbegin(), nums.rend());
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != nums[i + 1])
                count++;
            if (count == 2)
                return nums[i + 1];
        }
        return nums[0];
    }
};