//Tags: Maths
//Difficulty: Medium
//Problem Link: https://leetcode.com/problems/reverse-integer/
//Time Complexity: O(n)

class Solution
{
public:
    int reverse(int x)
    {
        vector<long long int> v;
        bool flag = true;
        if (x < 0)
        {
            flag = false;
        }
        while (x)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        long long int ans = 0;
        for (auto a : v)
        {
            if (abs(ans * 10) >= INT_MAX)
                return 0;
            ans = ans * 10 + a;
        }
        if (flag)
            return ans;
        else
        {
            ans = ans - 0;
            return ans;
        }
    }
};