// Problem Link: https://leetcode.com/problems/next-permutation/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
private:
    int binarySearch(int key, int low, int high, vector<int> &nums)
    {
        int resIdx = -1;
        for (int i = low; i <= high; i++)
        {
            if (nums[i] > key)
                resIdx = i;
        }
        return resIdx;
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int idx = -1;
        int n = nums.size();
        for (int i = n - 2; i > -1; i--)
        {
            if (nums[i + 1] > nums[i])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
            return;
        }
        int rightIdx = binarySearch(nums[idx], idx, n - 1, nums);
        swap(nums[idx], nums[rightIdx]);
        int left = idx + 1, right = n - 1;
        while (left <= right)
        {
            swap(nums[right], nums[left]);
            --right;
            ++left;
        }
    }
};