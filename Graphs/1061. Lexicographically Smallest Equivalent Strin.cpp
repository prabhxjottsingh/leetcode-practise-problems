// Problem Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

// Time Complexity: O(N)
// Space Complexity: O(26)

class DSU
{
public:
    vector<int> par;

    DSU()
    {
        par.resize(26);
        for (int i = 0; i < 26; i++)
            par[i] = i;
    }

    int findPar(int n)
    {
        if (par[n] == n)
            return n;
        return par[n] = findPar(par[n]);
    }

    void Union(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);
        if (a != b)
        {
            par[max(a, b)] = min(a, b);
        }
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size();
        DSU st;
        for (int i = 0; i < n; i++)
        {
            st.Union(s1[i] - 'a', s2[i] - 'a');
        }
        string resStr;
        for (auto &a : baseStr)
        {
            resStr.push_back(st.findPar(a - 'a') + 'a');
        }
        return resStr;
    }
};