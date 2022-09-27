// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

// time Complexity: O(N * M * log (N * M))
// Space Complexity: O(n * M)

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> diffVec;
        for (auto &a : grid)
        {
            for (auto &b : a)
                diffVec.push_back(b);
        }
        int opts = 0;
        sort(diffVec.begin(), diffVec.end());
        int mid = grid[0].size() * grid.size() / 2;
        for (auto &a : diffVec)
        {
            int diff = abs(a - diffVec[mid]);
            if (diff % x != 0)
                return -1;
            opts += diff / x;
        }
        return opts;
    }
};