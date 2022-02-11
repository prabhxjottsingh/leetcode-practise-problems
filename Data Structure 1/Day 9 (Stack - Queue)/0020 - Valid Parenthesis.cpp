// Problem Link: https://leetcode.com/problems/valid-parentheses/

// Time Compleity:O(n)
// Space Complexity: O(n)

class Solution
{
public:
    map<char, int> mp = {{'(', -1}, {')', 1}, {'[', -2}, {']', 2}, {'{', -3}, {'}', 3}};
    bool isValid(string s)
    {

        stack<char> paren;
        for (char &c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                paren.push(c);
                break;
            case ')':
                if (paren.empty() || paren.top() != '(')
                    return false;
                else
                    paren.pop();
                break;
            case '}':
                if (paren.empty() || paren.top() != '{')
                    return false;
                else
                    paren.pop();
                break;
            case ']':
                if (paren.empty() || paren.top() != '[')
                    return false;
                else
                    paren.pop();
                break;
            default:; // pass
            }
        }
        return paren.empty();
    }
};