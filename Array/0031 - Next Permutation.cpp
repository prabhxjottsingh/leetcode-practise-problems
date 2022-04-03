// Problem Link: https://leetcode.com/problems/next-permutation/

// Time Complexity: O(N)
// Space Complexity: O(1) -> Constant

class Solution
{
private:
    void reverseTheOrder(vector<int> &v, int start, int end)
    {
        while (start < end)
        {
            swap(v[start], v[end]);
            start++;
            end--;
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int i, n = nums.size();
        for (i = n - 2; i > -1; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
        }
        if (i == -1)
        {
            reverseTheOrder(nums, 0, n - 1);
            return;
        }
        int j = i;
        int last = nums[i + 1], swapped = i + 1;
        for (j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i] && last >= nums[j])
            {
                swapped = j;
                last = nums[j];
            }
        }
        swap(nums[i], nums[swapped]);
        reverseTheOrder(nums, i + 1, n - 1);
    }
};