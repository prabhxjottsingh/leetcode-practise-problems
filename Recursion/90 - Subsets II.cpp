//Tags: Medium, Recursion
//Problem Link: https://leetcode.com/problems/subsets-ii/
//Time Complexity:
//Space Complexity:

class Solution
{
private:
    vector<vector<int>> ans;
    void generateSubsets(int idx, vector<int> &v, vector<int> &arr)
    {
        if (idx == arr.size())
        {
            sort(v.begin(), v.end());
            if (find(ans.begin(), ans.end(), v) == ans.end())
            {
                ans.push_back(v);
            }
            return;
        }
        v.push_back(arr[idx]);
        generateSubsets(idx + 1, v, arr);
        v.pop_back();
        generateSubsets(idx + 1, v, arr);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        generateSubsets(0, temp, nums);
        return ans;
    }
};