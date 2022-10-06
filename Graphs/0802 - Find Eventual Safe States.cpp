// Problem Link: https://leetcode.com/problems/find-eventual-safe-states/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> res;
        queue<int> q;
        vector<int> deg(V, 0);
        vector<int> graph[V];
        for (int i = 0; i < V; i++)
        {
            for (auto &child : adj[i])
            {
                graph[child].push_back(i);
                deg[i] += 1;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (!deg[i])
                q.push(i);
        }
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            res.push_back(node);
            for (auto &child : graph[node])
            {
                deg[child] -= 1;
                if (deg[child] == 0)
                    q.push(child);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};