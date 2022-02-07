// Problem Link: https://leetcode.com/problems/pascals-triangle/

// Time CompleixtY: O(n*log n)
// Space CompleixtY: O(1)

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows > 1)
            ans.push_back({1, 1});
        for (int i = 2; i < numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; j++)
            {
                temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};