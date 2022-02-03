//Tags: Medium, Matrix
//Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
//Time Complexity: O(N*M) (constraints weren't a problem)
//Space Complexity: Constant

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            int m = matrix[i].size();
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};