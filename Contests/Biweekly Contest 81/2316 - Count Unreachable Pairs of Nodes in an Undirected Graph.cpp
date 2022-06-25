// Problem Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution
{
private:
    static const int N = 2e5 + 3;
    vector<long long int> graph[N];
    bool visited[N];
    vector<vector<long long int>> connected_components;
    vector<long long int> current_component;

    void dfs(long long int vertex)
    {
        current_component.push_back(vertex);
        visited[vertex] = true;
        for (auto child : graph[vertex])
        {
            if (visited[child])
                continue;
            dfs(child);
        }
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        int e = edges.size();
        if (edges.size() == 0)
        {
            long long res = (1ll * n * (n + 1)) / 2;
            res -= n;
            return res;
        }
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            current_component.clear();
            if (visited[i] != true)
            {
                dfs(i);
                connected_components.push_back(current_component);
            }
        }
        long long count = 1ll * n * (n + 1) / 2;
        for (auto a : connected_components)
        {
            long long int t = a.size();
            count -= (t) * (t + 1) / 2;
        }
        return count;
    }
};