class Solution
{
private:
    int dp[51][51][51];
    static const int mod = 1e9 + 7;
    vector<pair<int, int>> possibleMoves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(int i, int j, int n, int m, int moves)
    {

        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        if (moves <= 0)
            return 0;
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];
        long long int finalCount = 0;
        for (auto &move : possibleMoves)
        {
            int newX = move.first + i;
            int newY = move.second + j;
            int newPath = dfs(newX, newY, n, m, moves - 1);
            finalCount = (finalCount + newPath) % mod;
        }
        return dp[i][j][moves] = finalCount;
    }

public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        int countPaths = dfs(startRow, startColumn, n, m, maxMove);
        return countPaths;
    }
};