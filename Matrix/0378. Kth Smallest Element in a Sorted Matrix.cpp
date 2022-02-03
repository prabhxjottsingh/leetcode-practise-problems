//Tags: Medium, Matrix
//Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//Time Complexity: O(n^2)
//Space Complexity: O(1)

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> v;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                v.push_back(matrix[i][j]);
        }
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};