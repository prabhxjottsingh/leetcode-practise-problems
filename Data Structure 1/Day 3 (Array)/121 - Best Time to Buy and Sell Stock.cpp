// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Space Complexity: O(1)
// Time Complexity: O(n)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0, buy = prices[0], n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            maxProfit = max(prices[i] - buy, maxProfit);
        }
        return maxProfit;
    }
};