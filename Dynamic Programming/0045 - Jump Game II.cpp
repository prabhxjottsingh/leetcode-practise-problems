// Problem Link: https://leetcode.com/problems/jump-game-ii/description/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxJumps = 0;
        int prevMaxJumpsIdx = 0;
        int steps = 1;
        int n = nums.size();
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++)
        {
            maxJumps = max(maxJumps, nums[i] + i);
            if (maxJumps >= n - 1)
                return steps;
            if (maxJumps <= i)
                return -1;
            if (i == prevMaxJumpsIdx)
            {
                steps += 1;
                prevMaxJumpsIdx = maxJumps;
            }
        }
        return steps;
    }
};