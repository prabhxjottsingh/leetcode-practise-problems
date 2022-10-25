class Solution
{
private:
    class DSU
    {
    private:
        vector<int> par;
        vector<int> size;
        int maxSize;

    public:
        DSU(int n)
        {
            par.resize(n);
            size.resize(n);
            maxSize = n;
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

public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        DSU dsuSt(V);
        for (int i = 0; i < V; i++)
        {
            for (auto &a : adj[i])
            {
                int u = i;
                int v = a[0];
                int wt = a[1];
                pq.push({wt, {u, v}});
            }
        }
        int sum = 0;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int wt = front.first;
            int u = front.second.first;
            int v = front.second.second;
            if (dsuSt.parent(u) == dsuSt.parent(v))
                continue;
            dsuSt.Union(u, v);
            sum += wt;
        }
        return sum;
    }
};