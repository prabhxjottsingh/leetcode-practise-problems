// Problem Link: https://leetcode.com/problems/baseball-game/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
private:
    int stringToInt(string s)
    {
        int x;
        if (s[0] == '-')
            x = 1;
        else
            x = 0;
        int res = 0, i;
        int n = s.size();
        for (i = x; i < n; i++)
        {
            res = res * 10 + (s[i] - '0');
        }
        if (x == 1)
            res = res * (-1);
        return res;
    }

public:
    int calPoints(vector<string> &ops)
    {
        stack<int> st;
        int n = ops.size();
        for (int i = 0; i < n; i++)
        {
            if (ops[i] == "+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y);
                st.push(x);
                st.push(x + y);
            }
            else if (ops[i] == "C")
            {
                st.pop();
            }
            else if (ops[i] == "D")
            {
                int x = st.top();
                st.push(x * 2);
            }
            else
            {
                int y = stringToInt(ops[i]);
                st.push(y);
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};