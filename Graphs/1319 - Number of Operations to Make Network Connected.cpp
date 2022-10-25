// Problem Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Time Complexity: O(N)
// Space Complexity: O(N)

class DSU
{
private:
    vector<int> par;
    vector<int> size;

public:
    DSU(int n)
    {
        par.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i, size[i] = 1;
    }

    int parent(int n)
    {
        if (par[n] == n)
            return n;
        return par[n] = parent(par[n]);
    }

    void Union(int u, int v)
    {
        u = parent(u);
        v = parent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
            par[u] = v, size[v] += size[u];
        else
            par[v] = u, size[u] += size[v];
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DSU dsuSt(n);
        int extraWires = 0;
        for (auto &a : connections)
        {
            int u = a[0];
            int v = a[1];
            if (dsuSt.parent(u) == dsuSt.parent(v))
            {
                extraWires += 1;
                continue;
            }
            dsuSt.Union(u, v);
        }
        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(dsuSt.parent(i));
        int reqWires = st.size() - 1;
        if (reqWires > extraWires)
            return -1;
        return reqWires;
    }
};