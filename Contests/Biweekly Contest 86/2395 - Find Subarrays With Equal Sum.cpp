// Time Complexity: O(n ^ 2)
// Space Complexity: O(1)

class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            long long sum = nums[i] + nums[i + 1];
            for (int j = i + 1; j < n - 1; j++)
            {
                if (nums[j] + nums[j + 1] == sum)
                    return true'
            }
        }
        return false;
    }
};