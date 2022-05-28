// Problem LinK: https://leetcode.com/problems/maximum-total-importance-of-roads/

// Space Complexity: O(N * M)
// Time Complexity: O(N * M)

class Solution
{
private:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second < b.second);
    }

public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        int m = roads.size();
        vector<int> graph[n];
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({i, graph[i].size()});
            mp[i] = 0;
        }
        sort(vp.begin(), vp.end(), comp);
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            mp[vp[i].first] = count;
            count++;
        }
        long long int sum = 0;
        for (int i = 0; i < m; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            sum += mp[u] + mp[v];
        }
        return sum;
    }
};