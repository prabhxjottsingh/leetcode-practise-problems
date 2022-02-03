//Tag: medium
//Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto m : mp)
        {
            if (m.second > 1)
                ans.push_back(m.first);
        }
        return ans;
    }
};