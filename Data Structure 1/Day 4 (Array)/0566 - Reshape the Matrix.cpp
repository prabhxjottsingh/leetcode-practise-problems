// Problem Link: https://leetcode.com/problems/reshape-the-matrix/
// Space Complexity: O(1)
// Time compleity:O(r*c)

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans;
        int n = mat.size(), m = mat[0].size(), a = 0, b = 0;
        int total = m * n;
        if (r * c != total)
            return mat;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;
            for (int j = 0; j < c; j++)
            {
                temp.push_back(mat[a][b]);
                b++;
                if (b == m)
                {
                    a++;
                    b = 0;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};