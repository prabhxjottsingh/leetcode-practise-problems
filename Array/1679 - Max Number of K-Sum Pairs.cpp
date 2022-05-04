// Problem Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int n = nums.size();
        for (auto &a : nums)
            mp[a]++;
        int count = 0;
        for (auto &a : mp)
        {
            int reqNum = k - a.first;
            if (reqNum == a.first)
            {
                count += (a.second / 2);
            }
            else if (mp.count(reqNum))
            {
                count += min(mp[reqNum], a.second);
                a.second = 0;
            }
        }
        return count;
    }
};

// Time Complexity: O(log N * N)
// Space Complexity: O(1)

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        int count = 0;
        while (left < right)
        {
            int tempSum = nums[left] + nums[right];
            if (tempSum == k)
            {
                count++;
                left++;
                right--;
            }
            else if (tempSum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
    }
};