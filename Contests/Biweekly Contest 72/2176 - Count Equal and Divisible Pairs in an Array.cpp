// Problem Link: https://leetcode.com/contest/biweekly-contest-72/problems/count-equal-and-divisible-pairs-in-an-array/

// Time Complexity: O(n^2)

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((nums[i] == nums[j]) && ((i * j) % k == 0))
                    count++;
            }
        }
        return count;
    }
};