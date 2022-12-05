// Problem Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution
{
private:
    bool isSafe(int x, int y, int n, int m)
    {
        if (x < 0 || x >= n)
            return 0;
        if (y < 0 || y >= m)
            return 0;
        return 1;
    }

public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int K)
    {
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        q.push({{0, 0}, K});
        int steps = 0;
        vector<vector<int>> kVal(n, vector<int>(m, -1));
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto front = q.front();
                q.pop();
                int x = front.first.first;
                int y = front.first.second;
                if (x == n - 1 && y == m - 1)
                    return steps;
                int k = front.second;
                for (auto &a : moves)
                {
                    int nx = x + a.first;
                    int ny = y + a.second;
                    if ((!isSafe(nx, ny, n, m)))
                        continue;
                    if (mat[nx][ny] == 1)
                    {
                        if (k > 0)
                        {
                            if ((kVal[nx][ny] != -1 && kVal[nx][ny] >= k))
                                continue;
                            kVal[nx][ny] = k - 1;
                            q.push({{nx, ny}, k - 1});
                        }
                    }
                    else
                    {
                        if ((kVal[nx][ny] != -1 && kVal[nx][ny] >= k))
                            continue;
                        kVal[nx][ny] = k;
                        q.push({{nx, ny}, k});
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
};