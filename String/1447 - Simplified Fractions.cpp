//Tag: Medium ,Strings
//Problem Link: https://leetcode.com/problems/simplified-fractions/
//Time Complexity: O(n^3)

class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                bool flag = true;
                if ((i % j == 0) && (j > 1))
                    flag = false;

                for (int k = 2; k < max(i, j); k++)
                {
                    if (i % k == 0 && j % k == 0)
                        flag = false;
                }

                if (flag)
                {
                    string ch1;
                    string ch2;
                    stringstream ss, ss2;
                    ss << i;
                    ss >> ch1;
                    ss2 << j;
                    ss2 >> ch2;
                    char ch3 = '/';
                    string s = ch2 + ch3 + ch1;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};