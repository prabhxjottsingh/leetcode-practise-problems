// Problem Link: https://leetcode.com/problems/shift-2d-grid/

// Time Complexity: O(K*N*M)
// Space Complexity: O(N*M)

class Solution
{
private:
    void rightShiftByOne(vector<int> &temp)
    {
        int n = temp.size();
        int lastNum = temp[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            temp[i] = temp[i - 1];
        }
        temp[0] = lastNum;
    }

public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> temp(n * m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp[i * m + j] = grid[i][j];
            }
        }
        while (k--)
        {
            rightShiftByOne(temp);
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = temp[idx];
                idx++;
            }
        }
        return grid;
    }
};