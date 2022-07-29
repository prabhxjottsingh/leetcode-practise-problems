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

//Constant Space Complexity: 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0) 
                col0 = 0;
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = rows-1; i >= 0; i--){
            for(int j = cols-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }
    }
};