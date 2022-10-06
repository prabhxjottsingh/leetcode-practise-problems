// can be done using topological sort

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<pair<int, int>> graph[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 1});
        }
        vector<bool> isVis(N, 0);
        vector<int> dist(N, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (isVis[node])
                continue;
            isVis[node] = 1;
            for (auto &a : graph[node])
            {
                int child = a.first;
                int minDist = a.second;
                if (minDist + dist[node] < dist[child])
                    dist[child] = minDist + dist[node];
                q.push(child);
            }
        }
        for (auto &a : dist)
        {
            if (a == 1e9)
                a = -1;
        }
        return dist;
    }
};