// Tag: Medium
// Problem Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Time Complexity: O(n+n)
// Space Complexity: O(n)

string minRemoveToMakeValid(string s)
{
    string ans = "";
    stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (st.empty())
                continue;
            else
                st.pop();
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        ans.push_back(s[i]);
        // cout<<s[i]<<"->"<<ans<<endl;
    }
    // cout<<endl;
    string finalAns = "";
    if (st.empty())
        return ans;
    else
    {
        int m = ans.size();
        for (int i = m - 1; i >= 0; i--)
        {
            if (!st.empty() && ans[i] == '(')
            {
                st.pop();
                continue;
            }
            else
                finalAns.push_back(ans[i]);
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
    }
}

//<-----------------------------------------------------------||----------------------------------------->
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        vector<int> removedClosed, removedOpen;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    removedClosed.push_back(i);
                }
                else
                    st.pop();
            }
        }
        while (!st.empty())
        {
            removedOpen.push_back(st.top());
            st.pop();
        }
        sort(removedOpen.begin(), removedOpen.end());
        string res;
        int idxOpen = 0, idxClose = 0;
        int n = removedOpen.size();
        int m = removedClosed.size();
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (idxOpen < n && removedOpen[idxOpen] == i)
                {
                    idxOpen++;
                    continue;
                }
            }
            else if (s[i] == ')')
            {
                if (idxClose < m && removedClosed[idxClose] == i)
                {
                    idxClose++;
                    continue;
                }
            }
            res += s[i];
        }
        return res;
    }
};