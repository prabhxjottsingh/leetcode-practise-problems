// Problem Link: https://leetcode.com/problems/permutations-ii/

// Time Complexity:
// Space Complextity:

class Solution
{
private:
    vector<vector<int>> finalVec;

    void helperFunction(int idx, vector<int> nums)
    {
        if (idx == nums.size())
        {
            if (find(finalVec.begin(), finalVec.end(), nums) == finalVec.end())
                finalVec.push_back(nums);
            return;
        }
        for (int i = idx; i < (int)nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            helperFunction(idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        helperFunction(0, nums);
        return finalVec;
    }
};