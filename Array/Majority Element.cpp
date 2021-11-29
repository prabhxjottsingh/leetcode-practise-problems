// Tags: Array
// Difficulty: Easy
//Problem Link: https://leetcode.com/problems/majority-element/
//Time Complexity: O(n)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto &ans : mp)
        {
            if (ans.second > (nums.size() / 2))
                return ans.first;
        }
        return -1;
    }
};