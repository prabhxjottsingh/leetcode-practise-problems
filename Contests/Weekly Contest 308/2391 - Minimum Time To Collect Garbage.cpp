// Problem Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/discuss

// Time Complexity: O(N * M)
// Space Complexity: O(N)

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        long long int metalTime = 0, paperTime = 0, glassTime = 0;
        long long countTime = garbage[0].size();
        int n = garbage.size();
        vector<long long> sum;
        for (auto &a : travel)
        {
            if (sum.empty())
                sum.push_back(a);
            else
                sum.push_back(a + sum.back());
        }
        for (int i = 1; i < n; i++)
        {
            for (auto &a : garbage[i])
            {
                if (a == 'M')
                    metalTime = sum[i - 1];
                if (a == 'P')
                    paperTime = sum[i - 1];
                if (a == 'G')
                    glassTime = sum[i - 1];
                countTime += 1;
            }
        }
        int prev = 0;
        countTime += metalTime;
        countTime += paperTime;
        countTime += glassTime;
        return countTime;
    }
};