//Problem Link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < maxi && nums[i] > mini)
                count++;
        }
        return count;
    }
};