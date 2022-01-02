//Tags: String, Easy
//Problem Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
//Time Complexity: O(N)

class Solution
{
public:
    bool checkString(string s)
    {
        bool flag = true;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
                flag = false;
            if (s[i] == 'a')
            {
                if (flag == false)
                    return false;
            }
        }
        return true;
    }
};