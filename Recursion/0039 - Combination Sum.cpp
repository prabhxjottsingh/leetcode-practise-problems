//Tags: Medium, Recursion
//Problem Link: https://leetcode.com/problems/combination-sum/
//Time Complexity:
//Space Complexity:

class Solution
{
private:
    vector<vector<int>> ans;

    void findCombinations(int idx, vector<int> &temp, vector<int> candidates, int target)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
                ans.push_back(temp);
            return;
        }
        if (candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            findCombinations(idx, temp, candidates, target - candidates[idx]);
            temp.pop_back();
        }
        findCombinations(idx + 1, temp, candidates, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        findCombinations(0, temp, candidates, target);
        return ans;
    }
};
