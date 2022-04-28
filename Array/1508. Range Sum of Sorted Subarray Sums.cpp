// Problem Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Time Complexity: O(N ^ 2)
// Space Complexity: O(N)

class Solution
{
private:
    long long int mod = 1e9 + 7;

public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> helper;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = ((sum + nums[j]) % mod);
                helper.push_back(sum);
            }
        }
        int res = 0;
        left--;
        right--;
        sort(helper.begin(), helper.end());
        for (int i = left; i <= right; i++)
        {
            res = (res + helper[i]) % mod;
        }
        return res;
    }
};