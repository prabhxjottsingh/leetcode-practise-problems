// Problem Link: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

// Time Complexity: O(n)
// Space Complexity: O(N)

class Solution
{
public:
    string robotWithString(string s)
    {
        stack<char> st;
        string resStr;
        int n = s.size();
        vector<char> vec(n);
        char ch = 'z';
        for (int i = n - 1; i >= 0; i--)
        {
            ch = min(ch, s[i]);
            vec[i] = ch;
        }
        for (int i = 0; i < n; i++)
        {
            char a = s[i];
            if (!st.empty())
            {
                while (!st.empty() && (vec[i] >= st.top()))
                {
                    resStr += st.top();
                    st.pop();
                }
            }
            st.push(a);
        }
        while (!st.empty())
            resStr += st.top(), st.pop();
        return resStr;
    }
};