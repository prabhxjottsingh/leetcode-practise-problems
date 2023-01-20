// Problem Link: https://leetcode.com/problems/non-decreasing-subsequences/description/

// Time Complexity: O(2 ^ N)
// Space Complexity: O(2 ^ N)

class Solution
{
private:
    void func(int idx, int n, vector<int> &nums, vector<int> &tVec, set<vector<int>> &resVec, int prev)
    {
        if (idx == n)
        {
            if (tVec.size() > 1)
                resVec.insert(tVec);
            return;
        }
        if (nums[idx] >= prev)
        {
            tVec.push_back(nums[idx]);
            func(idx + 1, n, nums, tVec, resVec, nums[idx]);
            tVec.pop_back();
        }
        func(idx + 1, n, nums, tVec, resVec, prev);
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> resVec;
        vector<int> tVec;
        func(0, nums.size(), nums, tVec, resVec, -1e9);
        vector<vector<int>> vc(resVec.begin(), resVec.end());
        return vc;
    }
};