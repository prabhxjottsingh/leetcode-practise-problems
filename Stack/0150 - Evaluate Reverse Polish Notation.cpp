// Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Tags: Medium, Stacks
// Time Complexity: O(n)
// Space Complexity: O(n)

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

// Code After New TestCases
class Solution
{
private:
    long long StringToInt(string s)
    {
        bool neg = false;
        if (s[0] == '-')
            neg = true;
        long long val = 0;
        for (auto &a : s)
        {
            if (a == '-')
                continue;
            val = val * 1ll * 10 + (a - '0');
        }
        if (neg)
            val *= (-1ll);
        if (val > INT_MAX)
            return INT_MIN;
        return val;
    }

    string toString(long long val)
    {
        bool neg = false;
        string res;
        if (val < 0)
            neg = true, val *= (-1);
        while (val)
        {
            res.push_back((val % 10) + '0');
            val /= 10;
        }
        if (neg)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;
        for (auto &a : tokens)
        {
            if (a == "*" || a == "+" || a == "/" || a == "-")
            {
                long long oneVal = StringToInt(st.top());
                st.pop();
                long long twoVal = StringToInt(st.top());
                st.pop();
                if (a == "*")
                    st.push(toString(oneVal * twoVal));
                if (a == "+")
                    st.push(toString(oneVal + twoVal));
                if (a == "-")
                {
                    swap(oneVal, twoVal);
                    st.push(toString(oneVal - twoVal));
                }
                if (a == "/")
                {
                    swap(oneVal, twoVal);
                    st.push(toString(oneVal / twoVal));
                }
            }
            else
            {
                st.push(a);
            }
        }
        return StringToInt(st.top());
    }
};