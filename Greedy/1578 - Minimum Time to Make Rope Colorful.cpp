// Problem Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

// Time Complexity: O(N)
// Space Compelxtiy: O(1)

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        char prev = colors[0];
        int removeSum = 0;
        int maxTime = INT_MIN;
        int n = colors.size();
        for (int i = 1; i < n; i++)
        {
            if (prev == colors[i])
            {
                removeSum += neededTime[i - 1];
                maxTime = neededTime[i - 1];
                while (i < n && prev == colors[i])
                {
                    removeSum += neededTime[i];
                    maxTime = max(maxTime, neededTime[i]);
                    i += 1;
                }
                removeSum -= maxTime;
                if (i < n)
                    prev = colors[i];
            }
            else
                prev = colors[i];
        }
        return removeSum;
    }
};