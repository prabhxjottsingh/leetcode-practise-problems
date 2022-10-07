// Problem Link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/

// Time Complexity: O(n * M * 6)
// Space Complexity: O(1)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }

    int helperFunc(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        int sum = 0;
        int countCells = 0;
        for (auto &a : moves)
        {
            int x = i + a.first;
            int y = j + a.second;
            if (isSafe(x, y, n, m))
                sum += grid[x][y], countCells += 1;
        }
        if (countCells == 7)
            return sum;
        return 0;
    }

public:
    int maxSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxSum = 0;
        pair<int, int> a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = helperFunc(i, j, n, m, grid);
                maxSum = max(maxSum, sum);
                if (maxSum == sum)
                    a.first = i, a.second = j;
            }
        }
        return maxSum;
    }
};