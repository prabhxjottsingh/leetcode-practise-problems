// Tags: Array
// Difficulty: Mediu,
//Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
//Time Complexity: O(n)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        for (auto &ans : mp)
        {
            if (ans.second > 1)
                return ans.first;
        }
        return -1;
    }
};