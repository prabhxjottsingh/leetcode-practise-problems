// Problem Link: https://leetcode.com/problems/longest-common-prefix/
// Time Complexity: O(N * M)
// space Complexity: O(M)

class Solution
{
private:
    stack<char> insertStringinStack(string str)
    {
        stack<char> st;
        for (auto &s : str)
            st.push(s);
        return st;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        stack<char> st;
        string firstStr = strs[0];
        for (auto &s : firstStr)
            st.push(s);

        for (auto &str : strs)
        {
            stack<char> tempStack = insertStringinStack(str);

            while (tempStack.size() > st.size())
                tempStack.pop();

            while (st.size() > tempStack.size())
                st.pop();

            while (!st.empty() && st != tempStack)
            {
                st.pop();
                tempStack.pop();
            }
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