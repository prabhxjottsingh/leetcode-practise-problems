class Solution
{
private:
    vector<int> par;
    vector<int> size;

    void init(int n)
    {
        par.resize(n);
        size.resize(n);
    }

    void make(int i)
    {
        par[i] = i;
        size[i] = 1;
    }

    int findPar(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = findPar(par[u]);
    }

    void Union(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        if (u == v)
            return;
        if (size[u] < size[v])
            swap(u, v);
        par[v] = u;
        size[v] += size[u];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        init(n + 1);
        for (int i = 1; i <= n; i++)
            make(i);
        for (auto &a : edges)
        {
            int u = a[0];
            int v = a[1];
            if (findPar(u) != findPar(v))
                Union(u, v);
            else
                return {u, v};
        }
        return {};
    }
};