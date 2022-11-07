//Problem link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

//Time Complexity: O(N ^ 2)
//Space Complexity: O(1)

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int maxi = -1001;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == -1 * nums[j])
                    maxi = max(maxi, nums[i]);
            }
        }
        return (maxi == -1001) ? -1 : maxi;
    }
};