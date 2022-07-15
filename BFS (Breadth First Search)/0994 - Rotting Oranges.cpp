class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isPossible(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int seconds = -1;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        bool twoPresent = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    twoPresent = 1;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                for (auto &move : moves)
                {
                    int newX = move.first + front.first;
                    int newY = move.second + front.second;
                    if (isPossible(newX, newY, n, m) && grid[newX][newY] == 1)
                    {
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                    }
                }
            }
            seconds++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        }
        if (twoPresent == 0)
            return 0;
        return seconds;
    }
};