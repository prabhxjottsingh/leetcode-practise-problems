//Tags: Medium, Matrix
//Problem Link: https://leetcode.com/problems/set-matrix-zeroes/
//Time Complexity: O(n*m*log(n)*log(m))
//Space Complexity: O(m+n)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> rowZero, colZero;
        for (int i = 0; i < n; i++)
        {
            int m = matrix[i].size();
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowZero.push_back(i);
                    colZero.push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            int m = matrix[i].size();
            for (int j = 0; j < m; j++)
            {
                if (find(rowZero.begin(), rowZero.end(), i) != rowZero.end() || find(colZero.begin(), colZero.end(), j) != colZero.end())
                    matrix[i][j] = 0;
            }
        }
    }
};