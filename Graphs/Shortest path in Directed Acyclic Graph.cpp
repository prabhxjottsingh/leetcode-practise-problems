//can also be done using Topologicla Sort, Djisktra Algo

class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> graph[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v, wt});
        }
        vector<int> dist(N, 1e9);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
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