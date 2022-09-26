// Problem Link: https://leetcode.com/problems/satisfiability-of-equality-equations/

// Time Complexity: O()
// Space Complexity: O()

//Union - Find

class Solution
{
private:
    int par[26];
    int size[26];

    void init()
    {
        for (int i = 0; i < 26; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int x)
    {
        if (par[x] == x)
            return x;
        return (par[x] = findPar(par[x]));
    }

    void Union(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            par[b] = a;
            size[a] += size[b];
        }
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        init();
        for (auto &eq : equations)
        {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            if (eq[1] == eq[2])
            {
                Union(u, v);
            }
        }

        for (auto &eq : equations)
        {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            if (eq[1] != eq[2])
            {
                if (findPar(u) == findPar(v))
                    return false;
            }
        }
        return true;
    }
};