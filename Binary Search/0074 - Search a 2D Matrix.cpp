// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/

// Time Complexity: O(N * log M)
// Space Complexity: O(1) -> Constant

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            auto x = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (x == matrix[i].end())
                continue;
            if (target == *x)
                return true;
        }
        return false;
    }
};

// Time Complexity: O(N * log M)
// Space Complexity: O(1) -> Constant

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (high >= low)
        {
            int midIdx = ((high + low) >> 1);
            int midVal = matrix[midIdx / m][midIdx % m];
            if (target == midVal)
                return true;
            else if (target < midVal)
                high = midIdx - 1;
            else
                low = midIdx + 1;
        }
        return false;
    }
};