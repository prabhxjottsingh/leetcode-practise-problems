class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i > -1 && j > -1 && i < n && j < m)
            return true;
        return false;
    }

    void dfs(int i, int j, int &row, int &col, vector<vector<int>> &grid, vector<pair<int, int>> &vec)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        vec.push_back({i - row, j - col});
        for (auto &a : moves)
        {
            int p = i + a.first;
            int q = j + a.second;
            if (isSafe(p, q, n, m) && grid[p][q] == 1)
                dfs(p, q, row, col, grid, vec);
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<vector<pair<int, int>>> st;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, i, j, grid, vec);
                    st.insert(vec);
                }
            }
        }
        return (int)st.size();
    }
};  