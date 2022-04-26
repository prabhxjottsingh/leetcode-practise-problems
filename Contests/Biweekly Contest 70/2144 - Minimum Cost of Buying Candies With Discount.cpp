// Problem Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        int n = cost.size();
        int totalCost = 0;
        for (int i = 0; i < n; i += 3)
        {
            totalCost += cost[i];
            if (i + 1 < n)
                totalCost += cost[i + 1];
        }
        return totalCost;
    }
};