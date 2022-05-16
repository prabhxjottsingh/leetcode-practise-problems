// Problem Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int maxCount = 0;
        int n = candidates.size();
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if ((candidates[j] & (1 << i)) != 0)
                    count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};