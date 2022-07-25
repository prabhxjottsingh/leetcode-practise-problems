// Problem Link: https://leetcode.com/problems/network-delay-time/

class Solution
{
private:
    const int INF = 1e9 + 7;

    int dijkstra(int source, int n, vector<pair<int, int>> graph[])
    {

        vector<int> dist(n, INF);
        vector<bool> isVis(n, false);

        set<pair<int, int>> st;

        st.insert({0, source});
        dist[source] = 0;

        while (!st.empty())
        {
            auto node = *st.begin();

            int v = node.second;
            int v_dist = node.first;

            st.erase(*st.begin());

            if (isVis[v])
                continue;

            isVis[v] = 1;

            for (auto &child : graph[v])
            {

                int child_v = child.first;
                int wt = child.second;

                if (((dist[v] + wt) < dist[child_v]))
                {
                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }

        int maxDist = 0;

        for (int i = 1; i < n; i++)
        {
            if (dist[i] == INF)
                return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> graph[n + 1];
        for (auto &vec : times)
        {
            graph[vec[0]].push_back({vec[1], vec[2]});
        }
        int res = dijkstra(k, n + 1, graph);
        return res;
    }
};

// Using Bellman Ford Algorithm

/*

here dp[i][j] represents minimum time to reach j nodes with atmost i steps

*/
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX));
        for (int i = 0; i <= n + 1; i++)
            dp[i][k] = 0;                                         //minimum time to reach node K with atmost i steps
        for (int i = 1; i <= n + 1; i++)
        {
            for (auto &a : times)
            {
                int u = a[0];
                int v = a[1];
                int wt = a[2];
                if (dp[i - 1][u] != INT_MAX)                     //minimum time to reach u with atmost i - 1 steps
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + wt); //minimum time to reach v with atmost i steps
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[n][i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, dp[n][i]);                   //minimum time to reach ith node with atmost k steps
        }
        return maxTime;
    }
};