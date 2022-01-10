//Tags: Matrix, Easy
//Problem Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
//Time Complexity: O(n*n)
//Space Complxity: O(n+n) (because of using the maps)

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            map<int, bool> mp;
            map<int, bool> mpCol;
            for (int j = 0; j < n; j++)
            {
                mp[matrix[i][j]] = true;
                mpCol[matrix[j][i]] = true;
            }
            for (int j = 1; j <= n; j++)
            {
                if (mp[j] == false || mpCol[j] == false)
                    return false;
            }
        }
        return true;
    }
};