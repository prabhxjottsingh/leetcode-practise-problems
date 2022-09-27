// Problem Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// Time Complexity: O(N * log N)
// Space ComplexitY: O(1)

class Solution
{
private:
    const int mod = 1e9 + 7;

    int powFunc(int len)
    {
        if (len == 0)
            return 1;
        long long res = powFunc(len / 2) % mod;
        if (len & 1)
            return (((2 % mod) * (res % mod) * (res % mod)) % mod);
        return (((res % mod) * (res % mod)) % mod);
    }

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int countSubs = 0;
        while (start <= end)
        {
            if (nums[start] + nums[end] <= target)
            {
                int len = end - start;
                countSubs = ((countSubs % mod) + (powFunc(len) % mod)) % mod;
                start += 1;
            }
            else
                end -= 1;
        }
        return countSubs;
    }
};