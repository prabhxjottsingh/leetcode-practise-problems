//Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
//Tags: Medium, Stacks
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
private:
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            if (tokens[i].size() != 1)
            {
                stringstream ss;
                int x;
                ss << tokens[i];
                ss >> x;
                st.push(x);
            }
            else if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(y + x);
                if (tokens[i] == "-")
                    st.push(y - x);
                if (tokens[i] == "/")
                    st.push(y / x);
                if (tokens[i] == "*")
                    st.push(y * x);
            }
            else
            {
                stringstream ss;
                ss << tokens[i];
                int x;
                ss >> x;
                st.push(x);
            }
        }
        return st.top();
    }
};