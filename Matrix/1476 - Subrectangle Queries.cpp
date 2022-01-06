//Tags: Medium
//Problem Link: https://leetcode.com/problems/subrectangle-queries/
//Time Complexity:
//Space Complexity:

class SubrectangleQueries
{
private:
    vector<vector<int>> matrix;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        int n = rectangle.size();
        for (int i = 0; i < n; i++)
        {
            int m = rectangle[i].size();
            vector<int> inner(m);
            for (int j = 0; j < m; j++)
            {
                inner[j] = rectangle[i][j];
            }
            matrix.push_back(inner);
        }
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            int m = matrix[i].size();
            for (int j = 0; j < m; j++)
            {
                if (i >= row1 && i <= row2 && j >= col1 && j <= col2)
                    matrix[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */