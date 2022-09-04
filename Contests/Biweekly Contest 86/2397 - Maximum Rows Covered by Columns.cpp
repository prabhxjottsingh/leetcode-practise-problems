// Time Complexity O(2 ^ n)
// Space Complexity: O(m * n)

class Solution
{
private:
    void recur(int idx, int cols, int m, vector<int> temp, vector<vector<int>> &res)
    {
        if (temp.size() == cols)
            res.push_back(temp);
        if (temp.size() > cols)
            return;
        if (idx == m)
            return;
        temp.push_back(idx);
        recur(idx + 1, cols, m, temp, res);
        temp.pop_back();
        recur(idx + 1, cols, m, temp, res);
    }

public:
    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> rowWithOne;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j])
                    rowWithOne[i].push_back(j);
            }
        }
        vector<vector<int>> allSubsets;
        vector<int> temp;
        int maxCount = 0;
        recur(0, cols, m, temp, allSubsets);
        for (auto &a : allSubsets)
        {
            int count = 0;
            for (int x = 0; x < n; x++)
            {
                bool sameFound = true;
                for (auto &b : rowWithOne[x])
                {
                    if (find(a.begin(), a.end(), b) == a.end())
                        sameFound = false;
                }
                count += sameFound;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};