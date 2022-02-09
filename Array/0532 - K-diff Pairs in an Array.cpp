// Problem Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        for (auto &a : mp)
        {
            if (k == 0)
            {
                if (a.second > 1)
                    count++;
            }
            else
            {
                if (mp[a.first] && mp[a.first + k] > 0)
                    count++;
            }
        }
        return count;
    }
};