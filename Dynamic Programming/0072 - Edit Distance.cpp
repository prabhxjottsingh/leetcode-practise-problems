class Solution
{
private:
    int dp[503][503];
    vector<pair<int, int>> moves = {{-1, 0}, {-1, -1}, {0, -1}};
    int func(int i, int j, string &s, string &t)
    {
        if (i < 0)
            return (j + 1);
        if (j < 0)
            return (i + 1);
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = func(i - 1, j - 1, s, t);
        int countOpts = INT_MAX;
        for (auto &move : moves)
        {
            int x = i + move.first;
            int y = j + move.second;
            countOpts = min(countOpts, 1 + func(x, y, s, t));
        }
        return dp[i][j] = countOpts;
    }

public:
    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        int n = word1.size();
        int m = word2.size();
        int count = func(n - 1, m - 1, word1, word2);
        return count;
    }
};