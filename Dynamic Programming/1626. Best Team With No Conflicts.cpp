// tc: O(N * m)
// sc: O(n * M)

class Solution
{
private:
    int dp[1001][1001];

    int func(int idx, int n, vector<pair<int, int>> &pr, int prevMaxIdx)
    {
        if (idx == n)
            return 0;
        if (dp[idx][prevMaxIdx] != -1)
            return dp[idx][prevMaxIdx];
        int take = 0;
        if (pr[idx].first != pr[prevMaxIdx].first)
        {
            if (pr[idx].second >= pr[prevMaxIdx].second)
                take = pr[idx].second + func(idx + 1, n, pr, idx);
        }
        else
        {
            take = pr[idx].second + func(idx + 1, n, pr, idx);
        }
        int notTake = func(idx + 1, n, pr, prevMaxIdx);
        return dp[idx][prevMaxIdx] = max(take, notTake);
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> pr;
        int n = ages.size();
        memset(dp, -1, sizeof(dp));

        pr.emplace_back(-1, -1);
        for (int i = 0; i < n; i++)
            pr.emplace_back(ages[i], scores[i]);
        sort(pr.begin(), pr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if( a.first == b.first ) return a.second < b.second;
            return a.first < b.first; });
        int maxScore = func(1, n + 1, pr, 0);
        return maxScore;
    }
};

// sc: O(n)
// iterative DP
class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = ages.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++)
            pr.emplace_back(ages[i], scores[i]);
        sort(pr.begin(), pr.end());
        int maxScore = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = pr[i].second;
            for (int j = 0; j < i; j++)
            {
                if (pr[j].second <= pr[i].second)
                    dp[i] = max(dp[i], pr[i].second + dp[j]);
            }
            maxScore = max(maxScore, dp[i]);
        }
        return maxScore;
    }
};