// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// time Complexity: O(K * N)
// Space Complexity: o(n * k)

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dp(k + 2, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= k + 1; i++)
            dp[i][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &a : flights)
            {
                int u = a[0];
                int v = a[1];
                int wt = a[2];
                if (dp[i - 1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], wt + dp[i - 1][u]);
            }
        }
        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};

// Djisktra
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> graph[n];
        for (auto &a : flights)
        {
            int start = a[0];
            int end = a[1];
            int cost = a[2];
            graph[start].push_back({end, cost});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = 1e9;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int stops = front.first;
            int node = front.second.first;
            int costPrev = front.second.second;
            if (stops > k)
                continue;
            for (auto &child : graph[node])
            {
                int childNode = child.first;
                int childCost = child.second;
                if (childCost + costPrev < dist[childNode] && stops <= k)
                {
                    dist[childNode] = childCost + costPrev;
                    q.push({stops + 1, {childNode, dist[childNode]}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};