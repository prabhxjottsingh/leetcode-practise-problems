// Problem Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> freq;
        freq[0] = 1;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        map<int, int> freq;
        freq[0] = 1;
        int count = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            freq[rem]++;
        }
        for (auto &a : freq)
        {
            count += a.second * (a.second - 1) / 2;
        }
        return count;
    }
};