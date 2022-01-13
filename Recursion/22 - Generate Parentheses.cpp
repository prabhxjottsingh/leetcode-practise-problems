//Tags: Medium, Resursion
//Problem Link: https://leetcode.com/problems/generate-parentheses/
//Time Complexity:

class Solution
{
private:
    vector<string> ans;
    void generateParenthesis(int open, int close, string s)
    {
        if ((open == 0) && (close == 0))
        {
            ans.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            generateParenthesis(open - 1, close, s);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                generateParenthesis(open, close - 1, s);
                s.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string s;
        generateParenthesis(n, n, s);
        return ans;
    }
};