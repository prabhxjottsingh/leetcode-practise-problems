// Problem Link: https://leetcode.com/problems/two-city-scheduling/

// Time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
private:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        int x = (a[0] - a[1]);
        int y = (b[0] - b[1]);
        return (x < y);
    }

public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), comparator);
        int minCost = 0;
        for (int i = 0; i < costs.size() / 2; i++)
        {
            minCost += costs[i][0];
        }
        for (int i = costs.size() / 2; i < costs.size(); i++)
        {
            minCost += costs[i][1];
        }
        return minCost;
    }
};