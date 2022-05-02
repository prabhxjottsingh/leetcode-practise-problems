// Problem Link: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        long long count = 0;
        for (int i = 0; i * cost1 <= total; i++)
        {
            count += (total - i * cost1) / cost2;
            count++;
        }
        return count;
    }
};