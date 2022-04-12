// Problem Link: https://leetcode.com/problems/game-of-life/
//Time Complexity: O(N*M)
//Space Compexity: O(N*M)

class Solution
{
private:
    map<pair<int, int>, int> mp;

    int dfs(int i, int j, vector<vector<int>> board)
    {
        int n = board.size();
        int m = board[0].size();
        if (i >= n || i < 0 || j < 0 || j >= m)
            return 0;
        else if (board[i][j] == 1)
            return 1;
        return 0;
    }

    int helper(int x, int y, vector<vector<int>> board)
    {
        int count = 0;
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i == x && j == y)
                    continue;
                count += dfs(i, j, board);
            }
        }
        return count;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = helper(i, j, board);
                if (board[i][j] == 1)
                {
                    if (count < 2)
                        mp[{i, j}] = 0;
                    else if (count > 3)
                        mp[{i, j}] = 0;
                    else
                        mp[{i, j}] = 1;
                }
                else
                {
                    if (count == 3)
                        mp[{i, j}] = 1;
                    else
                        mp[{i, j}] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mp[{i, j}] == 1)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};