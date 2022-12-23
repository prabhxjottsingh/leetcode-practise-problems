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

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string>> res;
        int n = accounts.size();
        vector<set<string>> newAccounts(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
                newAccounts[i].insert(accounts[i][j]);
        }
        disjointSet st(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (auto &a : newAccounts[i])
                {
                    if (newAccounts[j].count(a))
                    {
                        st.unionBySize(i, j);
                        break;
                    }
                }
            }
        }
        vector<set<string>> vecSt(n);
        for (int i = 0; i < n; i++)
        {
            int par = st.findPar(i);
            int n = accounts[i].size();
            for (int j = 1; j < n; j++)
            {
                vecSt[par].insert(accounts[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vecSt[i].size())
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &a : vecSt[i])
                temp.push_back(a);
            res.push_back(temp);
        }
        return res;
    }
};

// Second Method
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

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        map<string, int> mapMailNode;
        disjointSet st(n);

        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                string &str = accounts[i][j];

                if (mapMailNode.count(str))
                    st.unionBySize(i, mapMailNode[str]);

                else
                    mapMailNode[str] = i;
            }
        }

        vector<string> mergedMails[n];

        for (auto &a : mapMailNode)
        {
            int node = a.second;
            node = st.findPar(node);

            mergedMails[node].push_back(a.first);
        }

        vector<vector<string>> resVec;

        for (int i = 0; i < n; i++)
        {
            if (!mergedMails[i].size())
                continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string &a : mergedMails[i])
                temp.push_back(a);
            resVec.push_back(temp);
        }
        return resVec;
    }
};