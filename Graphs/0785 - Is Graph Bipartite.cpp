// Problem Link: https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (color[i])
                continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int parent = q.front();
                q.pop();
                for (auto &child : graph[parent])
                {
                    if (color[child] == 0)
                    {
                        color[child] = -color[parent];
                        q.push(child);
                    }
                    else
                    {
                        if (color[child] == color[parent])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

//Using BFS it is called Kahn's Algorithm