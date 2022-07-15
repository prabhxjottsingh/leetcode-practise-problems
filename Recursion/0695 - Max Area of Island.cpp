//Problem link: https://leetcode.com/problems/max-area-of-island/
//Time Complexity: O(N * M)
//Space Complexity: O(1)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isPossible(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, int &count)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (!isPossible(i, j, n, m) || grid[i][j] == 0)
            return;
        count++;
        grid[i][j] = 0;
        for (auto &move : moves)
        {
            int x = i + move.first;
            int y = j + move.second;
            dfs(x, y, grid, count);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxCount = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = 0;
                    dfs(i, j, grid, count);
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};