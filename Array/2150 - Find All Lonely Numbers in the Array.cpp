//Problem Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto a : mp)
        {
            if (mp[a.first - 1] == 0 && mp[a.first + 1] == 0 && a.second == 1)
                ans.push_back(a.first);
        }
        return ans;
    }
};