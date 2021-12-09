//Tag: Medium
//Problem Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
//Time Complexity: O(n)
//Space Complexity: constant

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int high = *max_element(nums.begin(), nums.end());
        int low = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int highIndex, lowIndex;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == high)
                highIndex = i;
            if (nums[i] == low)
                lowIndex = i;
        }

        int a = n + highIndex - lowIndex + 1;     //if highest one and lowest are at last and first
        int b = n - highIndex + lowIndex + 1;     //if highest one and lowest one are at first and last
        int c = max(highIndex + 1, lowIndex + 1); // if lowest one and highest one are at first
        int d = max(n - highIndex, n - lowIndex); //if highest and lowest are present at last

        if (lowIndex == highIndex)
            return n;
        else
            return min(min(a, b), min(c, d));
    }
};