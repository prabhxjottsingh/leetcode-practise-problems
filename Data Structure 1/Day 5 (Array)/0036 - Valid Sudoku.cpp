// Problem Link: https://leetcode.com/problems/valid-sudoku/
// Time Complexity: O(n*m)
// Space Complexity: O(1) //constant

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        bool row[9][9] = {0}, col[9][9] = {0}, threeBox[9][9] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1, k = ((i / 3) * 3) + (j / 3);
                if (row[i][num] || col[j][num] || threeBox[k][num])
                    return false;
                row[i][num] = col[j][num] = threeBox[k][num] = 1;
            }
        }
        return true;
    }
};