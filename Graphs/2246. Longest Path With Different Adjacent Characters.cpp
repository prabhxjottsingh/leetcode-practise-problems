// Problem Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

// Time Complexity: O(N)
// space Complexity: O(n)

class Solution
{
private:
    int dfs(int node, vector<int> graph[], string &s, int &maxLen)
    {
        int currMax = 0;
        int secondMax = 0;
        for (auto &child : graph[node])
        {
            int result = dfs(child, graph, s, maxLen);
            if (s[child] == s[node])
                continue;
            if (result > currMax)
            {
                secondMax = currMax;
                currMax = result;
            }
            else
            {
                secondMax = max(secondMax, result);
            }
        }
        maxLen = max(maxLen, currMax + secondMax + 1);
        return currMax + 1;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        int n = s.size();
        vector<int> graph[n];
        for (int i = 1; i < n; i++)
            graph[parent[i]].push_back(i);
        int maxLen = 0;
        dfs(0, graph, s, maxLen);
        return maxLen;
    }
};