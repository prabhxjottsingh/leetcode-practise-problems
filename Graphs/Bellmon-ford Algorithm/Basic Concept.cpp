//Time Complexity: O(E * V)

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &a : edges)
            {
                int u = a[0];
                int v = a[1];
                int wt = a[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        for (auto &a : edges)
        {
            int u = a[0];
            int v = a[1];
            int wt = a[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        return dist;
    }
};  