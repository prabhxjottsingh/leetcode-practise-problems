// Problem Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/

// Time Complexity: O(N)
// Space Complexity: O(10)

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        vector<bool> v(10, false);
        int n = num.size();
        for (int i = 0; i < n; i++)
        {
            if (i + 2 < n)
            {
                if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
                {
                    v[num[i] - '0'] = true;
                }
            }
        }
        string res;
        for (int i = 9; i > -1; i--)
        {
            if (v[i] == true)
            {
                res.push_back(i + '0');
                res.push_back(i + '0');
                res.push_back(i + '0');
                break;
            }
        }
        return res;
    }
};