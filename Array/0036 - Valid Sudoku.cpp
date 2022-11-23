// Problem Link: https://leetcode.com/problems/valid-sudoku/

// Time Complexity: O(N * M)
// Space complexity: O(9 * 9)

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<int> row[9];
        set<int> col[9];
        set<int> squares[3][3];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (row[i].count(board[i][j] - '0') || col[j].count(board[i][j] - '0') || squares[i / 3][j / 3].count(board[i][j] - '0'))
                    return false;
                row[i].insert(board[i][j] - '0');
                col[j].insert(board[i][j] - '0');
                squares[i / 3][j / 3].insert(board[i][j] - '0');
            }
        }
        return true;
    }
};