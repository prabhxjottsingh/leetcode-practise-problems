// Problem Link: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

// Space Complexity: O(n)
// Time Complexity:O(n log n)

class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        int n = nums.size();
        if ((n == 1) && (k % 2 != 0))
        {
            return -1;
        }
        if (k > n)
        {
            return *max_element(nums.begin(), nums.end());
        }
        for (int i = 0; i < k - 1; i++)
        {
            pq.push(nums[i]);
        }
        if (k < n)
        {
            pq.push(nums[k]);
        }
        return pq.top();
    }
};