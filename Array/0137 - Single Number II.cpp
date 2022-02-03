//Problem Link: https://leetcode.com/problems/single-number-ii/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto a : mp)
        {
            if (a.second == 1)
                return a.first;
        }
        return -1;
    }
};