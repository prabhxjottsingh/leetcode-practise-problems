//Problem Link: https://leetcode.com/problems/contains-duplicate/

//Time Complexity: O(n)
//Space Complexity: O(n) (Using Map Data Structure)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto a : mp)
        {
            if (a.second > 1)
                return 1;
        }
        return 0;
    }
};

//Time Complexity: O(n * log n)
//Space Complexity: O(1) 

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return 1;
        }
        return 0;
    }
};