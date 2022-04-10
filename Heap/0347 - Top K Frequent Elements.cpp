// Problem Link:

// Time Complexity:  O(n * log n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        for (auto &a : freq)
        {
            minHeap.push({a.second, a.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> res;
        while (k--)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};

//Time Complexity: 
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