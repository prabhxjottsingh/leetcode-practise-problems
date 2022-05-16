//Problem Link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int n = special.size();
        int maxCount = max(special[0] - bottom, top - special[n - 1]);
        for (int i = 0; i < n - 1; i++)
        {
            maxCount = max(maxCount, special[i + 1] - special[i] - 1);
        }
        return maxCount;
    }
};