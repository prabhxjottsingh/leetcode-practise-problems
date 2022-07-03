class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isPossible(int i, int j, int n, int m)
    {

        if (i >= n || i < 0)
            return false;
        if (j >= m || j < 0)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        if (!isPossible(i, j, n, m) || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        for (auto &move : moves)
        {
            int x = i + move.first;
            int y = j + move.second;
            dfs(x, y, grid);
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        int countIslands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (((i == 0) || (i == n - 1) || (j == 0) || (j == m - 1)) && (grid[i][j] == 0))
                    dfs(i, j, grid);
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, grid);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};