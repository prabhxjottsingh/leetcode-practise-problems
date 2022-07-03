class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {-1, 0}, {0, -1}};

    bool isPossible(int i, int j, int n)
    {

        if (i >= n || i < 0)
            return false;
        if (j >= n || j < 0)
            return false;

        return true;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 1}});
        grid[0][0] = 1;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second.first;
            int countSteps = front.second.second;
            if ((x == (n - 1)) && (y == (n - 1)))
                return countSteps;
            for (auto &move : moves)
            {
                int newX = x + move.first;
                int newY = y + move.second;
                if (isPossible(newX, newY, n) && grid[newX][newY] == 0)
                {
                    q.push({newX, {newY, countSteps + 1}});
                    grid[newX][newY] = 1;
                }
            }
        }
        return -1;
    }
};