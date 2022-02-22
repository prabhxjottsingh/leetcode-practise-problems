// Problem Link: https://leetcode.com/problems/excel-sheet-column-number/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int n = columnTitle.size();
        int i = 0, count = 0;
        while (i < n)
        {
            count = (count * 26) + (columnTitle[i] - 'A' + 1);
            i++;
        }
        return count;
    }
};