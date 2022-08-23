// Problem Link: https://leetcode.com/problems/match-substring-after-replacement/
// Time Complexity: O(N * M * log M)
//Space Complexity: O(N * M)
//Difficulty: Hard

class Solution
{
private:
    bool isPossible(string &a, string b, unordered_map<char, unordered_set<char>> &mp)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i] && mp.count(b[i]))
            {
                if (!mp[b[i]].count(a[i]))
                    return 0;
            }
            else if (a[i] != b[i] && !mp.count(b[i]))
                return 0;
        }
        return 1;
    }

public:
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings)
    {
        unordered_map<char, unordered_set<char>> mp;
        for (auto &a : mappings)
            mp[a[0]].insert(a[1]);
        int n = s.size();
        int k = sub.size();
        for (int i = 0; i < n - k + 1; i++)
        {
            string str;
            for (int j = i; j < i + k; j++)
                str += s[j];
            if (isPossible(str, sub, mp))
                return true;
        }
        return false;
    }
};