// Problem Link: https://leetcode.com/problems/partition-labels/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> mp;
        for (auto &a : s)
        {
            mp[a]++;
        }
        vector<int> ans;
        set<char> st;
        int n = s.size(), i = 0, j = -1;
        while (i < n)
        {
            st.insert(s[i]);
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                st.erase(s[i]);
            }
            if (st.size() == 0)
            {
                ans.push_back(i - j);
                j = i;
            }
            i++;
        }
        return ans;
    }
};