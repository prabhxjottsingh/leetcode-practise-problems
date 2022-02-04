// Problem Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp[target - nums[i]] > 0)
            {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]] - 1);
                break;
            }
            mp[nums[i]] = i + 1;
        }
        return ans;
    }
};