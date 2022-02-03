//Problem Link: https://leetcode.com/problems/two-sum/
//Time Complexity: O(n)
//Space Complexity: O(n) -> use of map

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = i + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mp[target - nums[i]] != (i + 1) && mp[target - nums[i]] != 0)
            {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]] - 1);
                return ans;
            }
        }
        return ans;
    }
};