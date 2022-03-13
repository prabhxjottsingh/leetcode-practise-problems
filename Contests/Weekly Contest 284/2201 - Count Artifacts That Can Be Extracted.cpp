// Problem Link: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

// Time Complexity: O(n)
// Space Complexity: O(N)

//Done Using Sets, can also be done with the help of mapping
class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        set<pair<int, int>> st;
        int x = dig.size();
        for (int i = 0; i < x; i++)
        {
            st.insert({dig[i][0], dig[i][1]});
        }
        int count = 0;
        for (int i = 0; i < artifacts.size(); i++)
        {
            int x1 = artifacts[i][0];
            int y1 = artifacts[i][1];
            int x2 = artifacts[i][2];
            int y2 = artifacts[i][3];
            bool canBeDigged = true;
            for (int j = x1; j <= x2; j++)
            {
                for (int k = y1; k <= y2; k++)
                {
                    if (st.count({j, k}) == 0)
                        canBeDigged = false;
                }
            }
            if (canBeDigged)
                count++;
        }
        return count;
    }
};