// Problem Link: https://leetcode.com/problems/fair-distribution-of-cookies/

// Space Complexity: O(N)
// Time Complexity: O(2 ^ N)

class Solution
{
private:
    void func(int idx, int n, vector<int> &cookies, vector<int> &groups, int &minRes, int k)
    {
        if (idx == n)
        {
            int maxVal = 0;
            for (auto &a : groups)
            {
                maxVal = max(maxVal, a);
            }
            minRes = min(minRes, maxVal);
            return;
        }
        for (int i = 0; i < k; i++)
        {
            groups[i] += (cookies[idx]);
            func(idx + 1, n, cookies, groups, minRes, k);
            groups[i] -= cookies[idx];
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> groups(k, 0);
        int minRes = 1e8;
        func(0, cookies.size(), cookies, groups, minRes, k);
        return minRes;
    }
};