// Problem Link: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

// Time Complexity: O(n*m)
// Space Complexity: O(1)

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> ans;
        char a = s[0], b = s[3];
        int x = s[1] - '0', y = s[4] - '0';
        for (char i = a; i <= b; i++)
        {
            for (int j = x; j <= y; j++)
            {
                char ch = j + '0';
                string temp;
                temp.push_back(i);
                temp.push_back(ch);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};