// Problem Link: https://leetcode.com/problems/count-prefixes-of-a-given-string/

// Time Complexity: O(N)
// Space Complexity: O(N * (N + 1) / 2) -> N is the size of string

class Solution
{
private:
    set<string> st;
    void allPrefixesOfString(string s)
    {
        int n = s.size();
        string temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(s[i]);
            st.insert(temp);
        }
    }

public:
    int countPrefixes(vector<string> &words, string s)
    {
        allPrefixesOfString(s);
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.find(words[i]) != st.end())
                count++;
        }
        return count;
    }
};