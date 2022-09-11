// Problem Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

// Time Complexity: O(N)
// space Complexity: O(1e6)

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> freq(1e6 + 3, 0);
        int start = 1e9;
        int end = -1e9;
        int maxCount = 0;
        for (auto &a : intervals)
        {
            freq[a[0]] += 1;
            freq[a[1] + 1] -= 1;
            start = min(start, a[0]);
            end = max(end, a[1]);
        }
        int presCount = 0;
        for (int i = start; i <= end; i++)
        {
            presCount += freq[i];
            maxCount = max(maxCount, presCount);
        }
        return maxCount;
    }
};