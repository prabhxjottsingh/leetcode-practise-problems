// Problem Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
private:
    static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return (a.second < b.second);
        }
        return (a.first < b.first);
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> vp;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            int countOne = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    countOne++;
            }
            vp.push_back({countOne, i});
        }
        sort(vp.begin(), vp.end(), comparator);
        vector<int> ans;
        for (int i = 0; (i < n && ans.size() < k); i++)
        {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};