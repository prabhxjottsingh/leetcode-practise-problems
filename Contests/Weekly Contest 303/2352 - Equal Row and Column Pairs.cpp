// Problem Link: https://leetcode.com/problems/equal-row-and-column-pairs/
// time Complexity: O(n ^ N)
// Space Complexity: O(N)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int count = 0;
        int m = grid[0].size();
        int x = 0;
        map<vector<int>, int> freqColVecs;
        for (int k = 0; k < n; k++)
        {
            vector<int> colVec;
            for (int j = 0; j < m; j++)
            {
                colVec.push_back(grid[j][x]);
            }
            x++;
            freqColVecs[colVec]++;
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> rowVec = grid[i];
            if (freqColVecs.count(rowVec))
                count += freqColVecs[rowVec];
        }
        return count;
    }
};