// Problem Link: https://leetcode.com/problems/possible-bipartition/description/

// Time Complexity: O(N)
// Space ComplexitY: O(N)

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> graph[n];
        for (auto &a : dislikes)
        {
            a[0]--;
            a[1]--;
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        queue<int> q;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = 0;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (int &child : graph[node])
                    {
                        if (color[child] == -1)
                        {
                            color[child] = 1 - color[node];
                            q.push(child);
                        }
                        else
                        {
                            if (color[child] == color[node])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};