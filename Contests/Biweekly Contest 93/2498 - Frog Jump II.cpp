// Problem Link: https://leetcode.com/problems/frog-jump-ii/description/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int maxJump(vector<int> &stones)
    {
        int n = stones.size();
        int maxCost = max(0, abs(stones[n - 1] - stones[n - 2]));
        maxCost = max(maxCost, abs(stones[0] - stones[1]));
        for (int i = 2; i < n; i += 1)
        {
            maxCost = max(maxCost, abs(stones[i] - stones[i - 2]));
        }
        return maxCost;
    }
};