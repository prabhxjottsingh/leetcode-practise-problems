// Problem Link: https://leetcode.com/problems/01-matrix/

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution
{
private:
    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return true;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m));
        vector<vector<bool>> isVis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    isVis[i][j] = 1;
                }
            }
        }
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                int newI = front.first.first;
                int newJ = front.first.second;
                int steps = front.second;
                q.pop();
                dist[newI][newJ] = steps;
                for (auto &move : moves)
                {
                    int x = newI + move.first;
                    int y = newJ + move.second;
                    if (isSafe(x, y, n, m) && !isVis[x][y])
                    {
                        q.push({{x, y}, steps + 1});
                        isVis[x][y] = 1;
                    }
                }
            }
        }
        return dist;
    }
};