// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/

// Time Complextiy: O(N * M)
// Space Complexity: O(1)

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int countMinus = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] < 0)
                {
                    countMinus += 1;
                }
            }
        }
        int minElem = INT_MAX;
        for (auto &a : matrix)
        {
            for (auto &b : a)
            {
                if (b < 0)
                    b *= (-1);
                sum += b * 1ll;
                minElem = min(minElem, b);
            }
        }
        if (countMinus & 1)
            sum -= 2 * minElem;
        return sum;
    }
};