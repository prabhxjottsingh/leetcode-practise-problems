// Problem Link: https://leetcode.com/problems/calculate-amount-paid-in-taxes/

// time ComplexitY: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double taxes = 0;
        int amountUsed = min(income, brackets[0][0]);
        income -= amountUsed;
        int n = brackets.size();
        taxes = (double)amountUsed * (double)brackets[0][1] / (double)100;
        for (int i = 1; i < n && income > 0; i++)
        {
            int amountUsed = min(income, brackets[i][0] - brackets[i - 1][0]);
            income -= amountUsed;
            taxes += (double)amountUsed * (double)brackets[i][1] / (double)100;
        }
        return taxes;
    }
};