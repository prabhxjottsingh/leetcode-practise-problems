class Solution
{
private:
    class disjointSet
    {

    private:
        vector<int> par;
        vector<int> size;
        vector<int> rank;

    public:
        disjointSet(int n)
        {
            size.resize(n, 1);
            rank.resize(n, 0);
            par.resize(n);
            for (int i = 0; i < n; i++)
                par[i] = i;
        }

        int findPar(int n)
        {
            if (n == par[n])
                return n;
            return par[n] = findPar(par[n]);
        }

        void unionBySize(int u, int v)
        {
            u = findPar(u);
            v = findPar(v);
            if (u == v)
                return;
            if (size[u] < size[v])
            {
                par[u] = v;
                size[v] += size[u];
            }
            else
            {
                par[v] = u;
                size[u] += size[v];
            }
        }

        void unionByRank(int u, int v)
        {
            u = findPar(u);
            v = findPar(v);
            if (u == v)
                return;
            if (rank[u] < rank[v])
            {
                par[u] = v;
            }
            else if (rank[v] < rank[u])
                par[v] = u;
            else
            {
                par[v] = u;
                rank[u] += 1;
            }
        }
    };

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return true;
    }

    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        disjointSet st(n * m);
        int count = 0;

        int isVis[n][m];
        memset(isVis, 0, sizeof(isVis));

        vector<int> res;

        for (auto &a : operators)
        {
            int x = a[0];
            int y = a[1];

            if (isVis[x][y])
            {
                res.push_back(count);
                continue;
            }

            isVis[x][y] = 1;

            count++;
            for (auto &b : moves)
            {
                int nr = x + b.first;
                int nc = y + b.second;

                int node = x * m + y;
                int adjNode = nr * m + nc;

                if (isSafe(nr, nc, n, m) && isVis[nr][nc])
                {
                    if (st.findPar(node) != st.findPar(adjNode))
                        count--, st.unionBySize(node, adjNode);
                }
            }

            res.push_back(count);
        }

        return res;
    }
};