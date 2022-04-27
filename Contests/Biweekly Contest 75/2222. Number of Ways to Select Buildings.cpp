// Problem Link: https://leetcode.com/problems/number-of-ways-to-select-buildings/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    long long numberOfWays(string s)
    {
        int n = s.size();
        vector<int> one(n), zero(n);
        if (s[0] == '0')
        {
            zero[0] = 1;
            one[0] = 0;
        }
        else
        {
            zero[0] = 0;
            one[0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
                one[i] = one[i - 1] + 1;
            else
                one[i] = one[i - 1];
            if (s[i] == '0')
                zero[i] = zero[i - 1] + 1;
            else
                zero[i] = zero[i - 1];
        }
        long long int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                count += one[i] * (one[n - 1] - one[i]);
            }
            else
            {
                count += zero[i] * (zero[n - 1] - zero[i]);
            }
        }
        // for(auto &a:one)
        //     cout << a << " " ;
        // cout << endl;
        // for(auto &a:zero)
        //     cout << a << " " ;
        // cout << endl;
        return count;
    }
};