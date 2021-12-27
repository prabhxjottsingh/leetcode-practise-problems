//Tags: Stack, Medium
//Problem Link: https://leetcode.com/problems/validate-stack-sequences/
//Time Compxity: O(n)

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int n = pushed.size(), m = popped.size();
        int popCur = 0;
        for (int i = 0; (i < n) || (popCur < m); i++)
        {
            if (st.empty() && (i < n))
                st.push(pushed[i]);
            else if ((!st.empty()) && (i < n) && (st.top() != popped[popCur]))
            {
                st.push(pushed[i]);
            }
            else if ((!st.empty()) && st.top() == popped[popCur])
            {
                st.pop();
                popCur++;
                i--;
            }
            else
                popCur++;
        }
        if (st.empty())
            return true;
        return false;
    }
};