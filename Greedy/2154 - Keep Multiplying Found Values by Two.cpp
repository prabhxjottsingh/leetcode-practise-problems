//Problem Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
//Time Complexity:
//Space Complexity: O(1)

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        while (find(nums.begin(), nums.end(), original) != nums.end())
        {
            original *= 2;
        }
        return original;
    }
};