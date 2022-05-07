// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Time Complexity: O(N * K)
// Space Complexoty: O(N)

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        int n = s.size();
        int tempK = k;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                pair<char, int> top = st.top();
                if (top.first == s[i])
                {
                    st.push({s[i], top.second + 1});
                }
                else
                {
                    st.push({s[i], 1});
                }
                top = st.top();
                if (top.second == k)
                {
                    while (tempK--)
                    {
                        st.pop();
                    }
                    tempK = k;
                }
            }
        }
        string res;
        while (!st.empty())
        {
            pair<char, int> top = st.top();
            res.push_back(top.first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};