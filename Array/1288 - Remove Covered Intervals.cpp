// Problem Link: https://leetcode.com/problems/remove-covered-intervals/

// Time Complexoty: O(N (log N) + N)
// Space Cpomplexity: O(2*N)

class Solution
{
private:
    static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return (a.second > b.second);
        return (a.first < b.first);
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> sortedIntervals;
        for (int i = 0; i < intervals.size(); i++)
        {
            sortedIntervals.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(sortedIntervals.begin(), sortedIntervals.end(), comparator);
        int prevStart = sortedIntervals[0].first, prevEnd = sortedIntervals[0].second;
        int n = sortedIntervals.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if ((sortedIntervals[i].first >= prevStart) && (sortedIntervals[i].second <= prevEnd))
            {
                count++;
            }
            else
            {
                prevStart = sortedIntervals[i].first;
                prevEnd = sortedIntervals[i].second;
            }
        }
        return (intervals.size() - count);
    }
};

// Time Complexity: O(N (Log N))
// Space Complexity: O(1)

class Solution
{
private:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return (a[1] > b[1]);
        return (a[0] < b[0]);
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comparator);
        int prevStart = intervals[0][0], prevEnd = intervals[0][1];
        int n = intervals.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if ((intervals[i][0] >= prevStart) && (intervals[i][1] <= prevEnd))
            {
                count++;
            }
            else
            {
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        return (intervals.size() - count);
    }
};