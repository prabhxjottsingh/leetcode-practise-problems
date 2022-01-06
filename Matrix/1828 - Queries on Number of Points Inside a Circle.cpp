//Tags: Medium
//Problem Link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
//Time Complexity:
//Space Complexity:

class Solution
{
public:
    bool isInside(int cx, int cy, int r, int x, int y)
    {
        if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r)
            return true;
        else
            return false;
    }
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &query)
    {
        vector<int> ans;
        for (int i = 0; i < query.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (isInside(query[i][0], query[i][1], query[i][2], points[j][0], points[j][1]))
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};