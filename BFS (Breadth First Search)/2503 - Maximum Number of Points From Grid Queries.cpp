// Problem Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

// Time Complexity: O(Q * log Q)
// Space Complexity: O(n * M)

class Solution
{
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return 0;
        if (j < 0 || j >= m)
            return 0;
        return 1;
    }

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        vector<pair<int, int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        int isVis[n][m];
        memset(isVis, 0, sizeof(isVis));
        int q = queries.size();
        vector<int> resVec(q, 0);
        for (int i = 0; i < q; i++)
            qu.push_back({queries[i], i});
        sort(qu.begin(), qu.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int count = 0;
        for (auto &a : qu)
        {
            int lmt = a.first;
            int idx = a.second;
            while (!pq.empty() && pq.top().first < lmt)
            {
                auto front = pq.top();
                pq.pop();
                int x = front.second.first;
                int y = front.second.second;
                int wt = front.first;
                if (isVis[x][y])
                    continue;
                isVis[x][y] = 1;
                count += 1;
                for (auto &a : moves)
                {
                    int nx = a.first + x;
                    int ny = a.second + y;
                    if (isSafe(nx, ny, n, m) && !isVis[nx][ny])
                        pq.push({grid[nx][ny], {nx, ny}});
                }
            }
            resVec[idx] = count;
        }
        return resVec;
    }
};