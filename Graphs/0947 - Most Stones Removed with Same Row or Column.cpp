// Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// Time Complexity: O(N ^ 2)
// Space Complexity: O(N ^ 2)

class Solution
{
private:
    void dfs(int vertex, vector<int> graph[], vector<bool> &isVis)
    {
        isVis[vertex] = 1;
        for (auto &child : graph[vertex])
        {
            if (!isVis[child])
                dfs(child, graph, isVis);
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> graph[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count = n;
        vector<bool> isVis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!isVis[i])
                dfs(i, graph, isVis), count -= 1;
        }
        return count;
    }
};