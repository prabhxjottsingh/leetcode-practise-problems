// Problem Link: https://leetcode.com/problems/find-closest-number-to-zero/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int res = -1, minDist = 1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) < minDist)
            {
                res = (nums[i]);
                minDist = abs(nums[i]);
            }
            else if (minDist == abs(nums[i]))
                res = max(res, (nums[i]));
        }
        return res;
    }
};