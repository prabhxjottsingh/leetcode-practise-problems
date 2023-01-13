// Problem Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

// Time Complexity:
// space Complexity:

class Solution
{
private:
    int dfs(int node, int par, vector<int> graph[], vector<bool> &hasApp)
    {
        int totTime = 0;
        int childTime = 0;
        for (auto &child : graph[node])
        {
            if (child == par)
                continue;
            childTime = dfs(child, node, graph, hasApp);
            if (childTime || hasApp[child])
                totTime += childTime + 2;
        }
        return totTime;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> graph[n];
        for (auto &a : edges)
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        int totTime = dfs(0, -1, graph, hasApple);
        return totTime;
    }
};