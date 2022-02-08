// Tags: Medium, Matrix
// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Time Complexity: O(N*M) (constraints weren't a problem)
// Space Complexity: Constant

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

// Time Complexity: O((n+m) * log (n+m))
// Space Complexity: O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        if (n == 0 || m == 0)
            return false;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            int midVal = matrix[mid / m][mid % m];
            if (midVal == target)
                return true;
            else if (midVal > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};