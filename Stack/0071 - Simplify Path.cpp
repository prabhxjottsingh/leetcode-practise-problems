// Problem Link: https://leetcode.com/problems/simplify-path/

// Space Complexity: O(N)
// Time Complexity: O(N)

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string temp = "";
        int n = path.size();
        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                if (temp.size() == 0)
                {
                    temp.clear();
                    continue;
                }
                else if (temp == ".")
                {
                    temp.clear();
                    continue;
                }
                else if (temp == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else
                {
                    st.push(temp);
                }
                temp.clear();
            }
            else
            {
                temp += path[i];
            }
        }
        if (temp == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else if (temp != "/" && temp != "" && temp != ".")
        {
            st.push(temp);
        }
        string ans;
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans.empty())
        {
            ans += '/';
        }
        return ans;
    }
};