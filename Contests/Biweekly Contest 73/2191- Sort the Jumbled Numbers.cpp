// Problem Link: https://leetcode.com/problems/sort-the-jumbled-numbers/

// Time Complexity: O(N + (N*log N))
//Space Complexity: O(N)

class Solution
{
private:
    int newNumber(vector<int> mp, int x)
    {
        string s = to_string(x);
        int n = s.size();
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            int x = s[i] - '0';
            y = y * 10 + mp[x];
        }
        return y;
    }

    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return (a.second < b.second);
        }
        return (a.second < b.second);
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int y = newNumber(mapping, nums[i]);
            temp.push_back({x, y});
        }
        sort(temp.begin(), temp.end(), comp);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};