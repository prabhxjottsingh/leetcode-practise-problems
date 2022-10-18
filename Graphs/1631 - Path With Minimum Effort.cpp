// Problem Link: https://leetcode.com/problems/path-with-minimum-effort/

// Time Complexity: O(E * log (n * m) * 4)
// Space Complexity: O(N * M)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return 0;
        if (j < 0 || j >= m)
            return 0;
        return 1;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        int dist[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dist[i][j] = 1e9;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int currDist = front.first;
            int row = front.second.first;
            int col = front.second.second;
            if (row == n - 1 && col == m - 1)
                return currDist;
            for (auto &a : moves)
            {
                int nr = a.first + row;
                int nc = a.second + col;
                if (isSafe(nr, nc, n, m))
                {
                    int maxDist = max(currDist, abs(heights[row][col] - heights[nr][nc]));
                    if (maxDist < dist[nr][nc])
                    {
                        dist[nr][nc] = maxDist;
                        pq.push({maxDist, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};