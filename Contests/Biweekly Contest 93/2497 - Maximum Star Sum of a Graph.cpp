// Problem Link: https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {
        int n = vals.size();
        vector<int> graph[n];
        for (auto &a : edges)
        {
            graph[a[0]].push_back(vals[a[1]]);
            graph[a[1]].push_back(vals[a[0]]);
        }
        if (!edges.size())
            return *max_element(vals.begin(), vals.end());
        int maxSum = -1e9;
        for (int i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
            reverse(graph[i].begin(), graph[i].end());
            int sum = vals[i];
            if (graph[i].size())
            {
                for (int j = 0; j < min(k, (int)graph[i].size()); j++)
                {
                    if (graph[i][j] > 0)
                        sum += graph[i][j];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return ((maxSum == -1e9) ? 0 : maxSum);
    }
};