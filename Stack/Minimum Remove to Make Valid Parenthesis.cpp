//Tag: Medium
//Problem Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//Time Complexity: O(n+n)
//Space Complexity: O(n)

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