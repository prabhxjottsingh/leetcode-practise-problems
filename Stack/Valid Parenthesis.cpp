//Tag: Easy
//Problem Link: https://leetcode.com/problems/valid-parentheses/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    map<char, int> mp = {{'(', -1}, {')', 1}, {'[', -2}, {']', 2}, {'{', -3}, {'}', 3}};
    bool isValid(string s)
    {

        stack<char> st;

        int i, n = s.length();

        for (i = 0; i < n; i++)
        {
            if (mp[s[i]] < 0)
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                if (mp[st.top()] + mp[s[i]] != 0)
                    return false;
                else
                    st.pop();
            }
        }

        if (!st.empty())
            return false;
        return true;
    }
};

//Without Using Stack
class Solution {
public:
    map<char,int> mp ={{'(',-1}, {')',1}, {'[',-2}, {']',2}, {'{',-3}, {'}',3}};
    bool isValid(string s) {      
        
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};