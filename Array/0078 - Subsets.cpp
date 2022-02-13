// Problem Link: https://leetcode.com/problems/subsets/

class Solution
{
private:
    void generateSubset(vector<int> &v, int i, vector<int> &temp, map<vector<int>, int> &mp, vector<vector<int>> &subset)
    {
        if (i == v.size())
        {
            if (!mp.count(temp))
                subset.push_back(temp);
            return;
        }
        temp.push_back(v[i]);
        generateSubset(v, i + 1, temp, mp, subset);
        temp.pop_back();
        generateSubset(v, i + 1, temp, mp, subset);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> subset;
        vector<int> temp;
        map<vector<int>, int> mp;
        generateSubset(nums, 0, temp, mp, subset);
        return subset;
    }
};