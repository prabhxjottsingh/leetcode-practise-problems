// Problem Link: https://leetcode.com/problems/n-queens/

// Time Complexity: O(N!)
// Space Complexity: O(1)

class Solution
{
private:
    bool isSafe(int row, int col, vector<string> &temp)
    {
        int x = row;
        int y = col;
        while (y > -1)
        {
            if (temp[x][y] == 'Q')
                return false;
            y -= 1;
        }
        x = row, y = col;
        while (x > -1 && y > -1)
        {
            if (temp[x][y] == 'Q')
                return false;
            x -= 1;
            y -= 1;
        }
        x = row, y = col;
        while (x < temp.size() && y > -1)
        {
            if (temp[x][y] == 'Q')
                return false;
            x += 1;
            y -= 1;
        }
        return true;
    }

    void func(int col, int n, vector<string> temp, vector<vector<string>> &res)
    {
        if (col == n)
        {
            res.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, temp))
            {
                temp[row][col] = 'Q';
                func(col + 1, n, temp, res);
                temp[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        func(0, n, temp, res);
        return res;
    }
};