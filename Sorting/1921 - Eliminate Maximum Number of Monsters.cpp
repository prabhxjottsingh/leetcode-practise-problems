//Tags: Medium
//Problem Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
//Time Complexity:
//Space Complexity:

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
        {
            time[i] = ceil(((dist[i] - 1) / speed[i]));
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < n; i++)
        {
            if (i > time[i])
                return (i);
        }
        return n;
    }
};
