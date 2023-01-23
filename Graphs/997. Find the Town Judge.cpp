// problem Link: https://leetcode.com/problems/find-the-town-judge/description/

// time Complexity: O(N)
// space Complexity: O(n)

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int peopleWhoTrust[n + 1];
        int peopleWhomTrust[n + 1];
        memset(peopleWhoTrust, 0, sizeof(peopleWhoTrust));
        memset(peopleWhomTrust, 0, sizeof(peopleWhomTrust));
        for (auto &a : trust)
            ++peopleWhoTrust[a[0]], ++peopleWhomTrust[a[1]];
        for (int i = 1; i <= n; i++)
        {
            if (peopleWhoTrust[i] == 0 && peopleWhomTrust[i] == n - 1)
                return i;
        }
        return -1;
    }
};