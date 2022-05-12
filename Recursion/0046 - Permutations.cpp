// Tags: Medium, Recursion
// Problem Link: https://leetcode.com/problems/permutations/
// Time Complexity:
// Space Complexity:

class Solution
{
private:
    vector<vector<int>> ans;
    void recPermute(vector<int> nums, vector<int> &v, map<int, bool> freq)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                freq[i] = 1;
                v.push_back(nums[i]);
                recPermute(nums, v, freq);
                v.pop_back();
                freq[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        map<int, bool> freq;
        recPermute(nums, temp, freq);
        return ans;
    }
};

//<--------------------------------!!!---------------------------------->
class Solution
{
private:
    vector<vector<int>> finalVec;

    void helperFunction(int idx, vector<int> &nums)
    {
        if (idx == (int)nums.size())
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        helperFunction(0, nums);
        return finalVec;
    }
};