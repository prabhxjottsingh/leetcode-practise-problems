// Tags: String
// Difficulty: Medium
//Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/
//Time Complexity: O(n + nlog n)

class Solution
{
public:
    static bool conditionSort(const pair<char, int> &a, const pair<char, int> &b)
    {
        if (a.second == b.second)
            return (a.first > b.first);
        return (a.second > b.second);
    }

    string frequencySort(string s)
    {
        map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        vector<pair<char, int>> pr;
        for (auto ans : mp)
            pr.push_back({ans.first, ans.second});
        sort(pr.begin(), pr.end(), conditionSort);
        string ans;
        for (auto p : pr)
        {
            while (p.second)
            {
                ans.push_back(p.first);
                p.second--;
            }
        }
        return ans;
    }
};