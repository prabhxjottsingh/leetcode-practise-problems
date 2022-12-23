// Problem Link: https://leetcode.com/problems/swim-in-rising-water/description/

// Time Complexity: O(Log N * N * N)
// Space Complexity: O(N)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= n)
            return false;
        return true;
    }

    bool isPos(int i, int j, vector<vector<int>> &grid, int time, vector<vector<bool>> &isVis)
    {
        int n = grid.size();
        if (i == n - 1 && j == n - 1)
            return true;
        isVis[i][j] = 1;
        bool flag = false;
        for (auto &move : moves)
        {
            int nx = i + move.first;
            int ny = j + move.second;
            if (isSafe(nx, ny, n) && grid[nx][ny] <= time && !isVis[nx][ny])
                flag |= isPos(nx, ny, grid, time, isVis);
            if (flag)
                return true;
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int low = 0;
        int high = 0;
        int n = grid.size();
        for (auto &a : grid)
            for (auto &b : a)
                high = max(high, b);
        int minTime = 1e9;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> isVis(n, vector<bool>(n, 0));
            if (isPos(0, 0, grid, mid, isVis) && mid >= grid[0][0])
                minTime = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        return minTime;
    }
};