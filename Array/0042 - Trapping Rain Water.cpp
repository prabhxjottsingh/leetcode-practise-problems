/// Problem Link: https://leetcode.com/problems/trapping-rain-water/

// Time Complexity: O(N)
// Space Complexity: O(2 * N)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMax;
        vector<int> rightMax;
        int n = height.size();
        int lefiMaxi = 0;
        int rightMaxi = 0;
        for (int i = 0; i < n; i++)
        {
            lefiMaxi = max(lefiMaxi, height[i]);
            leftMax.push_back(lefiMaxi);
        }
        for (int i = n - 1; i > -1; i--)
        {
            rightMaxi = max(rightMaxi, height[i]);
            rightMax.push_back(rightMaxi);
        }
        reverse(rightMax.begin(), rightMax.end());
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            area += min(rightMax[i], leftMax[i]) - height[i];
        }
        return area;
    }
};