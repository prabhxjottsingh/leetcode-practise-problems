// Problem Link: https://leetcode.com/problems/backspace-string-compare/

// Time Complexity: O(max(N, M))
// Space Complexity: O(N + M)

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n = s.size();
        string newS;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#' && !newS.empty())
                newS.pop_back();
            else if (s[i] != '#')
                newS.push_back(s[i]);
        }
        int m = t.size();
        string newT;
        for (int i = 0; i < m; i++)
        {
            if (t[i] == '#' && !newT.empty())
                newT.pop_back();
            else if (t[i] != '#')
                newT.push_back(t[i]);
        }
        // cout << newS << endl;
        // cout << newT << endl;
        return (newT == newS);
    }
};

//We need to reduce space cpmplexity to O(1)
