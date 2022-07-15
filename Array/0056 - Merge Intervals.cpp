// Problem Link: https://leetcode.com/problems/merge-intervals/
// Time Complexity: O(N * log N)
// space Complexity: O(1)

class Solution
{
private:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> resInterval;
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int firstTime = intervals[i][0];
            int secondTime = intervals[i][1];
            while (i + 1 < n && secondTime >= intervals[i + 1][0])
            {
                secondTime = max(secondTime, intervals[i + 1][1]);
                i++;
            }
            resInterval.push_back({firstTime, secondTime});
        }
        return resInterval;
    }
};