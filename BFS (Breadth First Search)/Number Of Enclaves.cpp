// Time Complexity: O(N * M)
// Space Complexity: O(1)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0])
                q.push({i, 0});
            if (grid[i][m - 1])
                q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j])
                q.push({0, j});
            if (grid[n - 1][j])
                q.push({n - 1, j});
        }
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            if (grid[x][y])
            {
                grid[x][y] = 0;
                for (auto &a : moves)
                {
                    int i = a.first + x;
                    int j = a.second + y;
                    if (isSafe(i, j, n, m) && grid[i][j])
                        q.push({i, j});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    count += 1;
            }
        }
        return count;
    }
};