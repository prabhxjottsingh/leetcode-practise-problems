//Tags: Easy, String
//Problem Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
//Time Complexity: O(n)
//Space Complexity: O(k)

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int n = s.length();
        vector<string> ans;
        int x = 0;
        string str;
        for (int i = 0; i < n; i++)
        {
            x++;
            str.push_back(s[i]);
            if (x == k)
            {
                ans.push_back(str);
                x = 0;
                str.erase();
            }
        }
        if (!str.empty())
            ans.push_back(str);
        int z = ans.size();
        while (ans[z - 1].size() < k)
        {
            ans[z - 1].push_back(fill);
        }
        return ans;
    }
};