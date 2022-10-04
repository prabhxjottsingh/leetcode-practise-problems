// Problem Link: https://leetcode.com/problems/surrounded-regions/

// Time Complexity: O(N * M)
// Space Complexity: O(n * m)

class Solution
{
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }

    void boundaryZeroes(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &isVis)
    {
        int n = mat.size();
        int m = mat[0].size();
        isVis[i][j] = 1;
        for (auto &a : moves)
        {
            int x = i + a.first;
            int y = j + a.second;
            if (isSafe(x, y, n, m) && !isVis[x][y] && mat[i][j] == 'O')
                boundaryZeroes(x, y, mat, isVis);
        }
    }

    void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &isVis)
    {
        int n = mat.size();
        int m = mat[0].size();
        isVis[i][j] = 1;
        mat[i][j] = 'X';
        for (auto &a : moves)
        {
            int x = i + a.first;
            int y = j + a.second;
            if (isSafe(x, y, n, m) && !isVis[x][y] && mat[x][y] == 'O')
                dfs(x, y, mat, isVis);
        }
    }

public:
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> isVis(n, (vector<bool>(m, 0)));
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !isVis[i][0])
                boundaryZeroes(i, 0, mat, isVis);

            if (mat[i][m - 1] == 'O' && !isVis[i][m - 1])
                boundaryZeroes(i, m - 1, mat, isVis);
        }
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && !isVis[0][j])
                boundaryZeroes(0, j, mat, isVis);

            if (mat[n - 1][j] == 'O' && !isVis[n - 1][j])
                boundaryZeroes(n - 1, j, mat, isVis);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !isVis[i][j])
                    dfs(i, j, mat, isVis);
            }
        }
    }
};