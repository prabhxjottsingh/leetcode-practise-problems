// Problem Link: https://leetcode.com/problems/divide-array-into-equal-pairs/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        if (mp.size() > n / 2)
            return false;
        for (auto &a : mp)
        {
            if (a.second & 1)
                return false;
        }
        return true;
    }
};