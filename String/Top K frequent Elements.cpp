// Tags: String
// Difficulty: Medium
//Problem Link: https://leetcode.com/problems/top-k-frequent-elements/
//Time Complexity: this can be reduced with hlp of priority queue, need toi study that asap

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto m : mp)
        {
            v.push_back({m.second, m.first});
        }
        sort(v.rbegin(), v.rend());
        for (auto m : v)
        {
            ans.push_back(m.second);
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};