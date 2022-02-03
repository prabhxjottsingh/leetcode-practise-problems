//Tags: Medium,
//Problem Link:https://leetcode.com/problems/longest-consecutive-sequence/
//Time Complexity:
//Space Complexity:

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int count = 1, finalCount = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == nums[i - 1] + 1)
                count++;
            else
                count = 1;
            finalCount = max(count, finalCount);
        }
        finalCount = max(count, finalCount);
        return finalCount;
    }
};