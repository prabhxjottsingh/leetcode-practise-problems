//Problem Link: https://leetcode.com/problems/sort-the-matrix-diagonally/
//time Complexity: O(n * m * log n)
//space Complexity: O(1)

class Solution
{
private:
    void diagonalTransversal(int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<int, vector<int>, greater<int>> st;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            int newI = q.front().first;
            int newJ = q.front().second;
            st.push(mat[newI][newJ]);
            q.pop();
            if (newI + 1 < n && newJ + 1 < m)
                q.push({newI + 1, newJ + 1});
        }
        q.push({i, j});
        while (!q.empty())
        {
            int newI = q.front().first;
            int newJ = q.front().second;
            mat[newI][newJ] = st.top();
            st.pop();
            idx += 1;
            q.pop();
            if (newI + 1 < n && newJ + 1 < m)
                q.push({newI + 1, newJ + 1});
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
            (diagonalTransversal(i, 0, mat));
        for (int j = 0; j < m; j++)
            (diagonalTransversal(0, j, mat));
        return mat;
    }
};