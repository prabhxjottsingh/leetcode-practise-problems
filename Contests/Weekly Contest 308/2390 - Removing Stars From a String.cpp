// Problem Link: https://leetcode.com/problems/removing-stars-from-a-string/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (auto &a : s)
        {
            if (a == '*')
                st.pop();
            else
                st.push(a);
        }
        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};