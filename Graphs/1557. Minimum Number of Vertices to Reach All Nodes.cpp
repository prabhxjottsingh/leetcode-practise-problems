// Problem Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> resVec;
        vector<int> deg(n, 0);

        vector<int> graph[n];
        for (auto &a : edges)
            deg[a[1]] += 1;
        for (int i = 0; i < n; i++)
        {
            if (!deg[i])
                resVec.push_back(i);
        }

        return resVec;
    }
};