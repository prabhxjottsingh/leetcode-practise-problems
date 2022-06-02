// Problem Link: https://leetcode.com/problems/transpose-matrix/

// Time Complexity: O(N * M)
// Space COomplexity: O(N * M)

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                res[j % m][i % n] = matrix[i][j];
        }
        return res;
    }
};