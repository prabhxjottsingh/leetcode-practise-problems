//Tag: Easy
//Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string ans;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (!st.empty())
            {
                if (st.top() == s[i])
                    st.pop();
                else
                    st.push(s[i]);
                continue;
            }
            st.push(s[i]);
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
