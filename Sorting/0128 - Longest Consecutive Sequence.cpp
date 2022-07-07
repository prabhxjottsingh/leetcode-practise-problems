// Tags: Medium,
// Problem Link:https://leetcode.com/problems/longest-consecutive-sequence/
// Time Complexity: O(N * log N + N)
// Space Complexity: O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int count = 1, finalCount = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == nums[i - 1] + 1)
                count++;
            else
                count = 1;
            finalCount = max(count, finalCount);
        }
        finalCount = max(count, finalCount);
        return finalCount;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            freq[nums[i]]++;
        int count = 0;
        int finalCount = 0;
        int prev = -1e9;
        for (auto &a : freq)
        {
            if (prev == -1e9)
            {
                prev = a.first;
                count++;
            }
            else if (a.first - prev == 1)
            {
                count++;
                prev = a.first;
            }
            else
            {
                finalCount = max(count, finalCount);
                prev = a.first;
                count = 1;
            }
        }
        return max(count, finalCount);
    }
};