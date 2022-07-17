//Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
//space Complexity: O(N)
//Time Compelxity: O(N * log N + M * log M)

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int gcd = numsDivide[0];
        for (auto &a : numsDivide)
            gcd = __gcd(a, gcd);
        sort(nums.begin(), nums.end());
        int count = 0;
        for (auto &a : nums)
        {
            if (gcd % a == 0 && a <= gcd)
                break;
            count++;
        }
        if (count == nums.size())
            return -1;
        return count;
    }
};