//Problem Link: https://leetcode.com/problems/jump-game/description/

// Time Complexity: O(N)
// Space Complexiy: O(1)

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int currPos = 0;
        int maxJump = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxJump = max(maxJump, nums[i] + i);
            if (maxJump >= n - 1)
                return true;
            if (maxJump <= i)
                return false;
            if (currPos == i)
            {
                currPos = maxJump;
            }
        }
        return false;
    }
};