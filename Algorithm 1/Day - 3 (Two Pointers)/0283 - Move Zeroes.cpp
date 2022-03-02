// Problem Link: https://leetcode.com/problems/move-zeroes/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> finalAns(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                finalAns[right] = nums[i];
                right--;
            }
            else
            {
                finalAns[left] = nums[i];
                left++;
            }
        }
        nums = finalAns;
    }
};