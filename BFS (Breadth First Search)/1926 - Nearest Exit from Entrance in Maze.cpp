// Problem Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});
        int n = maze.size();
        int m = maze[0].size();
        int isVis[n][m];
        memset(isVis, 0, sizeof(isVis));
        pair<int, int> pq;
        pq.first = entrance[0];
        pq.second = entrance[1];
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int steps = front.first;
            int nx = front.second.first;
            int ny = front.second.second;
            pair<int, int> pr = {nx, ny};
            if ((nx == n - 1 || nx == 0 || ny == m - 1 || ny == 0) && (pr != pq))
                return steps;
            if (isVis[nx][ny])
                continue;
            isVis[nx][ny] = 1;
            for (auto &move : moves)
            {
                int x = move.first + nx;
                int y = move.second + ny;
                if (x < n && x >= 0 && y < m && y >= 0 && !isVis[x][y] && maze[x][y] == '.')
                    q.push({steps + 1, {x, y}});
            }
        }
        return -1;
    }
};