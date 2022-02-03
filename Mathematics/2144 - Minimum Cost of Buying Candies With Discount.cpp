//Problem Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
//Time Complexity: O( n + (n* log n) )
//Space Complexity: O(1)

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();
        int totalCost = 0;
        sort(cost.begin(), cost.end());

        if (n < 3)
        {
            for (int i = 0; i < n; i++)
                totalCost += cost[i];
            return totalCost;
        }

        else if (n == 3)
        {
            for (int i = 1; i < n; i++)
                totalCost += cost[i];
            return totalCost;
        }
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            totalCost += cost[i];
            count++;
            if (count == 2)
            {
                count = 0;
                i--;
            }
        }
        return totalCost;
    }
};