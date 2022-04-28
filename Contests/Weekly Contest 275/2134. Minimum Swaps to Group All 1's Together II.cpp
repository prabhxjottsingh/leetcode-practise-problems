// Problem Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// Time Complexity: O(N)
// Space Complexity: O(1)

//Using the concept of Sliing Window

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                count++;
            nums.push_back(nums[i]);
        }
        int countZero = 0;
        for (int i = 0; i < count; i++)
        {
            if (nums[i] == 0)
                countZero++;
        }
        int res = countZero;
        int left = 0, right = count;
        while (right < nums.size())
        {
            if (nums[left] == 0)
                countZero--;
            if (nums[right] == 0)
                countZero++;
            left++;
            right++;
            res = min(res, countZero);
        }
        return res;
    }
};